/*
 * ChestBuilder.h
 *
 *  Created on: Nov 24, 2013
 *      Author: Kevin
 */

#ifndef CHESTBUILDER_H_
#define CHESTBUILDER_H_

#include "ItemContainerBuilder.h"
#include "Armor.h"
#include "Belt.h"
#include "Boots.h"
#include "Equipment.h"
#include "Ring.h"
#include "Shield.h"
#include "Weapon.h"
#include "Helmet.h"
#include "Bracers.h"

class ChestBuilder: public virtual ItemContainerBuilder
{
    protected:
        vector<string> possibleItems;

    public:
        ChestBuilder();
        ChestBuilder(int pmapLevel, int pcharacterLevel);
        virtual ~ChestBuilder();

        virtual void buildContainer();
        void createRandomItem();
};

#endif /* CHESTBUILDER_H_ */
