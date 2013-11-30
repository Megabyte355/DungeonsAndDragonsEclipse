/*
 * ScrollingMapTileOptionList.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: Gary
 */

#include <MapTileOptionList.h>

MapTileOptionList::MapTileOptionList(int x, int y, int w, int h, int i) :
        ScrollingOptionList(x, y, w, h, i)
{
    selectedType = Cell::CellType::Floor;

    TileOption * opt;
    opt = new TileOption(Cell::CellType::Wall, 0, 0, w, (h - buttonHeight * 2) / i);
    opt->setVisibility(false);
    opt->functionPointer = std::bind(&MapTileOptionList::setSelectedType, this, std::placeholders::_1);
    addMapTileOption(opt);

    opt = new TileOption(Cell::CellType::Floor, 0, 0, w, (h - buttonHeight * 2) / i);
    opt->setVisibility(false);
    opt->functionPointer = std::bind(&MapTileOptionList::setSelectedType, this, std::placeholders::_1);
    addMapTileOption(opt);

    opt = new TileOption(Cell::CellType::Start, 0, 0, w, (h - buttonHeight * 2) / i);
    opt->setVisibility(false);
    opt->functionPointer = std::bind(&MapTileOptionList::setSelectedType, this, std::placeholders::_1);
    addMapTileOption(opt);

    opt = new TileOption(Cell::CellType::End, 0, 0, w, (h - buttonHeight * 2) / i);
    opt->setVisibility(false);
    opt->functionPointer = std::bind(&MapTileOptionList::setSelectedType, this, std::placeholders::_1);
    addMapTileOption(opt);

    opt = nullptr;
    updateOptionVisibility();
}

MapTileOptionList::~MapTileOptionList()
{
}

void MapTileOptionList::update()
{
}

void MapTileOptionList::draw()
{
    up->draw();
    down->draw();
    for (auto o : options)
    {
        o->draw();
    }
}

void MapTileOptionList::handleEvents(SDL_Event& event)
{
    up->handleEvents(event);
    down->handleEvents(event);
    for (auto o : options)
    {
        o->handleEvents(event);
    }
}

void MapTileOptionList::addMapTileOption(TileOption* opt)
{
    options.push_back(opt);
}

Cell::CellType MapTileOptionList::getSelectedType()
{
    return selectedType;
}

void MapTileOptionList::setSelectedType(Cell::CellType cellType)
{
    selectedType = cellType;
}
