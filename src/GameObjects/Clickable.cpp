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
}

Clickable::Clickable(int x, int y, int w, int h)
{
    boundary.x = x;
    boundary.y = y;
    boundary.w = w;
    boundary.h = h;
}

Clickable::~Clickable()
{
}
