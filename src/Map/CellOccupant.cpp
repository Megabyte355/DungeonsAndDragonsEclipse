/*
 * CellOccupant.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary Chang
 */

#include "CellOccupant.h"

CellOccupant::CellOccupant()
{
    type = OccupantType::Item;
}

CellOccupant::CellOccupant(OccupantType type)
{
    this->type = type;
}

CellOccupant::~CellOccupant()
{
}

void CellOccupant::setType(OccupantType type)
{
    this->type = type;
}

CellOccupant::OccupantType CellOccupant::getType()
{
    return type;
}
