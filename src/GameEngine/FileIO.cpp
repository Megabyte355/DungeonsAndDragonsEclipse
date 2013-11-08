/*
 * FileIO.cpp
 *
 *  Created on: Nov 8, 2013
 *      Author: Gary
 */

#include "FileIO.h"

FileIO::FileIO(std::string prefix, std::string postfix)
{
    this->prefix = prefix;
    this->postfix = postfix;
}

FileIO::~FileIO()
{
}

void FileIO::save(int slot, std::string data)
{
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

std::string FileIO::load(int slot)
{
    std::string data = "";
    std::stringstream filename;
    filename << prefix << slot << postfix;
    std::ifstream file(filename.str());
    if (file.is_open())
    {
        data = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    }
    else
    {
        std::cout << "Error loading file " << filename << std::endl;
    }
    return data;
}

