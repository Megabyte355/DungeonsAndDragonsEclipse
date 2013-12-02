/*
 * MapTile.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#ifndef MAPTILE_H_
#define MAPTILE_H_

#include <functional>
#include <SDL.h>
#include "Cell.h"
#include "Map.h"
#include "TextureRenderer.h"
#include "Clickable.h"

// Temporary for Assignment3

class MapTile : public virtual Clickable
{
    public:
        // Index of cell on mapModel
        int i;
        int j;

        MapTile(Map *, int, int, int, int, int, int);
        ~MapTile();
        void update() override;
        void handleEvents(SDL_Event &) override;
        void draw() override;

        SDL_Rect getBoundary();

        std::function<Cell::CellType()> getSelectedCellType;
    private:
        std::shared_ptr<Cell> cell;
        Map * mapModel;
};

#endif /* MAPTILE_H_ */
