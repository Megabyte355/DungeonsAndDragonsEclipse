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
    public:
        Screen(std::string name);
        virtual ~Screen(void);

        bool active;
        bool paused;
        int getInstanceId();
        virtual std::string getName();
        virtual void initialize() = 0;
        virtual void update(float) = 0;
        virtual void draw() = 0;
        virtual void handleEvents(SDL_Event * event) = 0;
        virtual void reset() = 0;

    private:
        std::string uniqueName;
        int instanceId;

    protected:
        static int instanceIdCounter;
};

#endif /* SCREEN_H_ */
