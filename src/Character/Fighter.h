/*
 * File:   Fighter.h
 * Author: Tiffany Ip 9341943
 *
 * Created on October 19, 2013, 6:05 PM
 */

#ifndef FIGHTER_H
#define	FIGHTER_H
#include "Character.h"
#include <string>

using namespace std;

class Fighter: public Character
{
    static const int hitDie = 10;

    public:
        Fighter(std::string name, int level);
        void setHP(); //overrides the Character setHP()
        void setAC();
        void setStr(int str, int strMod);
        void setDex(int dex, int dexMod);
        void setCon(int con, int conMod);
        void setInt(int intel, int intMod);
        void setWis(int wis, int wisMod);
        void setCha(int cha, int chaMod);
        void setBaseAttack();
        void setDamageBonus();
        int getHitDie();
        int getBaseAttackBonus();
        void printChar();
};
#endif	/* FIGHTER_H */

