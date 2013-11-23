/*
 * CellOccupant.h
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary Chang
 */

#ifndef CELLOCCUPANT_H_
#define CELLOCCUPANT_H_

#include "CellLocation.h"

class CellOccupant
{
    public:
        CellOccupant();
        virtual ~CellOccupant();

        void setLocation(CellLocation&);
        CellLocation getLocation();

    private:
        CellLocation myLocation;
};

#endif /* CELLOCCUPANT_H_ */
