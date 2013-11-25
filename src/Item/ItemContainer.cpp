/*
 * ItemContainer.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "ItemContainer.h"

ItemContainer::ItemContainer() {
}

ItemContainer::~ItemContainer() {
	itemList.clear();
}

vector<Item *> ItemContainer::getList() {
    return itemList;
}

//Used in update() to show all equips inside the container
string ItemContainer::displayContainerEquips() {
    stringstream ss;

    ss << "Displaying all items in container" << endl << endl;
    for(Item * it : itemList) {
        ss << it->toString() << endl << endl;
    }
    return ss.str();
}

//Adds an item to the container, notifies all observers.
void ItemContainer::addItem(Item * item) {

    itemList.push_back(item);
    cout << item->getName() << " was added to container.";
	//MUST NOTIFY ALL OBSERVERS!
	notify();
}

//Removes an item from the container, notifies all observers.
void ItemContainer::removeItem(Item * e) {
    for (vector<Item *>::iterator it = itemList.begin(); it != itemList.end(); it++) {
        if ((*it)->isEqual(*e)) {
            itemList.erase(it);
            cout << e->getName() << " was removed from container.";
			//MUST NOTIFY ALL OBSERVERS!
			notify();
			break;
        }
        cout << e->getName() << " could not be found in container.";
    }
}

bool ItemContainer::isItemInContainer(Item * e){
    for (vector<Item *>::iterator it = itemList.begin(); it != itemList.end(); it++) {
        if ((*it)->isEqual(*e)) { //polymorphic call to determine if 2 items are equal
            return true;
            break;
        }
    }
    return false;
}

//string ItemContainer::getContainerTypeEnumString(int enumVal) {
//    string characterStatsMapping[4] = { "Backpack", "Worn Inventory", "Store", "Treasure Chest" };
//    return characterStatsMapping[enumVal];
//}

void ItemContainer::calculateContainerStats() {

    Equipment * p_it;
    map<characterStats,int> localContainer;
    for (Item * it : itemList) {

        p_it = dynamic_cast<Equipment *>(it); //Casting to (Equipment)it, to have access to its methods;
        if (p_it != nullptr) {
            map<characterStats, int> localMap = p_it->getEquipmentStats();

            for (std::map<characterStats, int>::iterator it = localMap.begin(); it != localMap.end(); ++it) {
                if (localMap.find(it->first) == localMap.end()) {
                    localContainer[it->first] = it->second;  //not found, generates entry
                }
                else {
                    localContainer[it->first] += it->second;  //found, adds
                }
            }
        }
    }
	p_it = nullptr;
	containerStats = localContainer;
}

//Function used to map all contents of an inventory to added stats
string ItemContainer::displayContainerStats() {

    stringstream ss;

	ss << "Displaying statistics added by container!" << endl << "==============================" << endl << endl;

    for (std::map<characterStats, int>::iterator it = containerStats.begin(); it != containerStats.end(); ++it) {

        switch (it->first) {

            case characterStats::ARMOR:
                ss << "ARMOR: " << it->second << endl;
                break;

            case characterStats::ATTACK:
                ss << "ATTACK: " << it->second << endl;
                break;

            case characterStats::CHARISMA:
                ss << "CHARISMA: " << it->second << endl;
                break;

            case characterStats::CONSTITUTION:
                ss << "CONSTITUTION: " << it->second << endl;
                break;

            case characterStats::DAMAGE:
                ss << "DAMAGE: " << it->second << endl;
                break;

            case characterStats::DEXTERITY:
                ss << "DEXTERITY: " << it->second << endl;
                break;

            case characterStats::INTELLIGENCE:
                ss << "INTELLIGENCE: " << it->second << endl;
                break;

            case characterStats::STRENGTH:
                ss << "STRENGTH: " << it->second << endl;
                break;

            case characterStats::WISDOM:
                ss << "WISDOM: " << it->second << endl;
                break;
            default:
                break;
        }
    }
    return ss.str();
}
