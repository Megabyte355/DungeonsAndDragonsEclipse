/*
 * MapTileOptionList.h
 *
 *  Created on: Nov 29, 2013
 *      Author: Gary
 */

#ifndef MAPTILEOPTIONLIST_H_
#define MAPTILEOPTIONLIST_H_

#include "ScrollingOptionList.h"
#include "TileOption.h"

class MapTileOptionList : public virtual ScrollingOptionList

{
    public:
        MapTileOptionList(int x, int y, int w, int h, int i);
        virtual ~MapTileOptionList();

        void update() override;
        void draw() override;
        void handleEvents(SDL_Event &) override;

        void addMapTileOption(TileOption*);
        Cell::CellType getSelectedType();
        void setSelectedType(Cell::CellType);
    private:
        Cell::CellType selectedType;
};

#endif /* MAPTILEOPTIONLIST_H_ */
