/*
 * ScrollingOptionList.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: Gary
 */

#include <ScrollingOptionList.h>

ScrollingOptionList::ScrollingOptionList(int x, int y, int w, int h, int i)
{
    this->x = x;
    this->y = y;
    totalWidth = w;
    totalHeight = h;
    optionsToDisplay = i;
    optionHeight = (h - 40) / i;
    currentIndex = 0;
    up = new Button(x, y, w, 30, "");
    down = new Button(x, y + h - 20, w, 30, "");
}

ScrollingOptionList::~ScrollingOptionList()
{
    for(auto o :options)
    {
        delete o;
    }
    options.clear();

    delete up;
    delete down;
    up = nullptr;
    down = nullptr;
}

void ScrollingOptionList::update()
{
}

void ScrollingOptionList::draw()
{
}

void ScrollingOptionList::handleEvents(SDL_Event& event)
{
}

void ScrollingOptionList::scrollUp()
{
}

void ScrollingOptionList::scrollDown()
{
}
