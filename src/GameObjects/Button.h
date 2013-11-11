/*
 * Button.h
 *
 *  Created on: Nov 9, 2013
 *      Author: Gary
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "Clickable.h"
#include "TextRenderer.h"
#include <SDL.h>
#include <string>
#include <functional>

class Button : public virtual Clickable
{
    public:
        Button(int,int,int,int,std::string);
        ~Button();

        void draw();
        void handleEvents(SDL_Event &);
        void setFunction(std::function<void()>);
        void toggleVisibility();
        bool getVisibility();

    private:
        std::string label;
        bool visible;
        bool hover;
        SDL_Rect boundary;
        std::function<void()> functionPointer;
};

#endif /* BUTTON_H_ */
