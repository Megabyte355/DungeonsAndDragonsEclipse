/*
 * TileOption.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#ifndef TILEOPTION_H_
#define TILEOPTION_H_

#include "Cell.h"
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include <string>
#include <SDL.h>
#include <functional>

class TileOption
{
    public:
        TileOption(Cell::CellType, int, int, int, int);
        ~TileOption();

        Cell::CellType getCellType();
        void handleEvents(SDL_Event &);
        void draw();

        std::function<void(Cell::CellType)> functionPointer;
    private:
        int x, y, w, h;
        Cell::CellType myType;
};

#endif /* TILEOPTION_H_ */
