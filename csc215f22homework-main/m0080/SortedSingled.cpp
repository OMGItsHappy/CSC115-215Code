/******************************************************************************
 * @file    
 *
 * @brief   This file is reserved for future use.  Do not edit.
 *****************************************************************************/
#include "sortedSingle.h"


sortedSingle::sortedSingle(sortedSingle& l)
{

    node* toAdd, * toCopy, *prev;

    headptr = nullptr;

    if (l.headptr == nullptr)
    {
        return;
    }

    toAdd = new (nothrow) node();

    toAdd->theItem = l.headptr->theItem;

    toAdd->next = nullptr;

    headptr = toAdd;

    prev = toAdd;

    toCopy = l.headptr->next;

    while (toCopy != nullptr)
    {
        toAdd = new (nothrow) node();

        prev->next = toAdd;

        toAdd->theItem = toCopy->theItem;

        toAdd->next = nullptr;

        toCopy = toCopy->next;

        prev = toAdd;
    }

}
