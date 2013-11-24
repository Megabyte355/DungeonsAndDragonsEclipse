/*
 * Clickable.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#ifndef CLICKABLE_H_
#define CLICKABLE_H_

#include <SDL.h>
#include <functional>
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include "Observable.h"


class Clickable: public virtual Observable
{
    public:
        virtual ~Clickable() override;

        virtual void update() = 0;
        virtual void handleEvents(SDL_Event &) = 0;
        virtual void draw() = 0;

        void setCallback(std::function<void()>);
        void setVisibility(bool);
        bool isVisible();
        void toggleVisibility();

        SDL_Rect getBoundary();

    protected:
        bool visible;
        bool hover;
        bool clicked;

        Clickable(int, int);
        Clickable(int x, int y, int w, int h);
        SDL_Rect boundary;
        bool intersect(int x, int y);
        std::function<void()> callback;
};

#endif /* CLICKABLE_H_ */
