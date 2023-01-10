/** ***************************************************************************
* @file
******************************************************************************/

#pragma once

#include <iostream>
#include <random>
#include <queue>
#include <fstream>
#include <algorithm>
#include <string>

/**
*
* @brief the structure holding the card values
*
*/
struct card
{
    int faceValue = 0; /**<the suit of the card.
    determined by taking the 52 integer representation of the card and finding
    remainder after dividing by 13 13*/
    int suit = 0; /**<the face value of the card.
    determined by taking the 52 integer representation of the card and finding
    mod 13*/

    card();

    card(int intRep);

    card& operator =(card& c);

    bool operator ==(card& c);
    bool operator !=(card& c);
    bool operator <=(card& c);
    bool operator >=(card& c);
    bool operator <(card& c);
    bool operator >(card& c);

    int intRep();

    std::string returnCard();


};


/**
 * 
 * @brief a stack class that holds item in alinked list style format.
 */
template <class TY> 
class stack
{
    public:

	    stack();
        stack(const stack& s);
	    ~stack();

        bool push(TY item);
        bool pop(TY& item); // nullptr if empty
        bool top(TY& item); //nullptr if empty
        int size();
        bool empty();
        stack& operator=(stack &s);
        void swap(stack<TY> s);
        void clear();

    private:

        /**
         * @brief a way to store each element within the stack
         */
        struct node {
            TY theItem; /**<item contained within this node*/
            node* prev = nullptr; /**< the previous node*/
            node* next = nullptr; /**< the next node*/
        };

        node* headptr; /**<the first node in the queue*/
};

int runTestCases();

void playRound(std::queue<card>& player1, std::queue<card>& player2);

void generateDeck(std::queue<card>& player1, int seed);

bool readInDeck(std::queue<card>& player1, std::string fileLocation);

std::ostream& operator<<(std::ostream& out, card c);

std::ostream& operator<<(std::ostream& out, stack<card> s);

std::ostream& operator<<(std::ostream& out, std::queue<card> s);



/**
 * @author Oliver Schwab
 * 
 * @par Description  clears the stack
 * 
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * stack<card> a;
 * 
 * a.clear()
 * 
 * @endverbatim
 */
template<class TY>
void stack<TY>::clear()
{
    node* curr = headptr, *prev=headptr;

    if (curr == nullptr)
    {
        return;
    }

    prev = curr;

    curr = curr->next;

    delete prev;

    while (curr != nullptr)
    {
        prev = curr;

        curr = curr->next;

        delete prev;
    }

    headptr = nullptr;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description Equal operator for the stack class, performs a deep copy
 * 
 * @param[in] s the stack to 'copy' into the current stack
 * 
 * @return stack<TY>& the new copy stack
 * 
 * @par Example
 * @verbatim
 * 
 * stack<card> a, b;
 * 
 * a.push(card(10));
 * 
 * b = a; // b now contains the card 10
 * 
 * @endverbatim
 */
template<class TY>
stack<TY>& stack<TY>::operator=(stack &s)
{

    node* tmp;
    card tmpCard;

    // clear up current items in stack to manage memory.
    if (!empty()) 
    {

        tmp = headptr->next;
        // while there are still nodes in the stack delete them
        while (tmp->next != nullptr)
        {
            delete tmp->prev;
            tmp = tmp->next;
            //step to next node
        }

        delete tmp;

    }

    if (s.headptr == nullptr) // stack to copy is empty we are done
    { 
        headptr = nullptr;
    }

    else // have items to copy
    {
        tmp = s.headptr;
        // iterate to end of stack so we can use push method.
        while (tmp->next != nullptr) 
        {
            tmp = tmp->next;
        }
        // for item in the given stack push the item on the current stack
        while (tmp != nullptr)
        {
            tmpCard = tmp->theItem;

            push(tmpCard);

            tmp = tmp->prev;
        }
    }

    return *this; // the stack that has the copied items
}


/**
 * @author Oliver Schwab
 * 
 * @par Description Removes the top item on the stack, 
 * assigns the passed in value the item that was on the top.
 * 
 * @param[in, out] item item to copy the pop'ed item into
 * 
 * @return bool if the operation was succseful, 
 * will return false if stack is empty
 * 
 * @par Example
 * @verbatim
 * 
 * stack<card> a;
 * 
 * a.push(card(10));
 * 
 * card b;
 * 
 * a.pop(b); // be would now contain the card 10
 * @endverbatim
 */
template<class TY>
bool stack<TY>::pop(TY& item)
{

    node* tmp;

    if (empty()) // error checking for empty stack
    {
        return false;
    }
    tmp = headptr;
    // item to return
    item = headptr->theItem;
    // reassigning headptr
    headptr = headptr->next;
    // item to opo is the previous node
    //delete headptr->prev;
    // clean up node
    if (headptr != nullptr) 
    {
        headptr->prev = nullptr;
    }
    delete tmp;

    return true;

}


/**
 * @author Oliver Schwab
 * 
 * @par Description Assigns the top card of the stack to the passed in varible
 * if the stack is not empty, otherwise will not modify varible.
 * 
 * @param[in, out] item item to assign value to
 * 
 * @return bool true if operation was sucsseful, otherwise false
 * 
 * @par Example
 * @verbatim
 * 
 * stack<card> a;
 * 
 * a.push(card(10));
 * 
 * card b;
 * 
 * a.top(b); // b would not contain the card 10H
 * 
 * @endverbatim
 */
template<class TY>
bool stack<TY>::top(TY& item)
{

    if (empty())
    {
        return false;
    } 

    else
    {
        item = headptr->theItem;
        return true;
    }

}


/**
 * @author Oliver Schwab
 * 
 * @par Description Determines the number of items in the stack.
 * 
 * 
 * @return int the number of items in the stack
 * 
 * @par Example
 * @verbatim
 * 
 * stack<card> a;
 * 
 * a.push(card(10));
 * 
 * a.size(); would return 10
 * 
 * @endverbatim
 */
template<class TY>
int stack<TY>::size()
{
    int size = 0;

    node* tmp = headptr;
    // count the number of nodes
    while (tmp != nullptr)
    {
        tmp = tmp->next;
        size++;
    }

    return size;
}


/**
 * @author Oliver Schwab
 * 
 * @par Description Determines if the stack is empty
 * 
 * 
 * @return bool true if the stack is empty
 * 
 * @par Example
 * @verbatim
 * 
 * stack<card> a;
 * 
 * a.empty(); // would return true
 * 
 * a.push(card(10));
 * 
 * a.empty(); // would return false
 * 
 * @endverbatim
 */
template<class TY>
bool stack<TY>::empty()
{
    return headptr == nullptr;
}


/**
 * @author Oliver Schwab
 * 
 * @par Description Swaps the contents of the current 
 * stack with the passed in stack.
 * 
 * @param[in, out] s stack to swap values with
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * stack<card> a, b;
 * 
 * a.push(card());
 * 
 * b.push(card(10));
 * 
 * a.swap(b); // a would now contain the 10H and b would contain nothing
 * 
 * @endverbatim
 */
template<class TY>
void stack<TY>::swap(stack<TY> s)
{
    // only need to swap the headptr as they all point to the 
    // nodes in their respective lists
    node* tmp = headptr;

    headptr = s.headptr;

    s.headptr = tmp;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description Construct a new stack<T Y>::stack object
 * 
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * stack<card> a;
 * 
 * @endverbatim
 */
template<class TY>
stack<TY>::stack()
{
    // intialize stack with no items in stack
    headptr = nullptr;

}

/**
 * @author Oliver Schwab
 * 
 * @par Description Construct a new stack<TY>::stack object 
 * and copys the contents of the passed in stack.
 * performs a deep copy
 * 
 * @param[in] s the stack to copy
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * stack<card> a;
 * 
 * a.push(card);
 * 
 * stack<card> b = stack(a); // b would now contain the 10H
 * 
 * @endverbatim
 */
template<class TY>
stack<TY>::stack(const stack& s)
{

    node* tmp = nullptr, *toAdd = nullptr, *prev = nullptr;

    // if stack to copy is empty there is nothing to copy
    // intialize stack with nullptr
    if (s.headptr == nullptr) 
    {
        headptr = nullptr;

        return;
    }

    // create intial node
    toAdd = new (std::nothrow) node();

    if (toAdd == nullptr)
    {
        std::cout << "Memory allocation error" << std::endl;
        exit(0);
    }
    
    //initial copy setup as there will be at least one item in stack to copy
    toAdd->theItem = s.headptr->theItem;

    headptr = toAdd;

    prev = headptr;

    tmp = s.headptr->next;
    // iterate through all nodes in stack to copy
    while (tmp != nullptr)
    {  
        // need a new node in memeory for every item in stack to copy
        toAdd = new (std::nothrow) node();
        // make sure memory was allocated
        if (toAdd == nullptr)
        {
            std::cout << "Memory allocation error" << std::endl;
            exit(0);
        }
        // copy all related item into new node
        toAdd->theItem = tmp->theItem;
        // make sure to maintain prev node
        toAdd->prev = prev;

        toAdd->next = nullptr;
        // make sure previous node points to the next node
        prev->next = toAdd;

        prev = toAdd;

        tmp = tmp->next;
    }

}


/**
 * @author Oliver Schwab
 * 
 * @par Description Destroy the stack<T Y>::stack object
 * 
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * stack<card> a;
 * 
 * @endverbatim
 */
template<class TY>
stack<TY>::~stack()
{
    node *tmp, *prev;

    tmp = headptr;

    if (empty()) // if stack is empty nothing needs to be done
    {
        return;
    }
    // step through every node and delete them

    prev = tmp;

    tmp = tmp->next;
    while (tmp != nullptr)
    {
        delete prev;

        prev = tmp;

        tmp = tmp->next;
    }

    delete prev;

    headptr = nullptr;
}


/**
 * @author Oliver Schwab
 * 
 * @par Description Add the passed in item to the top of the stack
 * 
 * @param[in] item the item to add to the top of the stack
 * 
 * @return bool if operation was succsesful
 * 
 * @par Example
 * @verbatim
 * 
 * stack<card> a;
 * 
 * a.push(card());
 * 
 * a.push(card(10)); 
 * // a would now contain 10H at the top and AH following the 10H
 * 
 * @endverbatim
 */
template<class TY>
bool stack<TY>::push(TY item)
{

    TY* toInsert = new (std::nothrow) TY(item);

    node* n = new (std::nothrow) node;

    // make sure memory was properly allocated 
    // for both the new node and new item
    if (toInsert == nullptr) 
    {
        std::cout << "Memory allocation error" << std::endl;
        return false;
    }

    if (n == nullptr)
    {
        std::cout << "Memory allocation error" << std::endl;
        return false;
    }

    //copy the item
    *toInsert = item;

    n->theItem = *toInsert;
    // intialize node
    n->prev = nullptr;
    n->next = nullptr;

    if (empty())
    {
        headptr = n; // nothing needs to be done but add node to stack
    }

    else
    { // add to stack and appropriatly assign pointers
        n->next = headptr;
        n->next->prev = n;
        headptr = n;
    }

    return true;

}

