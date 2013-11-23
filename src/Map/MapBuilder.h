/*
 * MapBuilder.h
 *
 *  Created on: Nov 20, 2013
 *      Author: Gary
 */

#ifndef MAPBUILDER_H_
#define MAPBUILDER_H_

#include "Map.h"

class MapBuilder
{
    public:
        virtual ~MapBuilder();

        void setLevel(int);
        virtual void setSize() = 0;
        virtual void setTiles() = 0;
        virtual void setStartPoint() = 0;
        virtual void setEndPoint() = 0;
        virtual void placeItems() = 0;
        virtual void placeMonsters() = 0;

        Map * getMap();

    protected:
        int level;
        bool mapReturned;
        Map * map;
};

#endif /* MAPBUILDER_H_ */
