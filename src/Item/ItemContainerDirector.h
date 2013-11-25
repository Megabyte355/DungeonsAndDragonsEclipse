/*
 * ItemContainerDirector.h
 *
 *  Created on: Nov 24, 2013
 *      Author: Kevin
 */

#ifndef ITEMCONTAINERDIRECTOR_H_
#define ITEMCONTAINERDIRECTOR_H_

#include "ItemContainerBuilder.h"

class ItemContainerDirector
{
    private:
        ItemContainerBuilder * builder;
    public:
        ItemContainerDirector();
        ItemContainerDirector(ItemContainerBuilder * builder);
        virtual ~ItemContainerDirector();

        void setBuilder(ItemContainerBuilder * builder);
        void construct();

        ItemContainer * getResult();
};

#endif /* ITEMCONTAINERDIRECTOR_H_ */
