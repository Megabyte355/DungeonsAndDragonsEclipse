/* 
 * File:   BullyBuilder.cpp
 * Author: Tiffany Ip 9341943
 *
 * Created on November 23, 2013, 11:39 AM
 */

#include "BullyBuilder.h"

void BullyBuilder::setType(){
    charType = "BULLY";
}

void BullyBuilder::buildType(){
    character->setType(charType);
}

void BullyBuilder::buildStats(){
    character->setName(charName);
    character->setLevel(charLevel);
    character->generateAbilityScores();
    character->setSpeed();
    
    int str = character->getHighestAbilityScore();
    int con = character->getHighestAbilityScore();
    int dex = character->getHighestAbilityScore();
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

void BullyBuilder::buildItems(){
    //to complete
}
