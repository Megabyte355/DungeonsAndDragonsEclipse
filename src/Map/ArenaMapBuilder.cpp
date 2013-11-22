/*
 * ArenaMapBuilder.cpp
 *
 *  Created on: Nov 20, 2013
 *      Author: Gary
 */

#include "ArenaMapBuilder.h"

ArenaMapBuilder::ArenaMapBuilder()
{
    map = new Map();
}

ArenaMapBuilder::~ArenaMapBuilder()
{
}

void ArenaMapBuilder::setSize()
{
    map->initialize(9, 9);
}

void ArenaMapBuilder::setTiles()
{
    // Left and Right walls
    for(int i = 0; i < 9; i++)
    {
        map->setCell(Cell::CellType::Wall, 0, i);
        map->setCell(Cell::CellType::Wall, 8, i);
    }

    // Top and Bottom walls
    for(int i = 1; i < 8; i++)
    {
        if(i != 4)
        {
            map->setCell(Cell::CellType::Wall, i, 0);
            map->setCell(Cell::CellType::Wall, i, 8);
        }
    }
}

void ArenaMapBuilder::setStartPoint()
{
    map->setCell(Cell::CellType::Start, 4, 0);
}

void ArenaMapBuilder::setEndPoint()
{
    map->setCell(Cell::CellType::End, 4, 8);
}

void ArenaMapBuilder::placeItems()
{
    DummyItemChest * chest = new DummyItemChest(level);
    map->setOccupant(chest, 4, 4);

    // The map is responsible for deleting the chest (for this assignment).
    // TODO Need to find a solution for final build
    chest = nullptr;
}

void ArenaMapBuilder::placeMonsters()
{
    DummyMonster * monster = new DummyMonster(level);
    map->setOccupant(monster, 4, 1);

    // The map is responsible for deleting the chest (for this assignment).
    // TODO Need to find a solution for final build
    monster = nullptr;
}
