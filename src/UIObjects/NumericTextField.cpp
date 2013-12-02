/*
 * NumericTextField.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: Gary
 */

#include "NumericTextField.h"

NumericTextField::NumericTextField(int x, int y, int w, int h, int maxLength) :
        Clickable(x, y, w, h), TextField(x, y, w, h)
{
    this->maxLength = maxLength;
}

NumericTextField::~NumericTextField()
{
}

void NumericTextField::handleEvents(SDL_Event &event)
{
    switch (event.type)
    {
        case SDL_QUIT:
            GameConfig::getInstance()->gameIsRunning = false;
            break;
        case SDL_TEXTINPUT:
            if (isFocused())
            {
                char * c = event.text.text;
                switch (*c)
                {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        if(text.length() < maxLength)
                        {
                            text += event.text.text;
                        }
                        break;
                    default:
                        break;
                }
                c = nullptr;
            }
            break;
        case SDL_KEYDOWN:
            // Handle backspace
            if (isFocused() && text.length() > 0 && event.key.keysym.sym == SDLK_BACKSPACE)
            {
                text.pop_back();
            }
            else if (event.key.keysym.sym == SDLK_RETURN)
            {
                focus = false;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            focus = intersect(event.button.x, event.button.y);
            break;
        case SDL_MOUSEMOTION:
            hover = intersect(event.motion.x, event.motion.y);
            break;
        default:
            break;
    }
}
