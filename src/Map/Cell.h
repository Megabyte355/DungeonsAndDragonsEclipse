/*
 * Cell.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#ifndef CELL_H_
#define CELL_H_

#include "CellOccupant.h"
#include "CellLocation.h"
#include <memory>

class Cell
{
    public:
        enum CellType
        {
            Wall, Floor, Start, End
        };

        // Constructors
        Cell(int, int);
        Cell(CellType, int, int);
        ~Cell();

        // Getters and Setters
        int getX();
        int getY();
        void setX(int);
        void setY(int);
        CellType getType();
        void setType(CellType);
        CellLocation getLocation();
        std::vector<CellLocation> getNeighbors();

        // Occupation operations
        CellOccupant * getOccupant();
        void setOccupant(CellOccupant *);
        void clearOccupant();
        bool isOccupiable();
        bool isOccupied();

    private:
        CellLocation location;
        CellType type;
        CellOccupant * occupant;
};

#endif /* CELL_H_ */
