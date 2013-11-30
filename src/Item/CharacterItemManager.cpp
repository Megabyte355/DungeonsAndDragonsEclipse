/*
 * CharacterItemManager.cpp
 *
 *  Created on: Nov 23, 2013
 *      Author: Kevin
 */

#include "CharacterItemManager.h"

using namespace std;

CharacterItemManager::CharacterItemManager() {
    cout << "Creating CharacterItemManager!" << endl;

    equippedHelmet = nullptr;
    equippedArmor = nullptr;
    equippedShield = nullptr;
    equippedBracers = nullptr;
    equippedRing = nullptr;
    equippedBelt = nullptr;
    equippedBoots = nullptr;
    equippedWeapon = nullptr;
}

CharacterItemManager::~CharacterItemManager() {

    if (equippedHelmet != nullptr) {
        delete equippedHelmet;
    }
    if (equippedArmor != nullptr) {
        delete equippedArmor;
    }
    if (equippedShield != nullptr) {
        delete equippedShield;
    }
    if (equippedBracers != nullptr) {
        delete equippedBracers;
    }
    if (equippedRing != nullptr) {
        delete equippedRing;
    }
    if (equippedBelt != nullptr) {
        delete equippedBelt;
    }
    if (equippedBoots != nullptr) {
        delete equippedBoots;
    }
    if (equippedWeapon != nullptr) {
        delete equippedWeapon;
    }

    inventoryStats.clear();
}

bool CharacterItemManager::isItemInBag(Item * e) {
    return bag.isItemInContainer(e);
}

void CharacterItemManager::equipItem(Equipment * e) {

    Equipment ** equipped = getEquipmentSlot(e);

    if (*equipped != nullptr) {
        unequipItem(*equipped); //Unequips the correct attribute
    }

    cout << "Equipping " << e->getClassName() << " to Inventory!" << endl;

    *equipped = e; //Equips item
}

Equipment ** CharacterItemManager::getEquipmentSlot(Equipment * e) {
    if (dynamic_cast<Helmet *>(e) != nullptr)
        return (Equipment **) &equippedHelmet;
    else if (dynamic_cast<Armor *>(e) != nullptr)
        return (Equipment **) &equippedArmor;
    else if (dynamic_cast<Shield *>(e) != nullptr)
        return (Equipment **) &equippedShield;
    else if (dynamic_cast<Bracers *>(e) != nullptr)
        return (Equipment **) &equippedBracers;
    else if (dynamic_cast<Ring *>(e) != nullptr)
        return (Equipment **) &equippedRing;
    else if (dynamic_cast<Belt *>(e) != nullptr)
        return (Equipment **) &equippedBelt;
    else if (dynamic_cast<Boots *>(e) != nullptr)
        return (Equipment **) &equippedBoots;
    else if (dynamic_cast<Weapon *>(e) != nullptr)
        return (Equipment **) &equippedWeapon;
    else
        return nullptr;
}

//Method assumes user can click on equipped item and pass that as argument
void CharacterItemManager::unequipItem(Equipment * e) {
    Equipment ** equipped = getEquipmentSlot(e); // returns me the pointer to the attribute

    if (e == *equipped) {
        bag.addItem(*equipped);
        *equipped = nullptr; //Sets correct attribute to null
        cout << e->getClassName() << " has been unequipped and put into character bag!" << endl;
    }
}

void CharacterItemManager::addToBag(Item * e) {
    bag.addItem(e);
}

void CharacterItemManager::removeFromBag(Item * e) {
    bag.removeItem(e);
}

map<characterStats, int> CharacterItemManager::getInventoryStats() {
    return inventoryStats;
}

void CharacterItemManager::appendStatsInMap(map<characterStats, int> localMap,
        map<characterStats, int> &localContainer) {
    for (std::map<characterStats, int>::iterator it = localMap.begin(); it != localMap.end(); ++it) {
        if (localMap.find(it->first) == localMap.end()) {
            localContainer[it->first] = it->second;  //not found, generates entry
        }
        else {
            localContainer[it->first] += it->second;  //found, adds
        }
    }
}

void CharacterItemManager::calculateInventoryStats() {
    map<characterStats, int> localMap;
    map<characterStats, int> localContainer;

    if (equippedHelmet != nullptr) {
        localMap = equippedHelmet->getEquipmentStats();
        appendStatsInMap(localMap, localContainer);
    }
    if (equippedArmor != nullptr) {
        localMap = equippedArmor->getEquipmentStats();
        appendStatsInMap(localMap, localContainer);
    }
    if (equippedShield != nullptr) {
        localMap = equippedShield->getEquipmentStats();
        appendStatsInMap(localMap, localContainer);
    }
    if (equippedBracers != nullptr) {
        localMap = equippedBracers->getEquipmentStats();
        appendStatsInMap(localMap, localContainer);
    }
    if (equippedRing != nullptr) {
        localMap = equippedRing->getEquipmentStats();
        appendStatsInMap(localMap, localContainer);
    }
    if (equippedBelt != nullptr) {
        localMap = equippedBelt->getEquipmentStats();
        appendStatsInMap(localMap, localContainer);
    }
    if (equippedBoots != nullptr) {
        localMap = equippedBoots->getEquipmentStats();
        appendStatsInMap(localMap, localContainer);
    }
    if (equippedWeapon != nullptr) {
        localMap = equippedWeapon->getEquipmentStats();
        appendStatsInMap(localMap, localContainer);
    }
    inventoryStats = localContainer;
}

string CharacterItemManager::displayInventoryStats() {
    stringstream ss;

    ss << "Displaying statistics added by character's Inventory!" << endl
            << "=====================================================" << endl << endl;

    for (std::map<characterStats, int>::iterator it = inventoryStats.begin(); it != inventoryStats.end(); ++it) {

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
