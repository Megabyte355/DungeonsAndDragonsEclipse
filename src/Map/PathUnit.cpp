/*
 * PathUnit.cpp
 *
 *  Created on: Nov 2, 2013
 *      Author: Gary
 */

#include "PathUnit.h"

PathUnit::PathUnit(CellLocation loc, int d)
{
    location = loc;
    depth = d;
}

PathUnit::~PathUnit()
{
}

std::vector<PathUnit> PathUnit::getNextDepthNeighbors()
{
    std::vector<CellLocation> neighbors = location.getNeighborLocations();
    std::vector<PathUnit> pathUnitNeighbors;
    for(auto loc : neighbors)
    {
        pathUnitNeighbors.push_back(PathUnit(loc, depth + 1));
    }
    return pathUnitNeighbors;
}

bool PathUnit::isNeighbor(PathUnit &other)
{
    return location.isNeighbor(other.location);
}

bool PathUnit::operator==(const PathUnit &other)
{
    return location == other.location;
}
