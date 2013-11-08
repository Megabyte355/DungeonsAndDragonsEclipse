/*
 * Recordable.cpp
 *
 *  Created on: Nov 7, 2013
 *      Author: Gary
 */

#include "Recordable.h"

Recordable::~Recordable()
{
    delete fileHandler;
}

void Recordable::save(int slot)
{
    if (fileHandler != nullptr)
    {
        fileHandler->save(slot, toString());
    }
}

void Recordable::load(int slot)
{
    if (fileHandler != nullptr)
    {
        fromString(fileHandler->load(slot));
    }
}
