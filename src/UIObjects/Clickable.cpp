/*
 * Clickable.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#include "Clickable.h"

Clickable::Clickable(int x, int y)
{
    boundary.x = x;
    boundary.y = y;
    boundary.w = 0;
    boundary.h = 0;

    visible = false;
    hover = false;
    clicked = false;
    callback = nullptr;

}

Clickable::Clickable(int x, int y, int w, int h)
{
    boundary.x = x;
    boundary.y = y;
    boundary.w = w;
    boundary.h = h;

    visible = false;
    hover = false;
    clicked = false;
    callback = nullptr;
}

Clickable::~Clickable()
{
    visible = false;
    hover = false;
    callback = nullptr;
}

bool Clickable::intersect(int x, int y)
{
    return (x > boundary.x) && (x < (boundary.x + boundary.w)) && (y > boundary.y) && (y < (boundary.y + boundary.h));
}

void Clickable::toggleVisibility()
{
    visible = !visible;
}

void Clickable::setCallback(std::function<void()> funct)
{
    callback = funct;
}

void Clickable::setVisibility(bool status)
{
    visible = status;
}

bool Clickable::isVisible()
{
    return visible;
}
