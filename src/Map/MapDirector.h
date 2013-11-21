/*
 * MapDirector.h
 *
 *  Created on: Nov 20, 2013
 *      Author: Gary
 */

#ifndef MAPDIRECTOR_H_
#define MAPDIRECTOR_H_

#include "Map.h"
#include "MapBuilder.h"

class MapDirector
{
    public:
        MapDirector();
        virtual ~MapDirector();

        void setMapBuilder(MapBuilder *);
        void constructMap();
        Map * getMap();

    private:
        MapBuilder * mb;
};

#endif /* MAPDIRECTOR_H_ */
