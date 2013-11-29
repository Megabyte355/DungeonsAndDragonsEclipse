#pragma once
#include "Character.h"

class Combat
{
    
    public:
	void combatRound(Character* player,Character* monster);
        
        int calcNumOfAttacks(Character* character);
        
	Combat(void);
	~Combat(void);
};