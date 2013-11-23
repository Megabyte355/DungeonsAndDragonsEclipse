/*
 * DummyItemChest.h
 *
 *  Created on: Nov 22, 2013
 *      Author: Gary
 */

#ifndef DUMMYITEMCHEST_H_
#define DUMMYITEMCHEST_H_

#include "DummyItem.h"
#include "CellOccupant.h"
#include <vector>

class DummyItemChest : public virtual CellOccupant
{
    public:
        DummyItemChest(int level);
        virtual ~DummyItemChest();

    private:
        std::vector<DummyItem> items;
};

#endif /* DUMMYITEMCHEST_H_ */
