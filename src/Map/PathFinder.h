/*
 * PathFinder.h
 *
 *  Created on: Nov 2, 2013
 *      Author: Gary
 */

#ifndef PATHFINDER_H_
#define PATHFINDER_H_

#include <vector>
#include <algorithm>
#include "Map.h"
#include "PathUnit.h"

class Map;

class PathFinder
{
    public:
        PathFinder();
        ~PathFinder();

        static std::vector<CellLocation> getShortestPath(Map &map, Cell &origin, Cell &dest);
    private:
        static bool vectorContains(const std::vector<PathUnit>&, PathUnit&);
        static std::vector<PathUnit> filterPath(std::vector<PathUnit>&, Cell&, Cell&, int estinationDepth);
        static std::vector<CellLocation> convertPathUnitsToCellLocations(std::vector<PathUnit> &list);
};

#endif /* PATHFINDER_H_ */
