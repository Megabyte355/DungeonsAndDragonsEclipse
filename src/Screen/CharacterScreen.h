/*
 * CharacterScreen.h
 *
 *  Created on: Nov 8, 2013
 *      Author: Gary
 */

#ifndef CHARACTERSCREEN_H_
#define CHARACTERSCREEN_H_

#include "GameConfig.h"
#include "Screen.h"
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include <iostream>
#include <SDL.h>

class CharacterScreen : public virtual Screen
{
    public:
        CharacterScreen();
        ~CharacterScreen();

        void initialize() override;
        void update(float) override;
        void draw() override;
        void handleEvents(SDL_Event * event) override;

    private:
        TextureRenderer * textures;
        TextRenderer * texts;

        std::string textInput;
};

#endif /* CHARACTERSCREEN_H_ */
