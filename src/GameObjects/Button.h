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
        Button(int x,int y,int padding ,std::string label);
        ~Button();

        void draw();
        void handleEvents(SDL_Event &);
        void setOnClick(std::function<void()>);
        void toggleVisibility();
        bool isVisible();

    private:
        int padding;
        std::string label;
        bool visible;
        bool hover;
        SDL_Rect boundary;
        std::function<void()> onClick;
};

#endif /* BUTTON_H_ */
