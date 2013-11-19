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
        Clickable(x, y)
{
    visible = false;
    hover = false;
    this->label = label;
    onClick = nullptr;

    labelBoundary = SDL_Rect(TextRenderer::getInstance()->queryTextSize(x + padding, y + padding, label));

    boundary.w = 2 * padding + labelBoundary.w;
    boundary.h = 2 * padding + labelBoundary.h;
}

// Padding is not used. The label is centered in the button.
Button::Button(int x, int y, int w, int h, std::string label) :
        Clickable(x, y, w, h)
{
    visible = false;
    hover = false;
    this->label = label;
    onClick = nullptr;

    labelBoundary = SDL_Rect(TextRenderer::getInstance()->queryTextSize(x, y, label));
    labelBoundary.x = x + (w - labelBoundary.w) / 2;
    labelBoundary.y = y + (h - labelBoundary.h) / 2;
}

Button::~Button()
{
    visible = false;
    hover = false;
    onClick = nullptr;
}

void Button::update()
{
}

void Button::draw()
{
    TextRenderer * texts = TextRenderer::getInstance();
    texts->setSettings("arial", 20, TextRenderer::white);

    if (hover)
    {
        TextureRenderer::getInstance()->drawTexture("black_button_clicked", boundary.x, boundary.y, boundary.w,
                boundary.h);
    }
    else
    {
        TextureRenderer::getInstance()->drawTexture("black_button_on", boundary.x, boundary.y, boundary.w, boundary.h);
    }

    texts->renderText(labelBoundary.x, labelBoundary.y, label);
    texts = nullptr;
}

void Button::handleEvents(SDL_Event &event)
{
    if (visible)
    {
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (intersect(event.button.x, event.button.y))
            {
                if (onClick != nullptr)
                {
                    std::cout << "Function Pointer Clicked" << std::endl;
                    onClick();
                }
            }
        }
        else if (event.type == SDL_MOUSEMOTION)
        {
            hover = intersect(event.button.x, event.button.y);
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
