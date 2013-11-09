/*
 * MenuScreen.h
 *
 *  Created on: Nov 7, 2013
 *      Author: Gary
 */

#ifndef MENUSCREEN_H_
#define MENUSCREEN_H_

#include "GameConfig.h"
#include "ScreenManager.h"
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include "OptionLabel.h"
#include <iostream>
#include <SDL.h>

class MenuScreen: public virtual Screen
{
    public:
        MenuScreen();
        ~MenuScreen();

        void initialize() override;
        void update(float) override;
        void draw() override;
        void handleEvents(SDL_Event * event) override;
        void reset() override;

        // Functions passed to buttons
        static void goToCharacterScreen();
        static void goToMapScreen();

    private:
        TextureRenderer * textures;
        TextRenderer * texts;

        bool pressAnyKeyToggleOverTime;
        bool pressAnyKeyDisplay;
        float displayDelay;
        float currentTime;

        std::vector<OptionLabel*> menuOptions;
        bool showMenu;

};

#endif /* MENUSCREEN_H_ */
