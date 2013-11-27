/*
 * ItemContainerBuilder.h
 *
 *  Created on: Nov 24, 2013
 *      Author: Kevin
 */

#ifndef ITEMCONTAINERBUILDER_H_
#define ITEMCONTAINERBUILDER_H_

#include "ItemContainer.h"

class ItemContainerBuilder
{
    protected:
        ItemContainer * itemContainer;
        int mapLevel;
        int characterLevel;

    public:
        ItemContainerBuilder();
        ItemContainerBuilder(int pmapLevel, int pcharacterLevel);
        virtual ~ItemContainerBuilder();

        virtual void buildContainer() = 0;

        ItemContainer * getItemContainer(){return itemContainer;}
        
        int getCharacterLevel() const {return characterLevel;}
        void setCharacterLevel(int characterLevel) {this->characterLevel = characterLevel;}
        int getMapLevel() const {return mapLevel;}
        void setMapLevel(int mapLevel) {this->mapLevel = mapLevel;}
};

#endif /* ITEMCONTAINERBUILDER_H_ */
