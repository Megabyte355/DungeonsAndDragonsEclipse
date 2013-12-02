/*
 * MapDisplay.h
 *
 *  Created on: Nov 30, 2013
 *      Author: Gary
 */

#ifndef MAPDISPLAY_H_
#define MAPDISPLAY_H_

#include "Map.h"

class MapDisplay
{
    public:
        MapDisplay(Map *);
        virtual ~MapDisplay();



    private:
        Map * mapModel;
};

#endif /* MAPDISPLAY_H_ */
