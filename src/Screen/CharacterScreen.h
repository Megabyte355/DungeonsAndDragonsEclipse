/*
 * CharacterScreen.h
 *
 *  Created on: Nov 8, 2013
 *      Author: Gary
 */

#ifndef CHARACTERSCREEN_H_
#define CHARACTERSCREEN_H_

#include "GameConfig.h"
#include "ScreenManager.h"
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include "Button.h"
#include "CharacterDriver.h"
#include "FileIO.h"

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
        void handleEvents(SDL_Event &event) override;
        void reset() override;

        // Function pointers
        static void returnToMenu();
        static void beginCharacterCreation();
    private:
        TextureRenderer * textures;
        TextRenderer * texts;
        std::string textInput;
        std::vector<Button*> options;
        static bool characterCreation;
};

#endif /* CHARACTERSCREEN_H_ */
