/* 
 * File:   MoblinBuilder.cpp
 * Author: Tiffany Ip 9341943
 *
 * Created on November 23, 2013, 3:04 PM
 */

#include "MoblinBuilder.h"

void MoblinBuilder::setType(){
    charType = "MOBLIN";
}

void MoblinBuilder::buildType(){
    character->setType(charType);
}
void MoblinBuilder::buildStats(){
    character->setLevel(charLevel);
    character->setSpeed();
    character->generateAbilityScores();
    
   int dex = character->getHighestAbilityScore();
   int con = character->getHighestAbilityScore();
   int str = character->getHighestAbilityScore();
   int intel = character->getHighestAbilityScore();
   int wis = character->getHighestAbilityScore();
   int chari = character->getHighestAbilityScore();
    
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

void MoblinBuilder::buildItems(){
    //to complete
}



