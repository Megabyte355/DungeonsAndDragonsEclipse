/* 
 * File:   Master.h
 * Author: Tiffany Ip 9341943
 *
 * Created on November 23, 2013, 10:15 AM
 */

#ifndef MASTER_H
#define	MASTER_H
#include <string>
#include "CharacterBuilder.h"

class Master {
    
    CharacterBuilder* characterBuilder;
    
public: 
    void setCharacterBuilder(CharacterBuilder* cb);
    
    void constructCharacter(int level, string name); //for players
    void constructCharacter(int level); //for monsters?
    
    Character* getCharacter();
};


#endif	/* MASTER_H */

