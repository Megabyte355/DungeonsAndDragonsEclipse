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
#include "ScreenManager.h"
#include <vector>

class MainMenuScreen: public virtual Screen
{
    public:
        MainMenuScreen();
        virtual ~MainMenuScreen();

        void initialize() override;
        void reset() override;
        void update(float) override;
        void draw() override;
        void handleEvents(SDL_Event &event) override;

        // Menu options
        std::vector<MenuOption*> menuOptions;

    private:
        void goToNewGameScreen();
        void goToLoadGameScreen();
        void goToEditorMenuScreen();
        void goToCreditScreen();
};

#endif /* MAINMENUSCREEN_H_ */
