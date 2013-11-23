/*
 * Equipment.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "Equipment.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

string getStatsEnumString( int enumVal )
{
	string characterStatsMapping[9] = {"STRENGTH", "CONSTITUTION", "DEXTERITY", "INTELLIGENCE", "WISDOM", "CHARISMA", "ARMOR", "ATTACK", "DAMAGE"};
	return characterStatsMapping[enumVal];
}

Equipment::Equipment():Item() {
    enchantLevel = 0;
    name = "Generic Equipment";
	value = 0;
	weight = 0;
}

Equipment::Equipment(string pname, int pvalue, int pweight) {
    enchantLevel = 0;
    name = pname;
    value = pvalue;
    weight = pweight;
}
Equipment::~Equipment() {
}

bool Equipment::isEqual(Equipment* e) {
    return (enchantLevel == e->enchantLevel) && (enchantType == e->enchantType) && (name == e->name)
            && compareEquipmentStats(equipmentStats, e->equipmentStats) && (possibleEnchants == e->possibleEnchants);
}

int Equipment::getEnchantLevel() {
    return enchantLevel;
}

characterStats Equipment::getEnchantType() {
    return enchantType;
}

StatPair Equipment::getEquipmentStats() {
    return equipmentStats;
}

string Equipment::getName() {
    return name;
}

void Equipment::enchantEquipment() {
    enchantLevel = rand() % 5 +1; //Generates random from 1-5
    enchantType = possibleEnchants[rand() % possibleEnchants.size()];
	this->insertStatistic(enchantType, enchantLevel);
}

bool Equipment::compareEquipmentStats(const map<characterStats,int>& l, const map<characterStats,int>& r) {
// same types, proceed to compare maps here

    if (l.size() != r.size())
        return false;  // differing sizes, they are not the same

	map<characterStats,int>::const_iterator i, j;
    for (i = l.begin(), j = r.begin(); i != l.end(); ++i, ++j) {
        if (*i != *j)
            return false;
    }
    return true;
}

void Equipment::insertStatistic(characterStats stat, int value) {

    if (equipmentStats.find(stat) == equipmentStats.end()) {
		equipmentStats[stat] = value;  //not found, generates entry
    }
    else {
        equipmentStats[stat] += value;  //found, adds
    }
}

string Equipment::toString(){

	stringstream ss;

	ss << name << "   (+" << enchantLevel << " " << getStatsEnumString(enchantType) + ")" << endl; // Sword (+5 Attack)
	ss << "---------------------" << endl;
	ss << "Equipment type: " << this->getClassName() << endl; // Type: Weapon
	for(std::map<characterStats, int>::iterator it = equipmentStats.begin(); it != equipmentStats.end(); ++it)
	{
		int temp = it->second;

		ss << getStatsEnumString(it->first) << ": " << it->second << endl; // Strength: 5
	}
	ss << "Weight: " << weight << endl;
	ss << "Value: " << value << endl;

	return ss.str();
}

string Equipment::getClassName(){
	return "Equipment";
}
