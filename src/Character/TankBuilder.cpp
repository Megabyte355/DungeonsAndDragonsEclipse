/* 
 * File:   TankBuilder.cpp
 * Author: Tiffany Ip 9341943
 *
 * Created on November 23, 2013, 1:45 PM
 */
#include "TankBuilder.h"

void TankBuilder::setType(){
    charType = "BULLY";
}

void TankBuilder::buildType(){
    character->setType(charType);
}

void TankBuilder::buildStats(){
    character->setName(charName);
    character->setStartingLevel(charLevel);
    character->setSpeed();
    character->generateAbilityScores();
    
    int con = character->getHighestAbilityScore();
    int dex = character->getHighestAbilityScore();
    int str = character->getHighestAbilityScore();
    int intel = character->getHighestAbilityScore();
    int chari = character->getHighestAbilityScore();
    int wis = character->getHighestAbilityScore();
    
    character->setStr(str);
    character->setCon(con);
    character->setDex(dex);
    character->setInt(intel);
    character->setCha(chari);
    character->setWis(wis);
    character->setStrMod(str);
    character->setDexMod(dex);
    character->setConMod(con);
    character->setChaMod(chari);
    character->setIntMod(intel);
    character->setWisMod(wis);
    
    character->setAC();
    character->setHP();
    character->setAttackBonuses();

}

void TankBuilder::buildItems(){
    //to complete
}