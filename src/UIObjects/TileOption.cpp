/*
 * TileOption.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#include "TileOption.h"

TileOption::TileOption(Cell::CellType type, int x, int y, int w, int h) :
        Clickable(x, y, w, h), ListOption(x, y, w, h)
{
    this->myType = type;
}

TileOption::~TileOption()
{
}

Cell::CellType TileOption::getCellType()
{
    return myType;
}

void TileOption::update()
{

}

void TileOption::handleEvents(SDL_Event& event)
{
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        // Check if it falls inside the boundaries of this Clickable object
        if (intersect(event.button.x, event.button.y) && functionPointer != nullptr)
        {
            functionPointer(myType);
            std::cout << "Tile option " << myType << " clicked." << std::endl;
        }
    }
    else if (event.type == SDL_MOUSEMOTION)
    {
        if (intersect(event.button.x, event.button.y))
        {
            hover = true;
        }
        else
        {
            hover = false;
        }
    }
}

void TileOption::draw()
{
    if (visible)
    {
        std::string textureName;
        std::string label;

        if (myType == Cell::CellType::Wall)
        {
            textureName = "wall";
            label = "Wall";
        }
        else if (myType == Cell::CellType::Floor)
        {
            textureName = "floor";
            label = "Floor";
        }
        else if (myType == Cell::CellType::Start)
        {
            textureName = "start";
            label = "Start";
        }
        else if (myType == Cell::CellType::End)
        {
            textureName = "end";
            label = "End";
        }
        else
        {
            textureName = "empty";
            label = "Empty tile";
        }

        if (hover)
        {
            TextureRenderer::getInstance()->drawTexture("transparent_white", boundary.x, boundary.y, boundary.w,
                    boundary.h);
        }

        // TODO Need to resize
        TextureRenderer::getInstance()->drawTexture(textureName, boundary.x + 10, boundary.y + 10, 35, 35);
        TextRenderer::getInstance()->renderText(boundary.x + 75, boundary.y + 13, label, "retganon",
                TextRenderer::white, 30);
    }

}
