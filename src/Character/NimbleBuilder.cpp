/* 
 * File:   NimbleBuilder.cpp
 * Author: Tiffany Ip 9341943
 *
 * Created on November 23, 2013, 1:49 PM
 */

#include "NimbleBuilder.h"

void NimbleBuilder::setType(){
    charType = "BULLY";
}

void NimbleBuilder::buildType(){
    character->setType(charType);
}

void NimbleBuilder::buildStats(){
    character->setName(charName);
    character->setLevel(charLevel);
    character->setSpeed();
    character->generateAbilityScores();
    
   int dex = character->getHighestAbilityScore();
   int con = character->getHighestAbilityScore();
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

void NimbleBuilder::buildItems(){
    //to complete
}
