/*
 * File:   Fighter.cpp
 * Author: Tiffany Ip 9341943
 * Created on October 19, 2013, 6:06PM
 */
#include "Fighter.h"
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

Fighter::Fighter(std::string name, int level) :
        Character(name, level)
{
    Fighter::setHP();
    setBaseAttack();
    setDamageBonus();
}

//overriden sets
void Fighter::setHP()
{
    int conMod = getAbilityModifier(getCon());
    int random = (rand() % getHitDie()) + 1; //plus 1 in case the mod gives a value of 0 so we at least have 1 HP
    hitPoints = random + conMod * getLevel();
    notify();
}
void Fighter::setAC()
{
    armorClass = 10 + getAbilityModifier(getDex());
    notify();
}
void Fighter::setStr(int strScore, int strMod)
{
    str = strScore + strMod;
    Fighter::setBaseAttack(); //sets the new base attack
    Fighter::setDamageBonus(); //sets the new damage bonus
    notify();
}
void Fighter::setDex(int dexScore, int dexMod)
{
    dex = dexScore + dexMod;
    notify();
}
void Fighter::setCon(int conScore, int conMod)
{
    con = conScore + conMod;
    notify();
}
void Fighter::setInt(int intScore, int intMod)
{
    intel = intScore + intMod;
    notify();
}
void Fighter::setWis(int wisScore, int wisMod)
{
    wis = wisScore + wisMod;
    notify();
}
void Fighter::setCha(int chaScore, int chaMod)
{
    cha = chaScore + chaMod;
    notify();
}
void Fighter::setBaseAttack()
{
    baseAttack = getBaseAttackBonus() + getAbilityModifier(getStr());
    notify();
}
void Fighter::setDamageBonus()
{
    damageBonus = getAbilityModifier(getStr());
    notify();
}

int Fighter::getHitDie()
{
    return hitDie;
}

int Fighter::getBaseAttackBonus()
{
    return Fighter::getLevel();
}

void Fighter::printChar()
{
    cout << endl << "This is your new character: " << endl;
    cout << "Name: " << getName() << endl;
    cout << "Level: " << getLevel() << endl;
    cout << "HP: " << getHP() << endl;
    cout << "AC: " << getAC() << endl << endl;
    cout << "Your ability scores: " << endl;
    cout << "Strength " << getStr() << endl;
    cout << "Dexterity " << getDex() << endl;
    cout << "Constitution " << getCon() << endl;
    cout << "Intelligence " << getInt() << endl;
    cout << "Wisdom " << getWis() << endl;
    cout << "Charisma " << getCha() << endl << endl;
    cout << "Your attack stats: " << endl;
    cout << "Base Attack " << getBaseAttack() << endl;
    cout << "Damage Bonus " << getDamageBonus() << endl;
    cout << endl;
}
