/*
 * DummyCharacter.h
 *
 *  Created on: Nov 22, 2013
 *      Author: Gary
 */

#ifndef DUMMYCHARACTER_H_
#define DUMMYCHARACTER_H_

#include "CellOccupant.h"

class DummyCharacter : public virtual CellOccupant
{
    public:
        DummyCharacter();
        virtual ~DummyCharacter();

};

#endif /* DUMMYCHARACTER_H_ */
