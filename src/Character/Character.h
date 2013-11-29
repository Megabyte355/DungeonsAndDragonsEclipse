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
using namespace std;

class Character : public Observable {
protected:
    string charName;
    string charType;
    
    int level;
    int hitPoints;
    int armorClass;
    int speed;
    vector<int> rolls; // for the dice rolls for ability scores
    
    //ability scores
    int str;
    int dex;
    int con;
    int intel;
    int wis;
    int cha;
    
    //ability modifiers
    int strMod;
    int dexMod;
    int conMod;
    int intMod;
    int wisMod;
    int chaMod;
    
    //others
    int baseAttackBonus1,baseAttackBonus2, baseAttackBonus3, baseAttackBonus4;
    
public:
    Character();
    Character(string name, int level);
    Character(int level);
    
    //setters
    void setName(string name);
    void setStartingLevel(int level);
    void setType(string charType);
    
    virtual void setHP()=0;   
    virtual void setSpeed()=0;
    void setAC();
    void setStr(int str);
    void setDex(int dex);
    void setCon(int con);
    void setInt(int intel);
    void setWis(int wis);
    void setCha(int cha);
    
    void setStrMod(int str);
    void setDexMod(int dex);
    void setConMod(int con);
    void setIntMod(int intel);
    void setWisMod(int wis);
    void setChaMod(int cha);
    
    void setAttackBonuses();
    void setBaseAttackBonus1();
    void setBaseAttackBonus2();
    void setBaseAttackBonus3();
    void setBaseAttackBonus4();
    
    void generateAbilityScores();
    void chooseAbilityScores();
    
    //getters
    string getName();
    int getLevel();
    int getHP();
    virtual int getAC()=0;
    int getSpeed();
    
    int getStr();
    int getDex();
    int getCon();
    int getInt();
    int getWis();
    int getCha();
    
    int getStrMod();
    int getDexMod();
    int getConMod();
    int getIntMod();
    int getWisMod();
    int getChaMod();
   
    virtual int attack1()=0;
    virtual int attack2()=0;
    virtual int attack3()=0;
    virtual int attack4()=0;
    
    int getBaseAttackBonus1();
    int getBaseAttackBonus2();
    int getBaseAttackBonus3();
    int getBaseAttackBonus4();
    
    int getHitDie(); 
    int getAbilityModifier(double aScore);
    int getHighestAbilityScore();
    
    //combat
    bool hasAttack1();
    bool hasAttack2();
    bool hasAttack3();
    bool hasAttack4();
    int rollDie(int type);
    int rollD20();
    virtual int rollDamage()=0;
    void takeDamage(int dmg);
};


#endif	/* CHARACTER_H */
