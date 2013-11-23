/*
 * TitleScreen.h
 *
 *  Created on: Nov 23, 2013
 *      Author: Gary
 */

#ifndef TITLESCREEN_H_
#define TITLESCREEN_H_

#include "Screen.h"
#include "TextureRenderer.h"
#include "GameConfig.h"
#include "ScreenManager.h"
#include <SDL.h>

class TitleScreen: public virtual Screen
{
    public:
        TitleScreen();
        virtual ~TitleScreen();

        virtual void initialize();
        virtual void reset();
        virtual void update(float);
        virtual void draw();
        virtual void handleEvents(SDL_Event &event);

        void goToMenuScreen();

    private:
        float currentFlickerTime;
        bool flickeringTextState;

        const float flickeringDelay = 500;
        const std::string flickeringText = "Press any key";
};

#endif /* TITLESCREEN_H_ */
