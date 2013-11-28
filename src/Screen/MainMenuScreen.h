/*
 * MainMenuScreen.h
 *
 *  Created on: Nov 28, 2013
 *      Author: Gary
 */

#ifndef MAINMENUSCREEN_H_
#define MAINMENUSCREEN_H_

#include "Screen.h"
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include "GameConfig.h"

class MainMenuScreen: public virtual Screen
{
    public:
        MainMenuScreen();
        virtual ~MainMenuScreen();

        void initialize() override;
        void update(float) override;
        void draw() override;
        void handleEvents(SDL_Event &event) override;
        void reset() override;
};

#endif /* MAINMENUSCREEN_H_ */
