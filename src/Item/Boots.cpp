/*
 * Boots.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "Boots.h"

Boots::Boots() :
        Equipment() {
    name = "Generic Boots";
    armorBonus = 3;
    dexBonus = 2;
    possibleEnchants.push_back(characterStats::ARMOR);
    possibleEnchants.push_back(characterStats::DEXTERITY);
    enchantEquipment();
    insertStatistic(characterStats::ARMOR, armorBonus);
    insertStatistic(characterStats::DEXTERITY, dexBonus);

    if (textureName.empty()) {
        textureName = "assets/boots.png";
    }
}

Boots::Boots(string pname, int pvalue, int pweight, int parmorBonus, int pdexBonus, string ptextureName) :
        Equipment(pname, pvalue, pweight, ptextureName) {
    armorBonus = parmorBonus;
    dexBonus = pdexBonus;
    possibleEnchants.push_back(characterStats::ARMOR);
    possibleEnchants.push_back(characterStats::DEXTERITY);
    enchantEquipment();
    insertStatistic(characterStats::ARMOR, armorBonus);
    insertStatistic(characterStats::DEXTERITY, dexBonus);

    if (textureName.empty()) {
        textureName = "assets/boots.png";
    }
}

Boots::Boots(int charLevel, bool isRandom, string ptextureName) :
        Equipment(charLevel, isRandom, ptextureName) {
    name = "Randomly Generated Boots";
    armorBonus = rand() % charLevel;
    dexBonus = rand() % charLevel;
    possibleEnchants.push_back(characterStats::ARMOR);
    possibleEnchants.push_back(characterStats::DEXTERITY);
    enchantEquipment();
    insertStatistic(characterStats::ARMOR, armorBonus);
    insertStatistic(characterStats::DEXTERITY, dexBonus);
    generateRandomStats(charLevel);

    if (textureName.empty()) {
        textureName = "assets/boots.png";
    }
}

Boots::~Boots() {
}

string Boots::toString() {
    stringstream ss;
    ss << Equipment::toString();
    return ss.str();
}

string Boots::getClassName() {
    return "Boots";
}

