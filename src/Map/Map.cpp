/*
 * Map.cpp
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#include "Map.h"

Map::Map()
{
}

Map::Map(int width, int height)
{
    initialize(width, height);
}

Map::~Map()
{
}

void Map::initialize(int width, int height)
{
    // Sets the size of the map and initializes all cells
    mapWidth = width;
    mapHeight = height;
    matrix.resize(mapWidth);
    for (int i = 0; i < mapWidth; i++)
    {
        matrix[i].resize(mapHeight);
        for (int j = 0; j < mapHeight; j++)
        {
            matrix[i][j] = std::make_shared<Cell>(i, j);
        }
    }
    if (fileHandler == nullptr)
    {
        fileHandler = new FileIO("map_", ".txt");
    }
}

int Map::getWidth()
{
    return mapWidth;
}

int Map::getHeight()
{
    return mapHeight;
}

int Map::getLevel()
{
    return level;
}

void Map::setLevel(int level)
{
    this->level = level;
}

std::shared_ptr<Cell> Map::getCell(int x, int y)
{
    if (isValidCell(x, y))
    {
        return matrix[x][y];
    }
    return nullptr;
}

std::shared_ptr<Cell> Map::getStartCell()
{
    for (int i = 0; i < mapWidth; i++)
    {
        for (int j = 0; j < mapHeight; j++)
        {
            if (matrix[i][j]->getType() == Cell::CellType::Start)
            {
                return matrix[i][j];
            }
        }
    }
    return nullptr;
}

std::shared_ptr<Cell> Map::getEndCell()
{
    for (int i = 0; i < mapWidth; i++)
    {
        for (int j = 0; j < mapHeight; j++)
        {
            if (matrix[i][j]->getType() == Cell::CellType::End)
            {
                return matrix[i][j];
            }
        }
    }
    return nullptr;
}

void Map::setCell(Cell::CellType cellType, int x, int y)
{
    if (cellType == Cell::CellType::Start)
    {
        setStartCell(x, y);
    }
    else if (cellType == Cell::CellType::End)
    {
        setEndCell(x, y);
    }
    else if (isValidCell(x, y))
    {
        matrix[x][y]->setType(cellType);
        matrix[x][y]->setX(x);
        matrix[x][y]->setY(y);
        
        notify();
    }
}

void Map::setStartCell(int x, int y)
{
    if (isValidCell(x, y))
    {
        // Check if start cell already exists
        if (getStartCell() != nullptr)
        {
            getStartCell()->setType(Cell::CellType::Floor);
        }

        matrix[x][y]->setType(Cell::CellType::Start);
        matrix[x][y]->setX(x);
        matrix[x][y]->setY(y);

        notify();
    }
}

void Map::setEndCell(int x, int y)
{
    if (isValidCell(x, y))
    {
        // Check if end cell already exists
        if (getEndCell() != nullptr)
        {
            getEndCell()->setType(Cell::CellType::Floor);
        }
        matrix[x][y]->setType(Cell::CellType::End);
        matrix[x][y]->setX(x);
        matrix[x][y]->setY(y);

        notify();
    }
}

bool Map::validateMap()
{
    /*
     * A map is considered valid if it satisfies 3 conditions:
     *     1- A start point exist.
     *     2- An end point exist.
     *     3- There is a walkable path linking the start and end points.
     */
    std::shared_ptr<Cell> start = getStartCell();
    std::shared_ptr<Cell> end = getEndCell();

    bool hasStart = start != nullptr;
    bool hasEnd = end != nullptr;
    bool hasValidPath = false;

    if (!hasStart)
    {
        std::cout << "Start point is missing!" << std::endl;
    }
    else if (!hasEnd)
    {
        std::cout << "End point is missing!" << std::endl;
    }
    else
    {
        shortestPath = PathFinder::getShortestPath(*this, *start, *end);
        hasValidPath = !(shortestPath.empty());
        if (!hasValidPath)
        {
            std::cout << "There is no path from Start to End!" << std::endl;
        }
    }
    return hasStart && hasEnd && hasValidPath;
}

bool Map::isValidPath(Cell origin, Cell dest)
{
    return !PathFinder::getShortestPath(*this, origin, dest).empty();
}

std::vector<CellLocation> Map::getShortestPath(Cell &origin, Cell &dest)
{
    return PathFinder::getShortestPath(*this, origin, dest);
}

std::vector<CellLocation> Map::getStartToEndPath()
{
    std::vector<CellLocation> path;
    if (getStartCell() != nullptr && getEndCell() != nullptr)
    {
        path = PathFinder::getShortestPath(*this, *getStartCell(), *getEndCell());
    }
    return path;
}

bool Map::isValidCell(Cell c)
{
    return isValidCell(c.getX(), c.getY());
}

bool Map::isValidCell(int x, int y)
{
    return x >= 0 && x < mapWidth && y >= 0 && y < mapHeight;
}

bool Map::isValidCell(CellLocation loc)
{
    return isValidCell(loc.x, loc.y);
}

bool Map::isOccupiable(CellLocation loc)
{
    std::shared_ptr<Cell> temp = getCell(loc.x, loc.y);
    return temp != nullptr && temp->isOccupiable();
}

std::string Map::toFileString()
{
    std::stringstream ss;
    ss << mapWidth << "\n";
    ss << mapHeight << "\n";

    for (int row = 0; row < mapHeight; row++)
    {
        for (int col = 0; col < mapWidth; col++)
        {
            Cell::CellType currentType = matrix[col][row]->getType();
            if (currentType == Cell::CellType::Wall)
            {
                ss << "W";
            }
            else if (currentType == Cell::CellType::Floor)
            {
                ss << "F";
            }
            else if (currentType == Cell::CellType::Start)
            {
                ss << "S";
            }
            else if (currentType == Cell::CellType::End)
            {
                ss << "E";
            }
            else if (currentType == Cell::CellType::Empty)
            {
                ss << "_";
            }
            else
            {
                ss << "?";
            }
        }
        ss << "\n";
    }
    return ss.str();
}

void Map::fromFileString(std::string input)
{
    // Reset all
    for (int i = 0; i < mapWidth; i++)
    {
        for (int j = 0; j < mapHeight; j++)
        {
            matrix[i][j].reset();
        }
    }
    mapWidth = 0;
    mapHeight = 0;

    // Reading string
    std::stringstream ss;
    std::string line;
    ss << input;

    // First two lines are mapWidth and mapHeight
    std::getline(ss, line);
    std::stringstream temp1;
    temp1 << line;
    temp1 >> mapWidth;
    std::getline(ss, line);
    std::stringstream temp2;
    temp2 << line;
    temp2 >> mapHeight;

    // Re-initialize the map
    initialize(mapWidth, mapHeight);

    // Read the string
    while (std::getline(ss, line))
    {
        for (int row = 0; row < mapHeight; row++)
        {
            for (int col = 0; col < mapWidth; col++)
            {
                for (unsigned int k = 0; k < line.size(); k++)
                {
                    char c = line[k];
                    if (c == 'W')
                    {
                        matrix[col][row]->setType(Cell::CellType::Wall);
                    }
                    else if (c == 'F')
                    {
                        matrix[col][row]->setType(Cell::CellType::Floor);
                    }
                    else if (c == 'S')
                    {
                        matrix[col][row]->setType(Cell::CellType::Start);
                    }
                    else if (c == 'E')
                    {
                        matrix[col][row]->setType(Cell::CellType::End);
                    }
                    else
                    {
                        matrix[col][row]->setType(Cell::CellType::Empty);
                    }
                }
            }
        }
    }
}
