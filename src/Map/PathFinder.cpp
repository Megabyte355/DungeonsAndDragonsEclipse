/*
 * PathFinder.cpp
 *
 *  Created on: Nov 2, 2013
 *      Author: Gary
 */

#include "PathFinder.h"

#include <iostream>

PathFinder::PathFinder()
{
}

PathFinder::~PathFinder()
{
}

std::vector<CellLocation> PathFinder::getShortestPath(Map &map, Cell &origin, Cell &dest)
{
    bool destinationFound = false;
    int destinationDepth = 0;
    unsigned int index = 0;

    std::vector<PathUnit> unfilteredPath;
    std::vector<PathUnit> candidates;

    // Push origin to the list to begin
    unfilteredPath.push_back(PathUnit(origin.getLocation(), 0));

    // Begin search
    while (!destinationFound && index < unfilteredPath.size())
    {
        // Add valid neighbors to the list
        candidates = unfilteredPath[index].getNextDepthNeighbors();
        for (std::vector<PathUnit>::iterator it = candidates.begin(); it != candidates.end(); it++)
        {
            // Check if this location is already in our list
            if (!vectorContains(unfilteredPath, *it) && map.isOccupiable((*it).location))
            {
                unfilteredPath.push_back(*it);

                // If the destination is found, mark it
                if (dest.getLocation() == it->location)
                {
                    destinationFound = true;
                    destinationDepth = it->depth;
                    break;
                }
            }
        }
        candidates.clear();
        index++;
    }

    if (!destinationFound)
    {
        // Return an empty vector
        return std::vector<CellLocation>();
    }
    else
    {
        // Process unfiltered list back into a list of CellLocations
        std::vector<PathUnit> filteredPath = filterPath(unfilteredPath, origin, dest, destinationDepth);
        return convertPathUnitsToCellLocations(filteredPath);
    }
}

bool PathFinder::vectorContains(const std::vector<PathUnit> &list, PathUnit &target)
{
    for (auto unit : list)
    {
        if (unit == target)
        {
            return true;
        }
    }
    return false;
}

std::vector<PathUnit> PathFinder::filterPath(std::vector<PathUnit> &list, Cell &origin, Cell &dest,
        int destinationDepth)
{
    int targetDepth = destinationDepth - 1;
    bool done = false;
    PathUnit current(list.back());
    std::vector<PathUnit> filteredPath;
    filteredPath.push_back(current);

    while (!done)
    {
        for (PathUnit p : list)
        {
            // Find the first neighbor with depth = targetDepth
            if (p.depth == targetDepth && p.isNeighbor(current))
            {
                filteredPath.push_back(p);
                current = p;
                targetDepth--;

                if (targetDepth < 0)
                {
                    done = true;
                }
                break;
            }
        }
    }

    std::reverse(std::begin(filteredPath), std::end(filteredPath));

    return filteredPath;
}

std::vector<CellLocation> PathFinder::convertPathUnitsToCellLocations(std::vector<PathUnit> &pathunits)
{
    std::vector<CellLocation> locations;
    for (auto unit : pathunits)
    {
        locations.push_back(unit.location);
    }
    return locations;
}
