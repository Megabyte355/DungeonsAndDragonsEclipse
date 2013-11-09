/*
 * OptionLabel.h
 *
 *  Created on: Nov 9, 2013
 *      Author: Gary
 */

#ifndef OPTIONLABEL_H_
#define OPTIONLABEL_H_

#include "Clickable.h"
#include "TextRenderer.h"
#include <SDL.h>
#include <string>
#include <functional>

class OptionLabel : public virtual Clickable
{
    public:
        OptionLabel(int,int,int,int,std::string);
        ~OptionLabel();

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

#endif /* OPTIONLABEL_H_ */
