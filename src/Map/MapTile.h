/*
 * MapTile.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#ifndef MAPTILE_H_
#define MAPTILE_H_

#include "Cell.h"
#include "Map.h"
#include "TextureRenderer.h"
#include "Clickable.h"
#include <SDL.h>
#include <functional>

// Temporary for Assignment3
#include "DummyCharacter.h"
#include "DummyMonster.h"
#include "DummyItemChest.h"

class MapTile: public virtual Clickable
{
    public:
        // Index of cell on mapModel
        int i;
        int j;

        MapTile(Map *, int i, int j, int x, int y, int w, int h);
        ~MapTile();
        void update() override;
        void handleEvents(SDL_Event &) override;
        void draw() override;

        void setCellTypeGetter(std::function<Cell::CellType()>);
    private:
        std::function<Cell::CellType()> getSelectedCellType;
        std::shared_ptr<Cell> cell;
        Map * mapModel;
};

#endif /* MAPTILE_H_ */
