/*
 * MenuScreen.cpp
 *
 *  Created on: Nov 7, 2013
 *      Author: Gary
 */

#include "MenuScreen.h"

MenuScreen::MenuScreen() :
        Screen("MenuScreen")
{
    initialize();
}

MenuScreen::~MenuScreen()
{
    // MenuScreen is not responsible for destroying renderers
    textures = nullptr;
    texts = nullptr;
}

void MenuScreen::initialize()
{
    active = true;
    textures = TextureRenderer::getInstance();
    texts = TextRenderer::getInstance();

    pressAnyKeyDisplay = false;
    displayDelay = 500;
    currentTime = 0;
}

void MenuScreen::update(float deltaTime)
{
    currentTime += deltaTime;
    if (currentTime > displayDelay)
    {
        pressAnyKeyDisplay = !pressAnyKeyDisplay;
        currentTime = 0;
    }
}

void MenuScreen::draw()
{
    textures->drawTexture("bizzare_landscape", 0, 0, GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT);
    textures->drawTexture("ddlogo", 95, -100, 600, 450);
    //400 x 300
    texts->renderText(252, 227, "Mini Edition", "starcraft_font", TextRenderer::black, 40);
    texts->renderText(250, 225, "Mini Edition", "starcraft_font", TextRenderer::red, 40);

    if (pressAnyKeyDisplay)
    {
        texts->renderText(325, 325, "Press any key", "calibri", TextRenderer::white, 30);
    }

    texts->renderText(50, 450, "Gary Chang", "calibri", TextRenderer::white, 22);
    texts->renderText(50, 480, "Tiffany Ip", "calibri", TextRenderer::white, 22);
    texts->renderText(50, 510, "Kevin Silva", "calibri", TextRenderer::white, 22);
    texts->renderText(50, 540, "Tim Smith", "calibri", TextRenderer::white, 22);

    texts->renderText(GameConfig::SCREEN_WIDTH - 200, GameConfig::SCREEN_HEIGHT - 50, "Not a real product", "calibri",
            TextRenderer::white, 20);

}

void MenuScreen::handleEvents(SDL_Event* event)
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
                //ScreenManager::requestScreenChange("TestScreen");
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            active = false;
            break;
        default:
            break;
    }
}

void MenuScreen::reset()
{

}
