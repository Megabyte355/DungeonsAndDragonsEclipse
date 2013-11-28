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
}

void MainMenuScreen::initialize()
{
    active = true;
}

void MainMenuScreen::reset()
{
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
            std::cout << "Moving at : (" << event.motion.x << ", " << event.motion.y << ")" << std::endl;
            break;
        default:
            break;
    }
}


