/*
 * Bracers.cpp
 *
 *  Created on: Nov 23, 2013
 *      Author: Kevin
 */

#include "Bracers.h"

Bracers::Bracers() :
        Equipment() {
    name = "Generic Bracers";
    possibleEnchants.push_back(characterStats::ARMOR);
    possibleEnchants.push_back(characterStats::STRENGTH);
    enchantEquipment();

//    if (textureName.empty()) {
//        textureName = "assets/bracers.png";
//    }
}

Bracers::Bracers(string pname, int pvalue, int pweight, string ptextureName) :
        Equipment(pname, pvalue, pweight, ptextureName) {
    name = pname;
    possibleEnchants.push_back(characterStats::ARMOR);
    possibleEnchants.push_back(characterStats::STRENGTH);
    enchantEquipment();

//    if (textureName.empty()) {
//        textureName = "assets/bracers.png";
//    }
}

Bracers::Bracers(int charLevel, bool isRandom, string ptextureName) :
        Equipment(charLevel, isRandom, ptextureName) {
    name = "Randomly Generated Bracers";
    possibleEnchants.push_back(characterStats::ARMOR);
    possibleEnchants.push_back(characterStats::STRENGTH);
    enchantEquipment();
    generateRandomStats(charLevel);

//    if (textureName.empty()) {
//        textureName = "assets/bracers.png";
//    }
}

Bracers::~Bracers() {
}

string Bracers::toString() {
    stringstream ss;
    ss << Equipment::toString();
    return ss.str();
}

string Bracers::getClassName() {
    return "Bracers";
}

