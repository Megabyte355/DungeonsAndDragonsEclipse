/*
 * Button.cpp
 *
 *  Created on: Nov 9, 2013
 *      Author: Gary
 */

#include "Button.h"

// Constructor takes location of button, padding and a string to display.
// The size of the button is automatically calculated.
Button::Button(int x, int y, int padding, std::string label) :
        Clickable(x + padding, y + padding)
{
    visible = false;
    hover = false;
    this->label = label;
    onClick = nullptr;
    paddingX = padding;
    paddingY = padding;
}

// Padding is not used. The label is centered in the button.
Button::Button(int x, int y, int w, int h, std::string label)
{
    visible = false;
    hover = false;
    this->label = label;
    onClick = nullptr;
    SDL_Rect pos(TextRenderer::getInstance()->queryTextSize(x, y, label));
    paddingX = (w - pos.w) / 2;
    paddingY = (h - pos.h) / 2;
    this->x = x + paddingX;
    this->y = y + paddingY;
}

Button::~Button()
{
    visible = false;
    hover = false;
    onClick = nullptr;
}

void Button::draw()
{
    TextRenderer * texts = TextRenderer::getInstance();
    texts->setSettings("arial", 20, TextRenderer::white);

    SDL_Rect pos(texts->queryTextSize(x, y, label));
    if (hover)
    {
        TextureRenderer::getInstance()->drawTexture("black_button_clicked", x - paddingX, y - paddingY,
                pos.w + 2 * paddingX, pos.h + 2 * paddingY);
    }
    else
    {
        TextureRenderer::getInstance()->drawTexture("black_button_on", x - paddingX, y - paddingY, pos.w + 2 * paddingX,
                pos.h + 2 * paddingY);
    }

    texts->renderText(x, y, label);
    texts = nullptr;
}

void Button::handleEvents(SDL_Event &event)
{
    if (visible)
    {
        int buttonX = event.button.x;
        int buttonY = event.button.y;

        TextRenderer * r = TextRenderer::getInstance();
        SDL_Rect pos(r->queryTextSize(x, y, label));
        r = nullptr;

        int left = x - paddingX;
        int right = x + pos.w + paddingX;
        int up = y - paddingY;
        int down = y + pos.h + paddingY;

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
