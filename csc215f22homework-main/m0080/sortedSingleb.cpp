#include "sortedSingle.h"

bool sortedSingle::insert(int item)
{
	node *nextItem;

	node *toAdd = new (nothrow) node;

	if (toAdd == nullptr)
	{
		return false;
	}

	toAdd->theItem = item;
	toAdd->next = nullptr;

	if (headptr == nullptr) 
	{
		headptr = toAdd;
		return true;
	}

	else if (headptr->theItem >= item)
	{
		nextItem = headptr;

		headptr = toAdd;

		headptr->next = nextItem;

		return true;
	}

	nextItem = headptr;

	while (true)
	{

		if (nextItem->next == nullptr)
		{	
			nextItem->next = toAdd;
			return true;
		}

		else if ((nextItem->theItem < item && nextItem->next->theItem > item) || nextItem->theItem == item)
		{
			toAdd->next = nextItem->next;
			nextItem->next = toAdd;
			return true;
		}

		nextItem = nextItem->next;
	}

	return false;
}

void sortedSingle::print(ostream& out, string seperator)
{
	node *nextItem;

	if (headptr == nullptr)
	{
		return;
	}

	nextItem = headptr;

	while (nextItem->next != nullptr)
	{
		if (nextItem->next != nullptr)
		{
			out << nextItem->theItem << seperator;
		}
		nextItem = nextItem->next;
	}

	out << nextItem->theItem;
}