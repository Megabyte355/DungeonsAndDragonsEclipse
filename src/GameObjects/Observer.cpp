/*
 * Observer.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#include "Observer.h"

long Observer::observerIDtracker = 0;

Observer::Observer()
{
    observerID = observerIDtracker++;
}

long Observer::getObserverID()
{
    return observerID;
}
