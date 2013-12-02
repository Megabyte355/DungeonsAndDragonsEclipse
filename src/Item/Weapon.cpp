/*
 * Weapon.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "Weapon.h"

Weapon::Weapon() :
        Equipment() {
    name = "Generic Warrior Sword";
    weaponType = "Sword";
    range = 1; //WE ASSUME SWORD RANGE IS 1 SQUARE
    attackBonus = 8;
    damageBonus = 8;
    possibleEnchants.push_back(characterStats::ATTACK);
    possibleEnchants.push_back(characterStats::DAMAGE);
    enchantEquipment();
    insertStatistic(characterStats::ATTACK, attackBonus);
    insertStatistic(characterStats::DAMAGE, damageBonus);

    if (textureName.empty()) {
        textureName = "assets/sword.png";
    }

}

Weapon::Weapon(string pname, int pvalue, int pweight, int pattackBonus, int pdamageBonus, string pweaponType,
        string ptextureName) :
        Equipment(pname, pvalue, pweight, ptextureName) {
    weaponType = pweaponType;
    if (weaponType == "Sword") {
        range = 1;
        if (textureName.empty()) {
            textureName = "assets/sword.png";
        }
    }
    else if (weaponType == "Bow") {
        range = 6;
        if (textureName.empty()) {
            textureName = "assets/bow.png";
        }
    }
    attackBonus = pattackBonus;
    damageBonus = pdamageBonus;
    possibleEnchants.push_back(characterStats::ATTACK);
    possibleEnchants.push_back(characterStats::DAMAGE);
    enchantEquipment();
    insertStatistic(characterStats::ATTACK, attackBonus);
    insertStatistic(characterStats::DAMAGE, damageBonus);
}

Weapon::Weapon(int charLevel, bool isRandom, string pweaponType, string ptextureName) :
        Equipment(charLevel, isRandom, ptextureName) {
    name = "Randomly Generated Weapon";
    weaponType = pweaponType;
    if (weaponType == "Sword") {
        range = 1;
        if (textureName.empty()) {
            textureName = "assets/sword.png";
        }
    }
    else if (weaponType == "Bow") {
        range = 6;
        if (textureName.empty()) {
            textureName = "assets/bow.png";
        }
    }
    attackBonus = (rand() % charLevel) + 8;
    damageBonus = (rand() % charLevel) + 8;
    possibleEnchants.push_back(characterStats::ATTACK);
    possibleEnchants.push_back(characterStats::DAMAGE);
    enchantEquipment();
    insertStatistic(characterStats::ATTACK, attackBonus);
    insertStatistic(characterStats::DAMAGE, damageBonus);
    generateRandomStats(charLevel);

    if (ptextureName.empty()) {
        textureName = "assets/sword.png";
    }
}

Weapon::~Weapon() {
}

int Weapon::getAttackBonus() {
    return attackBonus;
}

int Weapon::getDamageBonus() {
    return damageBonus;
}

string Weapon::toString() {
    stringstream ss;
    ss << Equipment::toString();
    ss << "Weapon Type: " << weaponType << endl;
    return ss.str();
}

string Weapon::getClassName() {
    return "Weapon";
}
