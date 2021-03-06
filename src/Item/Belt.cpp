/*
 * Belt.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "Belt.h"

Belt::Belt() :
        Equipment() {
    name = "Generic Belt";
    consitutionBonus = 3;
    possibleEnchants.push_back(characterStats::CONSTITUTION);
    possibleEnchants.push_back(characterStats::STRENGTH);
    enchantEquipment();
    insertStatistic(characterStats::CONSTITUTION, consitutionBonus);
    if (textureName.empty()) {
        textureName = "assets/belt.png";
    }
}

Belt::Belt(string pname, int pvalue, int pweight, int pconsitutionBonus, string ptextureName) :
        Equipment(pname, pvalue, pweight, ptextureName) {
    consitutionBonus = pconsitutionBonus;
    possibleEnchants.push_back(characterStats::STRENGTH);
    possibleEnchants.push_back(characterStats::CONSTITUTION);
    enchantEquipment();
    insertStatistic(characterStats::CONSTITUTION, consitutionBonus);

    if (textureName.empty()) {
        textureName = "assets/belt.png";
    }
}

Belt::Belt(int charLevel, bool isRandom, string ptextureName) :
        Equipment(charLevel, isRandom, ptextureName) {
    name = "Randomly Generated Belt";
    consitutionBonus = rand() % charLevel;
    possibleEnchants.push_back(characterStats::CONSTITUTION);
    possibleEnchants.push_back(characterStats::STRENGTH);
    enchantEquipment();
    insertStatistic(characterStats::CONSTITUTION, consitutionBonus);
    generateRandomStats(charLevel);

    if (textureName.empty()) {
        textureName = "assets/belt.png";
    }
}

Belt::~Belt() {
}

string Belt::toString() {
    stringstream ss;
    ss << Equipment::toString();
    return ss.str();
}

string Belt::getClassName() {
    return "Belt";
}
