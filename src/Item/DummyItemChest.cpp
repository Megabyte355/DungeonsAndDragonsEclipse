/*
 * DummyItemChest.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: Gary
 */

#include "DummyItemChest.h"

DummyItemChest::DummyItemChest(int level)
{
    // A higher map level gives more items! (as an example)
    for (int i = 0; i < level; i++)
    {
        items.push_back(DummyItem(level));
    }
}

DummyItemChest::~DummyItemChest()
{
}

