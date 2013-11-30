/*
 * ItemContainer.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#ifndef ITEMCONTAINER_H_
#define ITEMCONTAINER_H_

#include <vector>
#include <sstream>
#include "Equipment.h"
#include "Observable.h"

using namespace std;

class ItemContainer : public Observable {

protected:

	vector<Item *> itemList;
	map<characterStats, int> containerStats;

public:
	ItemContainer();
	~ItemContainer();

	vector<Item *> getList();
	void displayContainerEquips();

	void calculateContainerStats(); 
	void displayContainerStats();
	
	
	void addItem(Item * it);
	void removeItem(Item * it);

	bool isItemInContainer(Item * e);



};

#endif /* ITEMCONTAINER_H_ */
