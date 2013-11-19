/*
 * PathUnit.h
 *
 *  Created on: Nov 2, 2013
 *      Author: Gary
 */

#ifndef PATHUNIT_H_
#define PATHUNIT_H_

#include "CellLocation.h"
#include <vector>

class PathUnit
{
    public:
        CellLocation location;
        int depth;

        PathUnit(CellLocation, int);
        ~PathUnit();

        std::vector<PathUnit> getNextDepthNeighbors();
        bool isNeighbor(PathUnit&);
        bool operator==(const PathUnit&);
};

#endif /* PATHUNIT_H_ */
