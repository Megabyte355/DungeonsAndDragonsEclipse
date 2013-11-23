/*
 * TitleScreen.h
 *
 *  Created on: Nov 23, 2013
 *      Author: Gary
 */

#ifndef TITLESCREEN_H_
#define TITLESCREEN_H_

#include <SDL.h>
#include "Screen.h"

class TitleScreen : public virtual Screen
{
    public:
        TitleScreen();
        virtual ~TitleScreen();

        virtual void initialize() = 0;
        virtual void update(float) = 0;
        virtual void draw() = 0;
        virtual void handleEvents(SDL_Event &event) = 0;
        virtual void reset() = 0;
};

#endif /* TITLESCREEN_H_ */
