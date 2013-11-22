/*
 * MapTile.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#include "MapTile.h"

MapTile::MapTile(Map* mapModel, int i, int j, int x, int y, int w, int h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->mapModel = mapModel;
    this->i = i;
    this->j = j;
    cell = mapModel->getCell(i, j);
}

MapTile::~MapTile()
{
    cell.reset();
    mapModel = nullptr;
    i = 0;
    j = 0;
}

void MapTile::handleEvents(SDL_Event &event)
{
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        int clickX = event.button.x;
        int clickY = event.button.y;

        // Check if it falls inside the boundaries of this Clickable object
        if (clickX >= x && clickY >= y && clickX <= (x + w) && clickY <= (y + h))
        {
            mapModel->setCell(getSelectedCellType(), i, j);
            //mapModel->setCell(MapScreen::selectedTile, i, j);
        }
    }
}

void MapTile::draw()
{
    if (cell->getType() == Cell::CellType::Wall)
    {
        TextureRenderer::getInstance()->drawTexture("bricks", x, y, w, h);
    }
    else if (cell->getType() == Cell::CellType::Floor)
    {
        TextureRenderer::getInstance()->drawTexture("floor", x, y, w, h);
    }
    else if (cell->getType() == Cell::CellType::Start)
    {
        TextureRenderer::getInstance()->drawTexture("floor", x, y, w, h);
        TextureRenderer::getInstance()->drawTexture("start", x, y, w, h);
    }
    else if (cell->getType() == Cell::CellType::End)
    {
        TextureRenderer::getInstance()->drawTexture("floor", x, y, w, h);
        TextureRenderer::getInstance()->drawTexture("stop", x, y, w, h);
    }
    else if (cell->getType() == Cell::CellType::Empty)
    {
        TextureRenderer::getInstance()->drawTexture("empty", x, y, w, h);
    }


    if (cell->isOccupied())
    {
        CellOccupant * occupant = cell->getOccupant();

        //  ===================== TEMPORARY for Assignment 3 =====================
        if (dynamic_cast<DummyCharacter*>(occupant) != nullptr)
        {
            TextureRenderer::getInstance()->drawTexture("link", x, y, w, h);
        }
        else if (dynamic_cast<DummyMonster*>(occupant) != nullptr)
        {
            TextureRenderer::getInstance()->drawTexture("monster", x, y, w, h);
        }
        else if (dynamic_cast<DummyItemChest*>(occupant) != nullptr)
        {
            TextureRenderer::getInstance()->drawTexture("treasure", x, y, w, h);
        }
        occupant = nullptr;
        // =======================================================================
    }
}
