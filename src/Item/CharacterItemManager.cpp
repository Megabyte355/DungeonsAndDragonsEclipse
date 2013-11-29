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

}

CharacterItemManager::~CharacterItemManager() {
    delete helmet;
    delete armor;
    delete shield;
    delete bracers;
    delete ring;
    delete belt;
    delete boots;
    delete weapon;

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
    *equipped = e; //Equips item

//    COMMENTED BEFORE TEST
//    if (isItemInBag(e)) {
//        //Must check what type of equipment is being passed.
//        switch (e->getClassName()) {
//            case "Helmet":
//                if (helmet != nullptr) {
//                    bag.addItem(helmet);
//                }
//                helmet = e;
//                break;
//            case "Armor":
//                if (armor != nullptr) {
//                    bag.addItem(armor);
//                }
//                armor = e;
//                break;
//            case "Shield":
//                if (shield != nullptr) {
//                    bag.addItem(shield);
//                }
//                shield = e;
//                break;
//            case "Bracers":
//                if (bracers != nullptr) {
//                    bag.addItem(bracers);
//                }
//                bracers = e;
//                break;
//            case "Ring":
//                if (ring != nullptr) {
//                    bag.addItem(ring);
//                }
//                ring = e;
//                break;
//            case "Belt":
//                if (belt != nullptr) {
//                    bag.addItem(belt);
//                }
//                belt = e;
//                break;
//            case "Boots":
//                if (boots != nullptr) {
//                    bag.addItem(boots);
//                }
//                boots = e;
//                break;
//            case "Weapon":
//                if (weapon != nullptr) {
//                    bag.addItem(weapon);
//                }
//                weapon = e;
//                break;
//        }
//        cout << e->getClassName() << " has been equipped" << endl;
//        bag.removeItem(e);
//    }
}

Equipment ** CharacterItemManager::getEquipmentSlot(Equipment * e) {
    if (dynamic_cast<Helmet *>(e) != nullptr)
        return (Equipment **)&helmet;
    else if (dynamic_cast<Armor *>(e) != nullptr)
        return (Equipment **)&armor;
    else if (dynamic_cast<Shield *>(e) != nullptr)
        return (Equipment **)&shield;
    else if (dynamic_cast<Bracers *>(e) != nullptr)
        return (Equipment **)&bracers;
    else if (dynamic_cast<Ring *>(e) != nullptr)
        return (Equipment **)&ring;
    else if (dynamic_cast<Belt *>(e) != nullptr)
        return (Equipment **)&belt;
    else if (dynamic_cast<Boots *>(e) != nullptr)
        return (Equipment **)&boots;
    else if (dynamic_cast<Weapon *>(e) != nullptr)
        return (Equipment **)&weapon;
    else
        return nullptr;
}

bool CharacterItemManager::isItemEquipped(Equipment * e) {
    return getEquipmentSlot(e) != nullptr;
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

void CharacterItemManager::appendStatsInMap(map<characterStats, int> localMap, map<characterStats, int> &localContainer) {
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


    if (helmet != nullptr) {
        localMap = helmet->getEquipmentStats();
        appendStatsInMap(localMap, localContainer);
    }
    if (armor != nullptr) {
        localMap = armor->getEquipmentStats();
        appendStatsInMap(localMap, localContainer);
    }
    if (shield != nullptr) {
        localMap = shield->getEquipmentStats();
       appendStatsInMap(localMap, localContainer);
    }
    if (bracers != nullptr) {
        localMap = bracers->getEquipmentStats();
        appendStatsInMap(localMap, localContainer);
    }
    if (ring != nullptr) {
        localMap = ring->getEquipmentStats();
        appendStatsInMap(localMap, localContainer);
    }
    if (belt != nullptr) {
        localMap = belt->getEquipmentStats();
        appendStatsInMap(localMap, localContainer);
    }
    if (boots != nullptr) {
        localMap = boots->getEquipmentStats();
        appendStatsInMap(localMap, localContainer);
    }
    if (weapon != nullptr) {
        localMap = weapon->getEquipmentStats();
        appendStatsInMap(localMap, localContainer);
    }
    inventoryStats = localContainer;
}

int CharacterItemManager::getInventorySpecificStat(characterStats stat)
{
    return (inventoryStats.find(stat) == inventoryStats.end()) ? 0 : inventoryStats[stat];
}

int CharacterItemManager::getInventoryStrength()
{
    return getInventorySpecificStat(characterStats::STRENGTH);
}

int CharacterItemManager::getInventoryConstitution()
{
    return getInventorySpecificStat(characterStats::CONSTITUTION);
}

int CharacterItemManager::getInventoryDexterity()
{
    return getInventorySpecificStat(characterStats::DEXTERITY);
}

int CharacterItemManager::getInventoryIntelligence()
{
    return getInventorySpecificStat(characterStats::INTELLIGENCE);
}

int CharacterItemManager::getInventoryWisdom()
{
    return getInventorySpecificStat(characterStats::WISDOM);
}

int CharacterItemManager::getInventoryCharisma()
{
    return getInventorySpecificStat(characterStats::CHARISMA);
}

int CharacterItemManager::getInventoryArmor()
{
    return getInventorySpecificStat(characterStats::ARMOR);
}

int CharacterItemManager::getInventoryAttack()
{
    return getInventorySpecificStat(characterStats::ATTACK);
}

int CharacterItemManager::getInventoryDamage()
{
    return getInventorySpecificStat(characterStats::DAMAGE);
}

string CharacterItemManager::displayInventoryStats() {
    stringstream ss;

    ss << "Displaying statistics added by character's Inventory!" << endl << "==============================" << endl
            << endl;

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
