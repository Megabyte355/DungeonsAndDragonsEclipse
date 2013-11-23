/*
 * CellOccupant.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary Chang
 */

#include "CellOccupant.h"

CellOccupant::CellOccupant()
{
}

CellOccupant::~CellOccupant()
{
}

void CellOccupant::setLocation(CellLocation& l)
{
    myLocation = l;
}

CellLocation CellOccupant::getLocation()
{
    return myLocation;
}
