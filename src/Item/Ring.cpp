/*
 * Ring.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "Ring.h"

Ring::Ring():Equipment() {
	name = "Generic Ring";
	charismanBonus = 1;
	wisdomBonus = 1;
	intBonus = 1;
	possibleEnchants.push_back(characterStats::ARMOR);
	possibleEnchants.push_back(characterStats::STRENGTH);
	possibleEnchants.push_back(characterStats::CONSTITUTION);
	possibleEnchants.push_back(characterStats::WISDOM);
	possibleEnchants.push_back(characterStats::CHARISMA);
	enchantEquipment();
	insertStatistic(characterStats::CHARISMA, charismanBonus);
	insertStatistic(characterStats::WISDOM, wisdomBonus);
	insertStatistic(characterStats::INTELLIGENCE, intBonus);

}

Ring::Ring(string pname, int pvalue, int pweight, int pcharismanBonus, int pwisdomBonus, int pintBonus):Equipment(pname, pvalue, pweight){
	possibleEnchants.push_back(characterStats::ARMOR);
	possibleEnchants.push_back(characterStats::STRENGTH);
	possibleEnchants.push_back(characterStats::CONSTITUTION);
	possibleEnchants.push_back(characterStats::WISDOM);
	possibleEnchants.push_back(characterStats::CHARISMA);
	enchantEquipment();
	insertStatistic(characterStats::CHARISMA, pcharismanBonus);
	insertStatistic(characterStats::WISDOM, pwisdomBonus);
	insertStatistic(characterStats::INTELLIGENCE, pintBonus);
}

Ring::Ring(int charLevel, bool isRandom):Equipment(charLevel, isRandom){
    name = "Randomly Generated Ring";
    charismanBonus = rand() % charLevel;
    wisdomBonus = rand() % charLevel;
    intBonus = rand() % charLevel;
    possibleEnchants.push_back(characterStats::ARMOR);
    possibleEnchants.push_back(characterStats::STRENGTH);
    possibleEnchants.push_back(characterStats::CONSTITUTION);
    possibleEnchants.push_back(characterStats::WISDOM);
    possibleEnchants.push_back(characterStats::CHARISMA);
    enchantEquipment();
    insertStatistic(characterStats::CHARISMA, charismanBonus);
    insertStatistic(characterStats::WISDOM, wisdomBonus);
    insertStatistic(characterStats::INTELLIGENCE, intBonus);
    generateRandomStats(charLevel);
}

Ring::~Ring() {
}

string Ring::toString(){
	stringstream ss;
	ss << Equipment::toString();
	return ss.str();
}

string Ring::getClassName(){
	return "Ring";
}
