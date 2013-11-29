/*
 * TextField.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: Gary
 */

#include "TextField.h"

TextField * TextField::focusedTextField = nullptr;
bool TextField::currentInputState = false;
bool TextField::previousInputState = false;

TextField::TextField(int x, int y, int w, int h) :
        Clickable(x, y, w, h)
{
    hover = false;
    focus = false;
}

TextField::~TextField()
{
    focusedTextField = nullptr;
    hover = false;
    focus = false;
}

void TextField::update()
{
    if(focusedTextField != nullptr)
    {
        // Manually set nullptr if there are no focused textfields
        if (!focusedTextField->isFocused())
        {
            focusedTextField = nullptr;
        }

        // Input state management to prevent starting/stopping text input continuously
        if (focus)
        {
            focusedTextField = this;
        }

        currentInputState = (focusedTextField == nullptr) ? false : true;

        if (currentInputState != previousInputState)
        {
            if (currentInputState)
            {
                SDL_StartTextInput();
            }
            else
            {
                SDL_StopTextInput();
            }
            previousInputState = currentInputState;
        }
    }
    
}

void TextField::handleEvents(SDL_Event &event)
{
    switch (event.type)
    {
        case SDL_QUIT:
            GameConfig::getInstance()->gameIsRunning = false;
            break;
        case SDL_TEXTINPUT:
            if (isFocused())
            {
                text += event.text.text;
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

void TextField::draw()
{
    TextureRenderer * ren = TextureRenderer::getInstance();
    //ren->drawTexture("empty", boundary.x, boundary.y, boundary.w, boundary.h);
    ren->drawLine(boundary.x, boundary.y, boundary.x + boundary.w, boundary.y);
    ren->drawLine(boundary.x + boundary.w, boundary.y, boundary.x + boundary.w, boundary.y + boundary.h);
    ren->drawLine(boundary.x, boundary.y + boundary.h, boundary.x + boundary.w, boundary.y + boundary.h);
    ren->drawLine(boundary.x, boundary.y, boundary.x, boundary.y + boundary.h);
    ren = nullptr;
    TextRenderer::getInstance()->renderText(5 + boundary.x, 5 + boundary.y, text);
}

bool TextField::isFocused()
{
    return focus;
}

std::string TextField::getText()
{
    return text;
}
