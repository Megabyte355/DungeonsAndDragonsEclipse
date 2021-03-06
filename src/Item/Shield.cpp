/*
 * Shield.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "Shield.h"

using namespace std;

Shield::Shield() :
        Equipment() {
    name = "Generic Shield";
    armorBonus = 3;
    strBonus = 2;
    shieldType = "Light";
    possibleEnchants.push_back(characterStats::ARMOR);
    enchantEquipment();
    insertStatistic(characterStats::ARMOR, armorBonus);
    insertStatistic(characterStats::STRENGTH, strBonus);

    if (textureName.empty()) {
        textureName = "assets/shield.png";
    }
}

Shield::Shield(string pname, int pvalue, int pweight, int parmorBonus, int pstrBonus, string pshieldType,
        string ptextureName) :
        Equipment(pname, pvalue, pweight, ptextureName) {
    armorBonus = parmorBonus;
    strBonus = pstrBonus;
    shieldType = pshieldType;
    possibleEnchants.push_back(characterStats::ARMOR);
    enchantEquipment();
    insertStatistic(characterStats::ARMOR, armorBonus);
    insertStatistic(characterStats::STRENGTH, strBonus);

    if (textureName.empty()) {
        textureName = "assets/shield.png";
    }
}

Shield::Shield(int charLevel, bool isRandom, string ptextureName) :
        Equipment(charLevel, isRandom, ptextureName) {
    name = "Randomly Generated Shield";
    armorBonus = rand() % charLevel;
    strBonus = rand() % charLevel;
    shieldType = "Random Type";
    possibleEnchants.push_back(characterStats::ARMOR);
    enchantEquipment();
    insertStatistic(characterStats::ARMOR, armorBonus);
    insertStatistic(characterStats::STRENGTH, strBonus);
    generateRandomStats(charLevel);

    if (textureName.empty()) {
        textureName = "assets/shield.png";
    }
}

Shield::~Shield() {
}

string Shield::toString() {
    stringstream ss;
    ss << Equipment::toString();
    ss << "Shield Type: " << shieldType << endl;
    return ss.str();
}

string Shield::getClassName() {
    return "Shield";
}
