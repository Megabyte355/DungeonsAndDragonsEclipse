/*
 * OptionLabel.cpp
 *
 *  Created on: Nov 9, 2013
 *      Author: Gary
 */

#include "OptionLabel.h"

OptionLabel::OptionLabel(int x, int y, int w, int h, std::string label) :
        Clickable(x, y, w, h)
{
    visible = false;
    hover = false;
    this->label = label;
    functionPointer = nullptr;
}

OptionLabel::~OptionLabel()
{
    visible = false;
    hover = false;
    functionPointer = nullptr;
}

void OptionLabel::draw()
{
    TextRenderer::getInstance()->renderText(x, y, label, "arial", TextRenderer::white, 20);
    if(hover)
    {
        TextureRenderer::getInstance()->drawLine(x, y, x + width, y);
        TextureRenderer::getInstance()->drawLine(x + width, y, x + width, y + height);
        TextureRenderer::getInstance()->drawLine(x + width, y + height, x, y + height);
        TextureRenderer::getInstance()->drawLine(x, y + height, x, y);
    }
}

void OptionLabel::handleEvents(SDL_Event& event)
{
    if (visible)
    {
        int buttonX = event.button.x;
        int buttonY = event.button.y;
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (buttonX > x && buttonX < x + width && buttonY > y && buttonY < y + height)
            {
                if (functionPointer != nullptr)
                {
                    std::cout << "Function Pointer Clicked" << std::endl;
                    functionPointer();
                }
            }
        }
        if (event.type == SDL_MOUSEMOTION)
        {
            if (buttonX > x && buttonX < x + width && buttonY > y && buttonY < y + height)
            {
                hover = true;
            }
            else
            {
                hover = false;
            }
        }
    }
}

void OptionLabel::toggleVisibility()
{
    visible = !visible;
}

void OptionLabel::setFunction(std::function<void()> funct)
{
    functionPointer = funct;
}

bool OptionLabel::getVisibility()
{
    return visible;
}
