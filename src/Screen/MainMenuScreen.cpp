/*
 * MainMenuScreen.cpp
 *
 *  Created on: Nov 28, 2013
 *      Author: Gary
 */

#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen() :
        Screen("MainMenuScreen")
{
}

MainMenuScreen::~MainMenuScreen()
{
    reset();
}

void MainMenuScreen::initialize()
{
    active = true;

    audio->playMusic(2);
    MenuOption * opt;
    opt = new MenuOption(300, 150, 25, "New Game");
    opt->setVisibility(true);
    opt->setCallback(std::bind(&MainMenuScreen::goToNewGameScreen, this));
    menuOptions.push_back(opt);
    opt = new MenuOption(300, 250, 25, "Load Game");
    opt->setVisibility(true);
    opt->setCallback(std::bind(&MainMenuScreen::goToLoadGameScreen, this));
    menuOptions.push_back(opt);
    opt = new MenuOption(300, 350, 25, "Editors");
    opt->setVisibility(true);
    opt->setCallback(std::bind(&MainMenuScreen::goToEditorMenuScreen, this));
    menuOptions.push_back(opt);
    opt = new MenuOption(300, 450, 25, "Credits");
    opt->setVisibility(true);
    opt->setCallback(std::bind(&MainMenuScreen::goToCreditScreen, this));
    menuOptions.push_back(opt);
    opt = nullptr;
}

void MainMenuScreen::reset()
{
    for (auto o : menuOptions)
    {
        delete o;
    }
    menuOptions.clear();
}

void MainMenuScreen::update(float deltaTime)
{
}

void MainMenuScreen::draw()
{
    TextureRenderer * textures = TextureRenderer::getInstance();
    TextRenderer * texts = TextRenderer::getInstance();

    textures->drawTexture("menu_screen", 0, 0, GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT);

    texts->setSettings("retganon", 45, TextRenderer::white, TextRenderer::blue);
    texts->renderTextWithShadow(229, 39, "MAIN MENU");

    texts->setSettings("retganon", 40, TextRenderer::white, TextRenderer::blue);
    for (auto option : menuOptions)
    {
        option->draw();
    }

    textures = nullptr;
    texts = nullptr;
}

void MainMenuScreen::handleEvents(SDL_Event& event)
{
    switch (event.type)
    {
        case SDL_QUIT:
            GameConfig::getInstance()->gameIsRunning = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                active = false;
            }
            break;
        case SDL_MOUSEBUTTONUP:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEMOTION:
            // TODO Testing code to be removed
            //std::cout << "Moving at : (" << event.motion.x << ", " << event.motion.y << ")" << std::endl;
            for (auto option : menuOptions)
            {
                option->handleEvents(event);
            }
            break;
        default:
            break;
    }
}

void MainMenuScreen::goToNewGameScreen()
{
    // TODO When new screen is complete, fix this
//    ScreenManager::requestScreenChange("", "");

    // TEST CODE
    Fighter* f = new Fighter();
    f->levelUp();
    f->levelUp();

    map<characterStats, int> testMap = f->inventory.getInventoryStats();
    for (auto it = testMap.begin(); it != testMap.end(); it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    Moblin * m = new Moblin(5);
    Combat c;
    c.combatRound(f, m);
}

void MainMenuScreen::goToLoadGameScreen()
{
    // TODO When new screen is complete, fix this
//    ScreenManager::requestScreenChange("", "");
    std::cout << "Load Game" << std::endl;
}

void MainMenuScreen::goToEditorMenuScreen()
{
    ScreenManager::requestScreenChange("MainMenuScreen", "EditorMenuScreen");
}

void MainMenuScreen::goToCreditScreen()
{
    // TODO When new screen is complete, fix this
//    ScreenManager::requestScreenChange("", "");
    ScreenManager::requestScreenChange("MainMenuScreen", "CreditScreen");
    std::cout << "Credits" << std::endl;
}
