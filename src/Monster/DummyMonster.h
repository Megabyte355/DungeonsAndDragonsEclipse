/*
 * DummyMonster.h
 *
 *  Created on: Nov 22, 2013
 *      Author: Gary
 */

#ifndef DUMMYMONSTER_H_
#define DUMMYMONSTER_H_

#include "CellOccupant.h"

class DummyMonster : public virtual CellOccupant
{
    public:
        DummyMonster(int level);
        virtual ~DummyMonster();

    private:
        int level;
};

#endif /* DUMMYMONSTER_H_ */
