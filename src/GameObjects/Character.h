/*
 * File:   Character.h
 * Author: Tiffany Ip 9341943
 *
 * Created on October 17, 2013, 3:02 PM
 */

#ifndef CHARACTER_H
#define	CHARACTER_H
#include "Observable.h"
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

struct item
{    //placeholder for the item system
    string name;
};

class Character: public Observable
{
    protected:
        string charName;
        int level;
        int hitPoints;
        int armorClass;
        vector<int> rolls; // for the dice rolls for ability scores

        //ability scores
        int str;
        int dex;
        int con;
        int intel;
        int wis;
        int cha;

        //others
        int baseAttack;
        int damageBonus;

        item helmet, ring1, ring2, weapon, shield, armor, belt, boots;

    public:
        Character();
        Character(string charName, int level);

        //setters
        void setName(string charName);
        void setStartingLevel(int level);
        void setHP();
        void setAC();
        void setStr(int str, int strMod);
        void setDex(int dex, int dexMod);
        void setCon(int con, int conMod);
        void setInt(int intel, int intMod);
        void setWis(int wis, int wisMod);
        void setCha(int cha, int chaMod);
        void setBaseAttack();
        void setDamageBonus();
        void generateAbilityScores();
        void chooseAbilityScores();

        //getters
        string getName();
        int getLevel();
        int getHP();
        int getAC();
        int getStr();
        int getDex();
        int getCon();
        int getInt();
        int getWis();
        int getCha();
        int getBaseAttack();
        int getHitDie();
        int getBaseAttackBonus();
        int getDamageBonus();
        int getAbilityModifier(double aScore);
};

#endif	/* CHARACTER_H */
