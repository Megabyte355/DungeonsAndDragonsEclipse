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

        case SDL_TEXTINPUT():
            //std::strcat(textInput, event.text.text);
            break;

        case SDL_TEXTEDITING():
            break;

    }
}
