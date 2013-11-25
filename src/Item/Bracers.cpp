/*
 * Bracers.cpp
 *
 *  Created on: Nov 23, 2013
 *      Author: Kevin
 */

#include "Bracers.h"

Bracers::Bracers():Equipment() {
    name = "Generic Bracers";
    possibleEnchants.push_back(characterStats::ARMOR);
    possibleEnchants.push_back(characterStats::STRENGTH);
    enchantEquipment();
}

Bracers::Bracers(string pname, int pvalue, int pweight):Equipment(pname, pvalue, pweight){
    name = pname;
    possibleEnchants.push_back(characterStats::ARMOR);
    possibleEnchants.push_back(characterStats::STRENGTH);
    enchantEquipment();
}

Bracers::Bracers(int charLevel, bool isRandom):Equipment(charLevel, isRandom){
    name = "Randomly Generated Bracers";
    possibleEnchants.push_back(characterStats::ARMOR);
    possibleEnchants.push_back(characterStats::STRENGTH);
    enchantEquipment();
    generateRandomStats(charLevel);
}

Bracers::~Bracers() {
}

string Bracers::toString(){
    stringstream ss;
    ss << Equipment::toString();
    return ss.str();
}

string Bracers::getClassName(){
    return "Bracers";
}


