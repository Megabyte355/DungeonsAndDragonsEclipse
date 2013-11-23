/*
 * DummyItem.h
 *
 *  Created on: Nov 22, 2013
 *      Author: Gary
 */

#ifndef DUMMYITEM_H_
#define DUMMYITEM_H_

class DummyItem
{
    public:
        DummyItem(int level);
        virtual ~DummyItem();

    private:
        int magicalStrength;
};

#endif /* DUMMYITEM_H_ */
