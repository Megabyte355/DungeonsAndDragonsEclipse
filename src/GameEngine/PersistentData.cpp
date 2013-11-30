/*
 * PersistentData.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: Gary
 */

#include <PersistentData.h>

PersistentData * PersistentData::instance = nullptr;

PersistentData::PersistentData()
{
    currentMap = nullptr;
    mapLoadWidth = 0;
    mapLoadHeight = 0;
    mapLoadPremade = 0;
    mapLoadSlot = 0;
    mapLoadMode = NewMap;
}

PersistentData::~PersistentData()
{
    for (auto m : savedMaps)
    {
        delete m;
    }
    savedMaps.clear();
    for (auto m : premadeMaps)
    {
        delete m;
    }
    premadeMaps.clear();
}

PersistentData * PersistentData::getInstance()
{
    if (instance == nullptr)
    {
        instance = new PersistentData();
    }
    return instance;
}

void PersistentData::setMapLoadSize(int w, int h)
{
    mapLoadWidth = w;
    mapLoadHeight = h;
}

void PersistentData::setMapLoadPremade(int premade)
{
    mapLoadPremade = premade;
}

void PersistentData::setMapLoadSlot(int slot)
{
    mapLoadSlot = slot;
}

Map * PersistentData::getCurrentMap() const
{
    return currentMap;
}

int PersistentData::getMapLoadHeight() const
{
    return mapLoadHeight;
}

void PersistentData::setMapLoadMode(MapLoadMode mapLoadMode)
{
    this->mapLoadMode = mapLoadMode;
}

int PersistentData::getMapLoadPremade() const
{
    return mapLoadPremade;
}

int PersistentData::getMapLoadSlot() const
{
    return mapLoadSlot;
}

int PersistentData::getMapLoadWidth() const
{
    return mapLoadWidth;
}
