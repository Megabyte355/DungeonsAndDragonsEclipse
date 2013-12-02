/*
 * ListOption.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: Gary
 */

#include <ListOption.h>

ListOption::ListOption(int x, int y, int w, int h) :
        Clickable(x, y, w, h)
{
}

ListOption::~ListOption()
{
}


void ListOption::setCoordinates(int x, int y)
{
    boundary.x = x;
    boundary.y = y;
}
