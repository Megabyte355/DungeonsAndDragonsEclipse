/* 
 * File:   CharacterBuilder.cpp
 * Author: Tiffany Ip 9341943
 *
 * Created on November 23, 2013, 10:16 AM
 */

#include "CharacterBuilder.h"
#include "Fighter.h"
#include "Moblin.h"
#include <string>


void CharacterBuilder::createNewCharacter(){
    if ( charType == "BULLY" || charType == "NIMBLE" || charType == "TANK" ) {
        character = new Fighter();
    }
    else if ( charType == "MOBLIN" ){
        character = new Moblin();
    }
    else {
        throw "No existing type.";
    }
}

void CharacterBuilder::setName(string name){
    charName = name;
}

void CharacterBuilder::setLevel(int level){
    charLevel = level;
}

Character* CharacterBuilder::getCharacter(){
    return character;
}
