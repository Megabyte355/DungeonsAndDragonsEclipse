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
    TextRenderer::getInstance()->renderText(50, 50, "Under construction", "arial", TextRenderer::white, 20);
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
            break;

        case SDL_MOUSEBUTTONUP:
            break;

        case SDL_MOUSEMOTION:
            break;
        default:
            break;
    }
}

void CharacterScreen::reset()
{

}
