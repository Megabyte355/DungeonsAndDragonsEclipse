/*
 * ItemContainerDirector.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: Kevin
 */

#include "ItemContainerDirector.h"

ItemContainerDirector::ItemContainerDirector() {
	cout << "Creating a new ItemContainerDirector!" << endl<< endl;
}

ItemContainerDirector::ItemContainerDirector(ItemContainerBuilder* builder) {
    setBuilder(builder);
}

ItemContainerDirector::~ItemContainerDirector() {
    delete builder;
}

void ItemContainerDirector::setBuilder(ItemContainerBuilder * builder) {
    this->builder = builder;
}

void ItemContainerDirector::construct() {
	cout << "Calling construct() from ItemContainerDirector!" << endl<< endl;
    builder->buildContainer();
}

ItemContainer * ItemContainerDirector::getResult() {
    return builder->getItemContainer();
}
