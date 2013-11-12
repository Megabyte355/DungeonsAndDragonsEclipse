/*
 * Button.cpp
 *
 *  Created on: Nov 9, 2013
 *      Author: Gary
 */

#include "Button.h"

Button::Button(int x, int y, int padding, std::string label) :
        Clickable(x, y)
{
    this->padding = padding;
    visible = false;
    hover = false;
    this->label = label;
    onClick = nullptr;
}

Button::~Button()
{
    visible = false;
    hover = false;
    onClick = nullptr;
}

void Button::draw()
{
    TextRenderer * r = TextRenderer::getInstance();
    r->setSettings("arial", 20, TextRenderer::white);
    r->renderText(x, y, label);
    if (hover)
    {
        TextureRenderer * ren = TextureRenderer::getInstance();
        SDL_Rect pos(r->queryTextSize(x, y, label));

        ren->drawLine(x - padding, y - padding, x + pos.w + padding, y - padding);
        ren->drawLine(x + pos.w + padding, y - padding, x + pos.w + padding, y + pos.h + padding);
        ren->drawLine(x + pos.w + padding, y + pos.h + padding, x - padding, y + pos.h + padding);
        ren->drawLine(x - padding, y + pos.h + padding, x - padding, y - padding);

//        TextureRenderer::getInstance()->drawLine(x, y, x + width, y);
//        TextureRenderer::getInstance()->drawLine(x + width, y, x + width, y + height);
//        TextureRenderer::getInstance()->drawLine(x + width, y + height, x, y + height);
//        TextureRenderer::getInstance()->drawLine(x, y + height, x, y);
        ren = nullptr;
    }
    r = nullptr;
}

void Button::handleEvents(SDL_Event& event)
{
    if (visible)
    {
        int buttonX = event.button.x;
        int buttonY = event.button.y;

        TextRenderer * r = TextRenderer::getInstance();
        SDL_Rect pos(r->queryTextSize(x, y, label));
        r = nullptr;



        int left = x - padding;
        int right = x + pos.w + padding;
        int up = y - padding;
        int down = y + pos.h + padding;


        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (buttonX > left && buttonX < right && buttonY > up && buttonY < down)
            {
                if (onClick != nullptr)
                {
                    std::cout << "Function Pointer Clicked" << std::endl;
                    onClick();
                }
            }
        }
        if (event.type == SDL_MOUSEMOTION)
        {
            if (buttonX > left && buttonX < right && buttonY > up && buttonY < down)
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

void Button::toggleVisibility()
{
    visible = !visible;
}

void Button::setOnClick(std::function<void()> funct)
{
    onClick = funct;
}

bool Button::isVisible()
{
    return visible;
}
