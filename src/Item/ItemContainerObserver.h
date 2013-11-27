#ifndef	ITEMCONTAINEROBSERVER_H_
#define ITEMCONTAINEROBSERVER_H_

#include "Observer.h"
#include "ItemContainer.h"
#include <iostream>

using namespace std;

class ItemContainerObserver : public Observer
{
	
private:
	ItemContainer * container;

public:
	ItemContainerObserver(ItemContainer * container);
	virtual ~ItemContainerObserver(void);

	void update() override;
};

#endif