/*
 * CharacterScreen.cpp
 *
 *  Created on: Nov 8, 2013
 *      Author: Gary
 */

#include "CharacterScreen.h"

bool CharacterScreen::characterCreation = false;

CharacterScreen::CharacterScreen() :
        Screen("CharacterScreen")
{
    initialize();
}

CharacterScreen::~CharacterScreen()
{
    reset();
}

void CharacterScreen::initialize()
{
    active = true;
    textures = TextureRenderer::getInstance();
    texts = TextRenderer::getInstance();

    Button * option = new Button(700, 0, 15, "Back");
    option->setOnClick(returnToMenu);
    options.push_back(option);
    option->toggleVisibility();

    option = new Button(300, 250, 15, "Begin Character Creation");
    option->setOnClick(beginCharacterCreation);
    options.push_back(option);
    option->toggleVisibility();

    option = nullptr;
}

void CharacterScreen::update(float deltaTime)
{
    if (characterCreation)
    {
        std::cout << "Entering Character Creator..." << std::endl;

        CharacterDriver * creator = new CharacterDriver();
        creator->runProgram();

        Fighter * f = (creator->returnFighter());


        std::cout << "Do you want to save the Fighter in a file?" << std::endl;
        std::cout << "(Enter 1 to say Yes)" << std::endl;
        std::cout << "Answer: ";

        int choice = 0;
        std::cin >> choice;
        if(choice == 1)
        {
            FileIO writer("Fighter_", ".txt");
            writer.save(1, f->toFileString());
            std::cout << "File saved." << std::endl;
        }
        else
        {
            std::cout << "Fighter is being discarded." << std::endl;
        }

        characterCreation = false;
        delete creator;
        delete f;
        creator = nullptr;
        f = nullptr;
    }
}

void CharacterScreen::draw()
{
    textures->drawTexture("background", 0, 0, GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT);
    texts->renderText(25, 25, "Character Editor", "arial", TextRenderer::white, 35);
    texts->renderText(25, 65, "(under construction)", "arial", TextRenderer::white, 20);

    for (auto o : options)
    {
        if (o->isVisible())
        {
            o->draw();
        }
    }

    if (characterCreation)
    {
        texts->renderText(75, 450, "The console is demanding your attention!!!", "arial", TextRenderer::white, 35);
    }
}

void CharacterScreen::handleEvents(SDL_Event * event)
{
    switch (event->type)
    {
        case SDL_QUIT:
            GameConfig::getInstance()->gameIsRunning = false;
            break;
        case SDL_KEYDOWN:
            if (event->key.keysym.sym == SDLK_ESCAPE)
            {
                active = false;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            for (auto o : options)
            {
                o->handleEvents(*event);
            }
            break;
        case SDL_MOUSEMOTION:
            for (auto o : options)
            {
                o->handleEvents(*event);
            }
            break;
        default:
            break;
    }
}

void CharacterScreen::reset()
{
    textures = nullptr;
    texts = nullptr;
    for (auto o : options)
    {
        delete o;
    }
    options.clear();
}

void CharacterScreen::returnToMenu()
{
    ScreenManager::requestScreenChange("CharacterScreen", "MenuScreen");
}

void CharacterScreen::beginCharacterCreation()
{
    characterCreation = true;
}
