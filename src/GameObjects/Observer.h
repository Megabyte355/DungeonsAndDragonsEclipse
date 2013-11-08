/*
 * Observer.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observer
{
    public:
        Observer();
        virtual ~Observer() {};
        virtual void update() = 0;

        long getObserverID();
    private:
        long observerID;
        static long observerIDtracker;
};

#endif /* OBSERVER_H_ */
