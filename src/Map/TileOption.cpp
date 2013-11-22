/*
 * TileOption.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#include "TileOption.h"

TileOption::TileOption(Cell::CellType type, int x, int y, int w, int h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->myType = type;
}

TileOption::~TileOption()
{
}

Cell::CellType TileOption::getCellType()
{
    return myType;
}

void TileOption::handleEvents(SDL_Event& event)
{
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        int clickX = event.button.x;
        int clickY = event.button.y;

        // Check if it falls inside the boundaries of this Clickable object
        if (clickX >= x && clickY >= y && clickX <= (x + w) && clickY <= (y + h))
        {
            functionPointer(myType);
            std::cout << "Tile option " << myType << " clicked." << std::endl;
        }
    }
}

void TileOption::draw()
{
    std::string textureName;
    std::string label;

    if (myType == Cell::CellType::Wall)
    {
        textureName = "wall";
        label = "Wall tile";
    }
    else if (myType == Cell::CellType::Floor)
    {
        textureName = "floor";
        label = "Floor tile";
    }
    else if (myType == Cell::CellType::Start)
    {
        textureName = "start";
        label = "Start";
    }
    else if (myType == Cell::CellType::End)
    {
        textureName = "stop";
        label = "End";
    }
    else
    {
        textureName = "empty";
        label = "Empty tile";
    }

    TextureRenderer::getInstance()->drawTexture(textureName, x, y, 50, 50);
    TextRenderer::getInstance()->renderText(x + 75, y + 13, label, "calibri", TextRenderer::white, 25);
}
