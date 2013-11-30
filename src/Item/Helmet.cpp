/*
 * Helmet.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "Helmet.h"

using namespace std;

Helmet::Helmet() :
        Equipment() {
    name = "Generic Helmet";
    armorBonus = 3;
    possibleEnchants.push_back(characterStats::ARMOR);
    possibleEnchants.push_back(characterStats::INTELLIGENCE);
    possibleEnchants.push_back(characterStats::WISDOM);
    enchantEquipment();
    insertStatistic(characterStats::ARMOR, armorBonus);

    if (textureName.empty()) {
        textureName = "assets/helmet.png";
    }
}

Helmet::Helmet(string pname, int pvalue, int pweight, int parmorBonus, string ptextureName) :
        Equipment(pname, pvalue, pweight, ptextureName) {
    armorBonus = parmorBonus;
    possibleEnchants.push_back(characterStats::ARMOR);
    possibleEnchants.push_back(characterStats::INTELLIGENCE);
    possibleEnchants.push_back(characterStats::WISDOM);
    enchantEquipment();
    insertStatistic(characterStats::ARMOR, armorBonus);

    if (textureName.empty()) {
        textureName = "assets/helmet.png";
    }
}

Helmet::Helmet(int charLevel, bool isRandom, string ptextureName) :
        Equipment(charLevel, isRandom, ptextureName) {
    name = "Randomly Generated Helmet";
    armorBonus = rand() % charLevel;
    possibleEnchants.push_back(characterStats::ARMOR);
    enchantEquipment();
    insertStatistic(characterStats::ARMOR, armorBonus);
    generateRandomStats(charLevel);

    if (textureName.empty()) {
        textureName = "assets/helmet.png";
    }
}

Helmet::~Helmet() {
}

string Helmet::toString() {
    stringstream ss;
    ss << Equipment::toString();
    return ss.str();
}

string Helmet::getClassName() {
    return "Helmet";
}
