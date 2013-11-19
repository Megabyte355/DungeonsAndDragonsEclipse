/*
 * TextField.h
 *
 *  Created on: Nov 18, 2013
 *      Author: Gary
 */

#ifndef TEXTFIELD_H_
#define TEXTFIELD_H_

#include "Clickable.h"

class TextField: public virtual Clickable
{
    public:
        TextField(int, int);
        virtual ~TextField();

        virtual void handleEvents(SDL_Event &) = 0;
        virtual void draw() = 0;
};

#endif /* TEXTFIELD_H_ */
