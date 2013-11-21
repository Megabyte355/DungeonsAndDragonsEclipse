/*
 * MapBuilder.cpp
 *
 *  Created on: Nov 20, 2013
 *      Author: Gary
 */

#include "MapBuilder.h"

MapBuilder::~MapBuilder()
{
    if(!mapReturned)
    {
        delete map;
    }
    map = nullptr;
}

Map * MapBuilder::getMap()
{
    mapReturned = true;
    return map;
}
