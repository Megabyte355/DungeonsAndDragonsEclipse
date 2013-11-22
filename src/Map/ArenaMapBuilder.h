/*
 * ArenaMapBuilder.h
 *
 *  Created on: Nov 20, 2013
 *      Author: Gary
 */

#ifndef ARENAMAPBUILDER_H_
#define ARENAMAPBUILDER_H_

#include "MapBuilder.h"
#include "DummyItemChest.h"
#include "DummyMonster.h"

class ArenaMapBuilder : public virtual MapBuilder
{
    public:
        ArenaMapBuilder();
        virtual ~ArenaMapBuilder();

        void setSize() override;
        void setTiles() override;
        void setStartPoint() override;
        void setEndPoint() override;
        void placeItems() override;
        void placeMonsters() override;
};

#endif /* ARENAMAPBUILDER_H_ */
