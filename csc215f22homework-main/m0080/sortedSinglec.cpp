	#include "sortedSingle.h"

bool sortedSingle::remove(int item)
{

	node *nxtItem, *tmp;

	if (headptr == nullptr)
	{
		return false;
	}

	if (headptr->theItem == item)
	{
		tmp = headptr;
		headptr = headptr->next;
		delete tmp;
		return true;
	}

	nxtItem = headptr;

	while (nxtItem->next != nullptr)
	{
		tmp = nxtItem;
		nxtItem = nxtItem->next;

		if (nxtItem->theItem == item)
		{

			tmp->next = nxtItem->next;
			 
			delete nxtItem;

			return true;
		}
	}

	return false;

}


void sortedSingle::clear()
{
	node *nxtItem, * tmp;

	int c = 0;

	if (headptr == nullptr)
	{
		return;
	}

	nxtItem = headptr;

	headptr = nullptr;

	while (nxtItem->next != nullptr)
	{
		tmp = nxtItem;

		nxtItem = nxtItem->next;

		delete tmp;
	}

	delete nxtItem;

}