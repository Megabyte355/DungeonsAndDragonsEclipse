/*
 * Screen.h
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <string>

//#include "Game.h"

// Forward class declaration
class Game;
union SDL_Event;

class Screen
{
    private:
        std::string uniqueName;
    public:
        Screen(std::string name);
        virtual ~Screen(void);

        virtual std::string getName();
        virtual void initialize() = 0;
        virtual void update(float) = 0;
        virtual void draw() = 0;
        virtual void handleEvents(SDL_Event * event) = 0;

};

#endif /* SCREEN_H_ */
