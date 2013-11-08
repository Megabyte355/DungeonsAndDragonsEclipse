/*
 * MapIO.cpp
 *
 *  Created on: Nov 8, 2013
 *      Author: Gary
 */

#include "MapIO.h"

MapIO::MapIO(void (*fromStringFunction)(std::string), std::string (*toStringFunction)())
{
    saver = toStringFunction;
    loader = fromStringFunction;
    prefix = "map_";
    postfix = ".txt";
}

MapIO::~MapIO()
{
    saver = nullptr;
    loader = nullptr;
}

void MapIO::save(int slot)
{
    std::string data = saver();
    std::stringstream ss;
    ss << data;

    std::stringstream filename;
    filename << prefix << slot << postfix;

    std::ofstream file(filename.str());
    if (file.is_open())
    {
        file << data;
        file.close();
    }
    else
    {
        std::cout << "Error saving file " << filename << std::endl;
    }
}

void MapIO::load(int slot)
{
    std::stringstream filename;
    filename << prefix << slot << postfix;
    std::ifstream file(filename.str());
    if(file.is_open())
    {
        std::string data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        loader(data);
    }
    else
    {
        std::cout << "Error loading file " << filename << std::endl;
    }
}
