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
}

void MenuScreen::update(float deltaTime)
{

}

void MenuScreen::draw()
{
    SDL_Rect dest;

    dest.x = 0;
    dest.y = 0;
    dest.w = GameConfig::SCREEN_WIDTH;
    dest.h = GameConfig::SCREEN_HEIGHT;

    textures->drawTexture("outer_space", dest.x, dest.y, dest.w, dest.h);

}

void MenuScreen::handleEvents(SDL_Event* event)
{
    switch (event->type)
    {
        case SDL_QUIT:
            GameConfig::getInstance()->gameIsRunning = false;
            break;
        case SDL_KEYDOWN:

            //std::cout << "Key pressed: " << event->key.keysym.sym << endl;
            if (event->key.keysym.sym == SDLK_ESCAPE)
            {
                //GameConfig::getInstance()->gameIsRunning = false;
                active = false;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            std::cout << "Left click? " << (event->button.button == SDL_BUTTON_LEFT) << std::endl;
            std::cout << "Right click? " << (event->button.button == SDL_BUTTON_RIGHT) << std::endl;
            std::cout << "Click at : (" << event->button.x << ", " << event->button.y << ")" << std::endl;
            break;

        case SDL_MOUSEBUTTONUP:
            std::cout << "Left up? " << (event->button.button == SDL_BUTTON_LEFT) << std::endl;
            std::cout << "Right up? " << (event->button.button == SDL_BUTTON_RIGHT) << std::endl;
            std::cout << "Click at : (" << event->button.x << ", " << event->button.y << ")" << std::endl;
            break;

        case SDL_MOUSEMOTION:
            std::cout << "Moving at : (" << event->motion.x << ", " << event->motion.y << ")" << std::endl;
            break;
        default:
            break;
    }
}
