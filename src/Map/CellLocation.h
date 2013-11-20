/*
 * CellLocation.h
 *
 *  Created on: Nov 2, 2013
 *      Author: Gary
 */

#ifndef CELLLOCATION_H_
#define CELLLOCATION_H_

#include <vector>

class CellLocation
{
    public:
        int x;
        int y;

        CellLocation();
        CellLocation(int, int);
        ~CellLocation();

        bool operator==(const CellLocation &);
        bool isNeighbor(const CellLocation &);
        std::vector<CellLocation> getNeighborLocations();
};

#endif /* CELLLOCATION_H_ */
