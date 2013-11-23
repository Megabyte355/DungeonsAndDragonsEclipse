/*
 * Armor.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "Armor.h"


Armor::Armor():Equipment() {
    name = "Generic Armor";
	armorBonus = 3;
    possibleEnchants.push_back(characterStats::ARMOR);
    enchantEquipment();
	armorType = "Light";
	insertStatistic(characterStats::ARMOR, armorBonus);
}

Armor::Armor(string pname, int pvalue, int pweight, string parmorType, int parmorBonus):Equipment(pname, pvalue, pweight){
	name = pname;
    possibleEnchants.push_back(characterStats::ARMOR);
    enchantEquipment();
	armorType = parmorType;
	insertStatistic(characterStats::ARMOR, parmorBonus);
}

Armor::~Armor() {
}

string Armor::toString(){
	stringstream ss;
	ss << Equipment::toString();
	ss << "Armor Type: " << armorType << endl;
	return ss.str();
}

string Armor::getClassName(){
	return "Armor";
}

