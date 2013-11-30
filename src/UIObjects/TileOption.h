/*
 * TileOption.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#ifndef TILEOPTION_H_
#define TILEOPTION_H_

#include <string>
#include <SDL.h>
#include <functional>
#include "Cell.h"
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include "ListOption.h"

class TileOption: public virtual ListOption
{
    public:
        TileOption(Cell::CellType, int, int, int, int);
        ~TileOption();

        Cell::CellType getCellType();
        void update();
        void draw();
        void handleEvents(SDL_Event &);
        std::function<void(Cell::CellType)> functionPointer;
    private:
        Cell::CellType myType;
};

#endif /* TILEOPTION_H_ */
