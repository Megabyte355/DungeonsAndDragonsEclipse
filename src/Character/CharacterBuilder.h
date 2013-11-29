/* 
 * File:   CharacterBuilder.h
 * Author: Tiffany Ip 9341943
 *
 * Created on November 23, 2013, 10:16 AM
 */

#ifndef CHARACTERBUILDER_H
#define	CHARACTERBUILDER_H
#include <string>
#include "Character.h"

class CharacterBuilder {
    
public:
    void setName(string name);
    void setLevel(int level);
    void createNewCharacter();
   
    Character* getCharacter();
    
    virtual void setType() = 0;
    virtual void buildType() = 0;
    virtual void buildStats() = 0;
    virtual void buildItems() = 0;

protected:
    Character* character;
    string charType;
    string charName;
    int charLevel;
    
};


#endif	/* CHARACTERBUILDER_H */

