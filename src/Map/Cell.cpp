/*
 * Cell.cpp
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#include "Cell.h"

Cell::Cell(int x, int y)
{
    this->type = Floor;
    location.x = x;
    location.y = y;
    occupant = nullptr;
}

Cell::Cell(CellType type, int x, int y)
{
    this->type = type;
    location.x = x;
    location.y = y;
    occupant = nullptr;
}

Cell::~Cell()
{
    // The occupant does not belong to Cell class - It is merely a reference!
    occupant = nullptr;
}

void Cell::setX(int x)
{
    location.x = x;
}

void Cell::setY(int y)
{
    location.y = y;
}

int Cell::getX()
{
    return location.x;
}

int Cell::getY()
{
    return location.y;
}

Cell::CellType Cell::getType()
{
    return type;
}

void Cell::setType(CellType type)
{
    this-> type = type;
}

void Cell::clearOccupant()
{
    occupant = nullptr;
}

void Cell::setOccupant(CellOccupant * occupant)
{
    this->occupant = occupant;
}

CellLocation Cell::getLocation()
{
    return location;
}

CellOccupant * Cell::getOccupant()
{
    return occupant;
}

std::vector<CellLocation> Cell::getNeighbors()
{
    return location.getNeighborLocations();
}

bool Cell::isOccupiable()
{
    return type == Floor || type == Start || type == End || type == Monster || type == Treasure;
}

bool Cell::isOccupied()
{
    return occupant != nullptr;
}
