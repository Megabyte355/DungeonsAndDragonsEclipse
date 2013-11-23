/*
 * Boots.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "Boots.h"

Boots::Boots():Equipment() {
	name = "Generic Boots";
	armorBonus = 3;
	dexBonus = 2;
	possibleEnchants.push_back(characterStats::ARMOR);
	possibleEnchants.push_back(characterStats::DEXTERITY);
    enchantEquipment();
	insertStatistic(characterStats::ARMOR, armorBonus);
	insertStatistic(characterStats::DEXTERITY, dexBonus);
}

Boots::Boots(string pname, int pvalue, int pweight, int parmorBonus, int pdexBonus):Equipment(pname, pvalue, pweight){
	possibleEnchants.push_back(characterStats::ARMOR);
	possibleEnchants.push_back(characterStats::DEXTERITY);
    enchantEquipment();
	insertStatistic(characterStats::ARMOR, parmorBonus);
	insertStatistic(characterStats::DEXTERITY, pdexBonus);
}

Boots::~Boots() {
}

string Boots::toString(){
	stringstream ss;
	ss << Equipment::toString();
	return ss.str();
}

string Boots::getClassName(){
	return "Boots";
}

