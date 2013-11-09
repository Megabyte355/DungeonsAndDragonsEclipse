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
#include "Recordable.h"
#include <sstream>
using namespace std;

struct item
{    //placeholder for the item system
        string name;
};

class Character: public virtual Observable, public virtual Recordable
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
        virtual void setName(string charName);
        virtual void setStartingLevel(int level);
        virtual void setHP();
        virtual void setAC();
        virtual void setStr(int str, int strMod);
        virtual void setDex(int dex, int dexMod);
        virtual void setCon(int con, int conMod);
        virtual void setInt(int intel, int intMod);
        virtual void setWis(int wis, int wisMod);
        virtual void setCha(int cha, int chaMod);
        virtual void setBaseAttack();
        virtual void setDamageBonus();
        virtual void generateAbilityScores();
        virtual void chooseAbilityScores();

        //getters
        virtual string getName();
        virtual int getLevel();
        virtual int getHP();
        virtual int getAC();
        virtual int getStr();
        virtual int getDex();
        virtual int getCon();
        virtual int getInt();
        virtual int getWis();
        virtual int getCha();
        virtual int getBaseAttack();
        virtual int getHitDie();
        virtual int getBaseAttackBonus();
        virtual int getDamageBonus();
        virtual int getAbilityModifier(double aScore);

        std::string toFileString();
        void fromFileString(std::string);
};

#endif	/* CHARACTER_H */
