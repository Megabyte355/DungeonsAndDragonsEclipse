/*
 * Observable.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include "Observer.h"
#include <memory>
#include <vector>
#include <iostream>

class Observable
{
    public:
        Observable();
        virtual ~Observable();

        void attach(Observer*);
        void detach(Observer*);
        void notify();
        int getObservableID();

    protected:
        // Observer variables
        std::vector<Observer*> observers;
        static long observableIDtracker;
        long observableID;
};

#endif /* OBSERVABLE_H_ */
