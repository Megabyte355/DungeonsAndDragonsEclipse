/*
 * MapTile.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#include "MapTile.h"

MapTile::MapTile(Map* mapModel, int i, int j, int x, int y, int w, int h) :
        Clickable(x, y, w, h)
{
    this->mapModel = mapModel;
    this->i = i;
    this->j = j;
    cell = mapModel->getCell(i, j);
}

MapTile::~MapTile()
{
    cell.reset();
    mapModel = nullptr;
}

void MapTile::update()
{
}

void MapTile::handleEvents(SDL_Event &event)
{
    if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP)
    {
        // Check if it falls inside the boundaries of this Clickable object
        if (intersect(event.button.x, event.button.y))
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
        TextureRenderer::getInstance()->drawTexture("wall", boundary.x, boundary.y, boundary.w, boundary.h);
    }
    else if (cell->getType() == Cell::CellType::Floor)
    {
        TextureRenderer::getInstance()->drawTexture("floor", boundary.x, boundary.y, boundary.w, boundary.h);
    }
    else if (cell->getType() == Cell::CellType::Start)
    {
        TextureRenderer::getInstance()->drawTexture("floor", boundary.x, boundary.y, boundary.w, boundary.h);
        TextureRenderer::getInstance()->drawTexture("start", boundary.x, boundary.y, boundary.w, boundary.h);
        TextureRenderer::getInstance()->drawTexture("link", boundary.x, boundary.y, boundary.w, boundary.h);
    }
    else if (cell->getType() == Cell::CellType::End)
    {
        TextureRenderer::getInstance()->drawTexture("floor", boundary.x, boundary.y, boundary.w, boundary.h);
        TextureRenderer::getInstance()->drawTexture("end", boundary.x, boundary.y, boundary.w, boundary.h);
    }
    else if (cell->getType() == Cell::CellType::Empty)
    {
        TextureRenderer::getInstance()->drawTexture("empty", boundary.x, boundary.y, boundary.w, boundary.h);
    }

    if (cell->isOccupied())
    {
//        CellOccupant * occupant = cell->getOccupant();
//
//        //  ===================== TEMPORARY for Assignment 3 =====================
//        if (dynamic_cast<DummyCharacter*>(occupant) != nullptr)
//        {
//            TextureRenderer::getInstance()->drawTexture("link", x, y, w, h);
//        }
//        else if (dynamic_cast<DummyMonster*>(occupant) != nullptr)
//        {
//            TextureRenderer::getInstance()->drawTexture("monster", x, y, w, h);
//        }
//        else if (dynamic_cast<DummyItemChest*>(occupant) != nullptr)
//        {
//            TextureRenderer::getInstance()->drawTexture("treasure", x, y, w, h);
//        }
//        occupant = nullptr;
//        // =======================================================================
    }
}

void MapTile::setCellTypeGetter(std::function<Cell::CellType()> function)
{
    getSelectedCellType = function;
}
