/*
 * Armor.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "Armor.h"

Armor::Armor() :
        Equipment() {
    name = "Generic Armor";
    armorBonus = 3;
    possibleEnchants.push_back(characterStats::ARMOR);
    enchantEquipment();
    armorType = "Light";
    insertStatistic(characterStats::ARMOR, armorBonus);

    if (textureName.empty()) {
        textureName = "assets/armor.png";
    }
}

Armor::Armor(string pname, int pvalue, int pweight, string parmorType, int parmorBonus, string ptextureName) :
        Equipment(pname, pvalue, pweight, ptextureName) {
    name = pname;
    armorType = parmorType;
    armorBonus = parmorBonus;
    possibleEnchants.push_back(characterStats::ARMOR);
    enchantEquipment();
    insertStatistic(characterStats::ARMOR, parmorBonus);

    if (textureName.empty()) {
        textureName = "assets/armor.png";
    }

}

Armor::Armor(int charLevel, bool isRandom, string ptextureName) :
        Equipment(charLevel, isRandom, ptextureName) {
    name = "Randomly Generated Armor";
    armorBonus = rand() % charLevel;
    armorType = "Light";
    possibleEnchants.push_back(characterStats::ARMOR);
    enchantEquipment();
    insertStatistic(characterStats::ARMOR, armorBonus);
    generateRandomStats(charLevel);

    if (textureName.empty()) {
        textureName = "assets/armor.png";
    }
}

Armor::~Armor() {
}

string Armor::toString() {
    stringstream ss;
    ss << Equipment::toString();
    ss << "Armor Type: " << armorType << endl;
    return ss.str();
}

string Armor::getClassName() {
    return "Armor";
}

