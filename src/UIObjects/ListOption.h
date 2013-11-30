/*
 * ListOption.h
 *
 *  Created on: Nov 29, 2013
 *      Author: Gary
 */

#ifndef LISTOPTION_H_
#define LISTOPTION_H_

#include "Clickable.h"

// This class is intended to be used by ScrollingOptionList to display elements
class ListOption : public virtual Clickable
{
    public:
        ListOption(int,int,int,int);
        virtual ~ListOption();

        virtual void update() = 0;
        virtual void draw() = 0;
        virtual void handleEvents(SDL_Event &) = 0;

        void setCoordinates(int x, int y);
};

#endif /* LISTOPTION_H_ */
