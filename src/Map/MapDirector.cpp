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
        mb->setLevel(1);
        mb->setSize();
        mb->setTiles();
        mb->setStartPoint();
        mb->setEndPoint();
        mb->placeItems();
        mb->placeMonsters();
    }
}

void MapDirector::constructMapWithLevel(int level)
{
    if (mb != nullptr)
    {
        mb->setLevel(level);
        mb->setSize();
        mb->setTiles();
        mb->setStartPoint();
        mb->setEndPoint();
        mb->placeItems();
        mb->placeMonsters();
    }
}

void MapDirector::setMapBuilder(MapBuilder* builder)
{
    mb = builder;
}

Map * MapDirector::getMap()
{
    return mb->getMap();
}
