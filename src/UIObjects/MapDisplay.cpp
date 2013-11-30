/*
 * MapDisplay.cpp
 *
 *  Created on: Nov 30, 2013
 *      Author: Gary
 */

#include <MapDisplay.h>

MapDisplay::MapDisplay(Map * model)
{
    mapModel = model;
}

MapDisplay::~MapDisplay()
{
    // The map is this class' responsibility
    mapModel = nullptr;
}

