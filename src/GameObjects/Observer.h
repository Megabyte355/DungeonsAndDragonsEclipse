/*
 * IObserver.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#ifndef IOBSERVER_H_
#define IOBSERVER_H_

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

#endif /* IOBSERVER_H_ */
