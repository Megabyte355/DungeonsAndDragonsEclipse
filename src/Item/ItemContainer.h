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

enum containerType_t {backpack, wornInventory, store, treasurechest};

class ItemContainer : public Observable {

protected:

	containerType_t containerType; //Will be used for storing backpack, wornInventory, store, etc.
	vector<Item *> itemList;
	int maxSlots; //not sure if necessary
	map<characterStats, int> constainerStats;

public:
	ItemContainer();
	ItemContainer(containerType_t c);
	~ItemContainer();

	//Used to hold items in list.
	vector<Item *> getList();
	string displayContainerEquips();

	//Used to hold map of stats and their values
	void calculateContainerStats(); 
	string displayContainerStats();
	
	
	void addItem(Item &it);
	void removeItem(Item &e);
	string getContainerTypeEnumString(int enumVal);

};

#endif /* ITEMCONTAINER_H_ */
