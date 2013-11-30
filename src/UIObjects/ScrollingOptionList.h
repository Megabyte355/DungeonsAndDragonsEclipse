/*
 * ScrollingOptionList.h
 *
 *  Created on: Nov 29, 2013
 *      Author: Gary
 */

#ifndef SCROLLINGOPTIONLIST_H_
#define SCROLLINGOPTIONLIST_H_

#include <vector>
#include <SDL.h>
#include "Button.h"
#include "TextureRenderer.h"

class ScrollingOptionList
{
    public:
        ScrollingOptionList(int x, int y, int w, int h, int i);
        virtual ~ScrollingOptionList();

        virtual void update();
        virtual void draw();
        virtual void handleEvents(SDL_Event &);

    protected:
        int x;
        int y;
        int totalWidth;
        int totalHeight;
        int optionsToDisplay;
        int optionHeight;
        int currentIndex;
        Button * up;
        Button * down;

        void scrollUp();
        void scrollDown();

        std::vector<ListOption *> options;
};

#endif /* SCROLLINGOPTIONLIST_H_ */
