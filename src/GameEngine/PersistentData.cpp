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
    currentChar = nullptr;
    currentMap = nullptr;
    savedMaps.resize(10);
    premadeMaps.resize(10);
    savedCharacters.resize(10);
    premadeCharacters.resize(10);
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

PersistentData::MapLoadMode PersistentData::getMapLoadMode()
{
    return mapLoadMode;
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

void PersistentData::saveMapToCurrentSlot(Map * m)
{
    savedMaps[mapLoadSlot] = m;
}

void PersistentData::loadMapFromCurrentSlot()
{
    currentMap = savedMaps[mapLoadSlot];
}

//Character
void PersistentData::setCharLoadPremade(int premade)
{
    charLoadPremade = premade;
}

void PersistentData::setCharLoadSlot(int slot)
{
    charLoadSlot = slot;
}

Character* PersistentData::getCurrentChar() const
{
    return currentChar;
}

int PersistentData::getCharLoadPremade() const
{
    return charLoadPremade;
}

int PersistentData::getCharLoadSlot() const
{
    return charLoadSlot;
}
void PersistentData::setCharLoadMode(CharLoadMode charLoadMode)
{
    this->charLoadMode = charLoadMode;
}

void PersistentData::saveCharToCurrentSlot(Character * c)
{
    savedCharacters[charLoadSlot] = c;
}
void PersistentData::loadCharFromCurrentSlot()
{
    currentChar = savedCharacters[charLoadSlot];
}
