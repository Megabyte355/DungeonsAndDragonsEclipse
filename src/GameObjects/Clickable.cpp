/*
 * Clickable.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#include "Clickable.h"

Clickable::Clickable()
{
    this->x = 0;
    this->y = 0;
    width = 0;
    height = 0;
    click = false;
}

Clickable::Clickable(int x, int y, int w, int h)
{
    this->x = x;
    this->y = y;
    width = w;
    height = h;
    click = false;
}

Clickable::~Clickable()
{
    // This class is not the main owner of the renderer. It won't be destroyed here.
    observers.clear();
}

bool Clickable::isClicked()
{
    bool copy = click;
    click = false;
    return copy;
}
