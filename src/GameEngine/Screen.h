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

        virtual std::string GetName();
        virtual void Instance() = 0;
        virtual void Initialize() = 0;
        virtual void Update(float) = 0;
        virtual void Draw() = 0;
        virtual void HandleEvents(SDL_Event * event) = 0;

};

#endif /* SCREEN_H_ */
