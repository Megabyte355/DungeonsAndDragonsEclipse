/*
 * Button.cpp
 *
 *  Created on: Nov 9, 2013
 *      Author: Gary
 */

#include "Button.h"
#include "AudioManager.h"


// Constructor takes location of button, padding and a string to display.
// The size of the button is automatically calculated.
Button::Button(int x, int y, int padding, std::string label) :
        Clickable(x, y)
{
    this->label = label;

    labelBoundary = SDL_Rect(TextRenderer::getInstance()->queryTextSize(x + padding, y + padding, label));

    boundary.w = 2 * padding + labelBoundary.w;
    boundary.h = 2 * padding + labelBoundary.h;


}

// Padding is not used. The label is centered in the button.
Button::Button(int x, int y, int w, int h, std::string label) :
        Clickable(x, y, w, h)
{
    this->label = label;

    labelBoundary = SDL_Rect(TextRenderer::getInstance()->queryTextSize(x, y, label));
    labelBoundary.x = x + (w - labelBoundary.w) / 2;
    labelBoundary.y = y + (h - labelBoundary.h) / 2;
}

Button::~Button()
{
}

void Button::update()
{
}

void Button::draw()
{
    if (visible)
    {
        TextRenderer * texts = TextRenderer::getInstance();
        if (clicked)
        {
            TextureRenderer::getInstance()->drawTexture("red_button_down", boundary.x, boundary.y, boundary.w,
                    boundary.h);
        }
        else
        {
            if (hover)
            {
                TextureRenderer::getInstance()->drawTexture("red_button_hover", boundary.x, boundary.y, boundary.w,
                        boundary.h);
            }
            else
            {
                TextureRenderer::getInstance()->drawTexture("red_button_normal", boundary.x, boundary.y, boundary.w,
                        boundary.h);
            }
        }
        texts->renderText(labelBoundary.x, labelBoundary.y, label);
        texts = nullptr;
    }
}

void Button::handleEvents(SDL_Event &event)
{

    audio = AudioManager::getInstance();
    if (visible)
    {
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            clicked = intersect(event.button.x, event.button.y);
        }
        else if (event.type == SDL_MOUSEMOTION)
        {
            hover = intersect(event.button.x, event.button.y);
            if(hover)
            	isHover++;
            else
            	isHover=0;

            if(isHover==1)
            	audio->playSound(1);
        }
        else if (event.type == SDL_MOUSEBUTTONUP)
        {
            if (clicked && callback != nullptr && intersect(event.button.x, event.button.y))
            {
            	audio->playSound(2);
                callback();
            }
            clicked = false;
        }
    }
}
