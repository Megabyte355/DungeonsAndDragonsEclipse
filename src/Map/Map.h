/*
 * Map.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#ifndef MAP_H_
#define MAP_H_


#include "Cell.h"
#include "PathFinder.h"
#include "Observable.h"
#include "Recordable.h"
#include <vector>
#include <iostream>
#include <functional>

class Map: public virtual Observable, public virtual Recordable
{
    public:
        Map();
        Map(int, int);
        ~Map();

        void initialize(int, int);

        // Map properties
        int getWidth();
        int getHeight();

        // Cell operations
        std::shared_ptr<Cell> getCell(int, int);
        std::shared_ptr<Cell> getStartCell();
        std::shared_ptr<Cell> getEndCell();
        void setCell(Cell::CellType, int, int);
        void setStartCell(int, int);
        void setEndCell(int, int);

        // Validations
        bool validateMap();
        bool isValidCell(Cell);
        bool isValidCell(int, int);
        bool isValidCell(CellLocation);
        bool isOccupiable(CellLocation);
        bool isValidPath(Cell, Cell);

        // Path calculation
        std::vector<CellLocation> getShortestPath(Cell&, Cell&);
        std::vector<CellLocation> getStartToEndPath();

    protected:
        // Save/Load functions
        std::string toString() override;
        void fromString(std::string) override;

    private:
        // Map variables
        std::vector<CellLocation> shortestPath;
        std::vector<std::vector<std::shared_ptr<Cell>>>matrix;
        int mapWidth;
        int mapHeight;
    };

#endif /* MAP_H_ */
