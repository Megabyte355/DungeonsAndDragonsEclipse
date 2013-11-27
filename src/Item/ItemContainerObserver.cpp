#include "ItemContainerObserver.h"


ItemContainerObserver::ItemContainerObserver(ItemContainer * c){
	cout << "Creating ItemContainerObserver from constructor!" << endl;
	container = c;
}


ItemContainerObserver::~ItemContainerObserver(void)
{
	container = nullptr;
}

void ItemContainerObserver::update(){

	cout << "Calling update() from BasicCharacter class Observer using the Observer Pattern!" << endl << endl;

	container->calculateContainerStats();
	container->displayContainerEquips();
	container->displayContainerStats();
}
