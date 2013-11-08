/*
 * CellOccupant.h
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary Chang
 */

#ifndef CELLOCCUPANT_H_
#define CELLOCCUPANT_H_

class CellOccupant
{
    public:

        // May need to refactor: Change to polymorphism
        enum OccupantType
        {
            Item, Player, Monster, None
        };

        CellOccupant();
        CellOccupant(OccupantType);
        ~CellOccupant();

        void setType(OccupantType type);
        OccupantType getType();

    private:
        OccupantType type;
};

#endif /* CELLOCCUPANT_H_ */
