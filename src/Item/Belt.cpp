/*
 * Belt.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "Belt.h"

Belt::Belt():Equipment() {
	name = "Generic Belt";
	consitutionBonus = 3;
	possibleEnchants.push_back(characterStats::CONSTITUTION);
	possibleEnchants.push_back(characterStats::STRENGTH);
    enchantEquipment();
	insertStatistic(characterStats::CONSTITUTION, consitutionBonus);
}

Belt::Belt(string pname, int pvalue, int pweight, int pconsitutionBonus):Equipment(pname, pvalue, pweight){
	possibleEnchants.push_back(characterStats::STRENGTH);
	possibleEnchants.push_back(characterStats::CONSTITUTION);
    enchantEquipment();
	insertStatistic(characterStats::CONSTITUTION, pconsitutionBonus);
}

Belt::Belt(int charLevel, bool isRandom):Equipment(charLevel, isRandom){
    name = "Randomly Generated Belt";
    consitutionBonus = rand() % charLevel;
    possibleEnchants.push_back(characterStats::CONSTITUTION);
    possibleEnchants.push_back(characterStats::STRENGTH);
    enchantEquipment();
    insertStatistic(characterStats::CONSTITUTION, consitutionBonus);
    generateRandomStats(charLevel);
}

Belt::~Belt() {
}

string Belt::toString(){
	stringstream ss;
	ss << Equipment::toString();
	return ss.str();
}

string Belt::getClassName(){
	return "Belt";
}
