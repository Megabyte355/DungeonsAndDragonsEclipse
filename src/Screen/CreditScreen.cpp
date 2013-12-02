/*
 * CreditScreen.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: Tim
 */

#include "CreditScreen.h"

CreditScreen::CreditScreen() :
        Screen("CreditScreen")
{
}

CreditScreen::~CreditScreen()
{
    reset();
}

void CreditScreen::initialize()
{
    active = true;

    audio->playMusic(2);
    MenuOption * opt;
    opt = new MenuOption(350, 500, 25, "Back");
    opt->setVisibility(true);
    opt->setCallback(std::bind(&CreditScreen::goBack, this));
    menuOptions.push_back(opt);
    opt = nullptr;
}

void CreditScreen::reset()
{
    for (auto o : menuOptions)
    {
        delete o;
    }
    menuOptions.clear();
}

void CreditScreen::update(float deltaTime)
{
}

void CreditScreen::draw()
{
    TextureRenderer * textures = TextureRenderer::getInstance();
    TextRenderer * texts = TextRenderer::getInstance();

    textures->drawTexture("menu_screen", 0, 0, GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT);
    textures->drawTexture("gary", 140, 150, 30, 38);
    textures->drawTexture("tiff", 473, 152, 30, 38);
    textures->drawTexture("tim", 465, 350, 33, 40);
    textures->drawTexture("kev", 140, 350, 30, 37);
    texts->setSettings("retganon", 45, TextRenderer::white, TextRenderer::blue);
    texts->renderTextWithShadow(229, 39, "Credits");

    texts->renderTextWithShadow(175, 190, "Graphics");
    texts->renderTextWithShadow(175, 225, "Map");

    texts->renderTextWithShadow(500, 190, "Character");
    texts->renderTextWithShadow(500, 225, "GUI");

    texts->renderTextWithShadow(175, 390, "Inventory");
    texts->renderTextWithShadow(175, 425, "Equipment");

    texts->renderTextWithShadow(500, 390, "Audio");
    texts->renderTextWithShadow(500, 425, "Combat");

    texts->setSettings("triforce", 45, TextRenderer::white, TextRenderer::blue);
    texts->renderTextWithShadow(175, 150, "Gary");
    texts->renderTextWithShadow(175, 350, "Kevin");
    texts->renderTextWithShadow(500, 150, "Tiffany");
    texts->renderTextWithShadow(500, 350, "Tim");

    texts->setSettings("retganon", 40, TextRenderer::white, TextRenderer::blue);
    for (auto option : menuOptions)
    {
        option->draw();
    }

    textures = nullptr;
    texts = nullptr;
}

void CreditScreen::handleEvents(SDL_Event& event)
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

void CreditScreen::goBack()
{
    ScreenManager::requestScreenChange(getScreenName(), "MainMenuScreen");
}
