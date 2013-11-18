/*
 * Clickable.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#ifndef CLICKABLE_H_
#define CLICKABLE_H_

#include <SDL.h>
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include "Observable.h"

class Clickable : public virtual Observable
{
    public:
        virtual ~Clickable() override;

        virtual void handleEvents(SDL_Event &) = 0;
        virtual void draw() = 0;

    protected:
        Clickable();
        Clickable(int, int);
        Clickable(int x, int y, int w, int h);
        SDL_Rect boundary;
};

#endif /* CLICKABLE_H_ */
