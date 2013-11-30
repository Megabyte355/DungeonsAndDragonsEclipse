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
    buttonHeight = 30;
    optionHeight = (h - buttonHeight * 2) / i;
    currentIndex = 0;
    
    up = new Button(x, y, w, buttonHeight, "Up");
    down = new Button(x, y + h - buttonHeight, w, buttonHeight, "Down");
    up->setVisibility(true);
    down->setVisibility(true);
    up->setCallback(std::bind(&ScrollingOptionList::scrollUp, this));
    down->setCallback(std::bind(&ScrollingOptionList::scrollDown, this));
}

ScrollingOptionList::~ScrollingOptionList()
{
    for (auto o : options)
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
    up->draw();
    down->draw();
//    TextureRenderer::getInstance()->drawTexture("yellow_triangle_up", x + (totalWidth / 2) - 10, y, 10, 30);
}

void ScrollingOptionList::handleEvents(SDL_Event& event)
{
}

void ScrollingOptionList::scrollUp()
{
    if (currentIndex > 0)
    {
        currentIndex--;
        updateOptionVisibility();
    }
}

void ScrollingOptionList::scrollDown()
{
    if (currentIndex < ((int)options.size() - optionsToDisplay))
    {
        currentIndex++;
        updateOptionVisibility();
    }
}

void ScrollingOptionList::updateOptionVisibility()
{
    int number = 0;
    for (int i = 0; i < (int)options.size(); i++)
    {
        if (i >= currentIndex && i < currentIndex + optionsToDisplay)
        {
            options[i]->setVisibility(true);
            options[i]->setCoordinates(x, y + buttonHeight + optionHeight * number++);
        }
        else
        {
            options[i]->setVisibility(false);
        }
    }
}
