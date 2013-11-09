/*
 * CharacterScreen.cpp
 *
 *  Created on: Nov 8, 2013
 *      Author: Gary
 */

#include "CharacterScreen.h"

CharacterScreen::CharacterScreen() :
        Screen("CharacterScreen")
{
    initialize();
}

CharacterScreen::~CharacterScreen()
{
    textures = nullptr;
    texts = nullptr;
}

void CharacterScreen::initialize()
{
    active = true;
    textures = TextureRenderer::getInstance();
    texts = TextRenderer::getInstance();
}

void CharacterScreen::update(float)
{
}

void CharacterScreen::draw()
{
}

void CharacterScreen::handleEvents(SDL_Event * event)
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
