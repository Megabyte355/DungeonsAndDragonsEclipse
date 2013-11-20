/*
 * CharacterDriver.h
 *
 *  Created on: Nov 9, 2013
 *      Author: Gary
 */

#ifndef CHARACTERDRIVER_H_
#define CHARACTERDRIVER_H_

#include "Fighter.h"
#include <iostream>

class CharacterDriver : public virtual Observer
{
    public:
        CharacterDriver();
        ~CharacterDriver();

        void update() override;
        void runProgram();

        Fighter * returnFighter();
    private:
        Fighter * myFighter;
};

#endif /* CHARACTERDRIVER_H_ */
