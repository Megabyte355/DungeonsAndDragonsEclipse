/*
 * ItemContainerBuilder.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: Kevin
 */

#include "ItemContainerBuilder.h"

ItemContainerBuilder::ItemContainerBuilder() {
    cout << "Creating abstract instance of ItemContainerBuilder!" << endl;
    characterLevel = 1;
    mapLevel = 1;

	itemContainer = new ItemContainer();
}

ItemContainerBuilder::ItemContainerBuilder(int pmapLevel, int pcharacterLevel){
    characterLevel = pcharacterLevel;
    mapLevel = pmapLevel;

	itemContainer = new ItemContainer();
}

ItemContainerBuilder::~ItemContainerBuilder() {
}

