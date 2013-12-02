#pragma once
#include "Character.h"

class Combat
{
    
    public:
	void combatRound(Character* player,Character* monster);
    void combatAction(Character* attacker, Character* defender);

	Combat(void);
	~Combat(void);
};
