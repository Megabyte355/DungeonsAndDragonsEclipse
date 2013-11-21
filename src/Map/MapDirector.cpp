/*
 * MapDirector.cpp
 *
 *  Created on: Nov 20, 2013
 *      Author: Gary
 */

#include "MapDirector.h"

MapDirector::MapDirector()
{
    mb = nullptr;
}

MapDirector::~MapDirector()
{
    mb = nullptr;
}

void MapDirector::constructMap()
{
    if (mb != nullptr)
    {
        mb->setSize();
        mb->setTiles();
        mb->setStartPoint();
        mb->setEndPoint();
        mb->placeItems();
        mb->placeMonsters();
    }
}

Map * MapDirector::getMap()
{
    return mb->getMap();
}
