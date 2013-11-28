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
#include "MenuOption.h"
#include <vector>

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

        // Functions passed to MenuOptions
        std::vector<MenuOption*> menuOptions;

};

#endif /* MAINMENUSCREEN_H_ */
