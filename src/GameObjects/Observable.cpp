/*
 * Observable.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#include "Observable.h"

long Observable::observableIDtracker = 0;

Observable::Observable()
{
    observableID = observableIDtracker++;
}

Observable::~Observable()
{
    observers.clear();
}

void Observable::attach(Observer * obs)
{
    observers.push_back(obs);
    observableID = observableIDtracker++;
    std::cout << "Observable #" << observableID << " attached." << std::endl;

}

void Observable::detach(Observer * obs)
{
    for (std::vector<Observer*>::iterator it = observers.begin(); it != observers.end(); it++)
    {
        if ((*it)->getObserverID() == obs->getObserverID())
        {
            observers.erase(it);
            std::cout << "Observable #" << observableID << " detached." << std::endl;
            break;
        }
    }
}

void Observable::notify()
{
    std::cout << "Observable #" << observableID << " calling notify()." << std::endl;
    for (std::vector<Observer*>::iterator it = observers.begin(); it != observers.end(); it++)
    {
        (*it)->update();
    }
}

int Observable::getObservableID()
{
    return observableID;
}
