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
#include <SDL.h>
#include <functional>

class MapTile
{
    public:
        int x, y, w, h;

        // Index of cell on mapModel
        int i;
        int j;

        MapTile(Map *, int, int, int, int, int, int);
        ~MapTile();
        void handleEvents(SDL_Event &);
        void draw();

        std::function<Cell::CellType()> getSelectedCellType;
    private:
        std::shared_ptr<Cell> cell;
        Map * mapModel;
};

#endif /* MAPTILE_H_ */
