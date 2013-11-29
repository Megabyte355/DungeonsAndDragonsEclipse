/* 
 * File:   Master.cpp
 * Author: Tiffany Ip 9341943
 *
 * Created on November 23, 2013, 10:15 AM
 */

#include "Master.h"
#include "CharacterBuilder.h"


void Master::setCharacterBuilder(CharacterBuilder* cb){
    characterBuilder = cb;
}

void Master::constructCharacter(int level, string name){
    characterBuilder->setName(name);
    characterBuilder->setLevel(level);
    characterBuilder->setType();
    characterBuilder->createNewCharacter();
    characterBuilder->buildType();
    characterBuilder->buildStats();
    characterBuilder->buildItems();
}

void Master::constructCharacter(int level){
    characterBuilder->setLevel(level);
    characterBuilder->setType();
    characterBuilder->createNewCharacter();
    characterBuilder->buildType();
    characterBuilder->buildStats();
    characterBuilder->buildItems();
}

Character* Master::getCharacter(){
    return characterBuilder->getCharacter();
}
