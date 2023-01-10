#include "sortedSingle.h"
#include <iostream>

sortedSingle::sortedSingle()
{
	headptr = nullptr;
}

int sortedSingle::size()
{
	int size = 0;

	if (headptr == 0)
	{
		return 0;
	}

	node currentItem = *headptr;

	size++;

	while (currentItem.next != nullptr)
	{
		size++;
		currentItem = *currentItem.next;
	}

	return size;
}

bool sortedSingle::empty()
{
	return headptr == nullptr;
}

bool sortedSingle::find(int item)
{
	if (headptr == nullptr)
	{
		return false;
	}

	node nextitem = *headptr;

	while (true)
	{
		if (nextitem.theItem == item)
		{
			return true;
		}

		if (nextitem.next == nullptr)
		{
			return false;
		}

		nextitem = *nextitem.next;
	}

}

int sortedSingle::retrievePosition(int item)
{

	int index = 1;

	node nextitem;

	if (headptr == nullptr)
	{
		return 0;
	}

	nextitem = *headptr;

	while (true)
	{
		if (nextitem.theItem == item)
		{
			return index;
		}

		if (nextitem.next == nullptr)
		{
			return 0;
		}

		nextitem = *nextitem.next;
		index++;
	}
	
}

sortedSingle::~sortedSingle()
{
	node* nextItem, * previousItem, tmpItem;

	if (headptr == nullptr)
	{
		return;
	}

	nextItem = headptr;

	while (true)
	{

		tmpItem = *nextItem;

		if (tmpItem.next == nullptr)
		{
			break;
		}

		previousItem = nextItem;

		nextItem = tmpItem.next;

		delete previousItem;
	}

	delete nextItem;
}