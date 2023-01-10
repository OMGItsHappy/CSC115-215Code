/** ***************************************************************************
* @file
******************************************************************************/

#include "thpe04.h"


/**
 * @author Oliver Schwab
 * 
 * @par Description outputs card to ostream
 * 
 * @param[in, out] out 
 * @param[in] c 
 * 
 * @return std::ostream& 
 * 
 * @par Example
 * @verbatim
 * 
 * card c;
 * 
 * cout << c;
 * 
 * @endverbatim
 */
std::ostream& operator<<(std::ostream& out, card c)
{
    out << c.returnCard();

    return out;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description Construct a new card::card object
 * 
 * @param[in] intRep The integer representation of a card 0-51 
 * where every 13 cards is a suit with ace's being low. 
 * Suit follows pattern of hearts, diamonds, clubs, spades.
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * card(10); // 10 of hearts
 * 
 * card(50); //11 of spades
 * 
 * @endverbatim
 */
card::card(int intRep)
{

    faceValue = intRep % 13;
    suit = intRep / 13;

}

/**
 * @author Oliver Schwab
 * 
 * @par Description Construct a new card::card object, defaults to ace of hearts
 * 
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * card a = card();
 * 
 * @endverbatim
 */
card::card()
{
    faceValue = 0;
    suit = 0;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description assigns current cards values to given cards values
 * 
 * @param[in] c Card to copy
 * 
 * @return card& the new cad containing the new values
 * 
 * @par Example
 * @verbatim
 * 
 * card a;
 * 
 * card b = card(10);
 * 
 * a = b; // a is now a 10 of hearts
 * 
 * @endverbatim
 */
card& card::operator =(card& c)
{
    faceValue = c.faceValue;
    suit = c.suit;
    return *this;
}


/**
 * @author Oliver Schwab
 * 
 * @par Description Equals operator for card struct, 
 * ignores suit only evaluates face value
 * 
 * @param[in] c the card to compare to
 * 
 * @return bool if the cards are equal
 * 
 * @par Example
 * @verbatim
 * 
 * card a;
 * 
 * card b = card(10);
 * 
 * a == b; // would return false
 * 
 * @endverbatim
 */
bool card::operator ==(card& c)
{
    return faceValue == c.faceValue;
}


/**
 * @author Oliver Schwab
 * 
 * @par Description not Equals operator for card struct, 
 * ignores suit only evaluates face value
 * 
 * @param[in] c the card to compare to
 * 
 * @return bool if the cards are not equal
 * 
 * @par Example
 * @verbatim
 * 
 * card a;
 * 
 * card b = card(10);
 * 
 * a != b; // would return true
 * 
 * @endverbatim
 */
bool card::operator !=(card& c)
{
    return faceValue != c.faceValue;
}


/**
 * @author Oliver Schwab
 * 
 * @par Description less then or Equals operator for card struct, 
 * ignores suit only evaluates face value
 * 
 * @param[in] c the card to compare to
 * 
 * @return bool if the card is less then or equal to the given card
 * 
 * @par Example
 * @verbatim
 * 
 * card a;
 * 
 * card b = card(10);
 * 
 * a <= b; // would return true
 * 
 * @endverbatim
 */
bool card::operator <=(card& c)
{
    return faceValue <= c.faceValue;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description greater then or Equals operator for card struct, 
 * ignores suit only evaluates face value
 * 
 * @param[in] c the card to compare to
 * 
 * @return bool if the card is greater or equal to the given card
 * 
 * @par Example
 * @verbatim
 * 
 * card a;
 * 
 * card b = card(10);
 * 
 * a >= b; // would return false
 * 
 * @endverbatim
 */
bool card::operator >=(card& c)
{
    return faceValue >= c.faceValue;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description outputs stack to ostream
 * 
 * @param[in, out] out the stream to output to
 * @param[in] s the stack to output
 * 
 * @return std::ostream& 
 * 
 * @par Example
 * @verbatim
 * 
 * stack<card> s;
 * 
 * cout << s;
 * 
 * @endverbatim
 */
std::ostream& operator<<(std::ostream& out, stack<card> s)
{
    card c;

    while (!s.empty())
    {
        s.pop(c);

        out << c;

        if (s.size() != 0)
        {
            out << " ";
        }
    }

    return out;
}   

/**
 * @author Oliver Schwab
 * 
 * @par Description outputs queue to ostream
 * 
 * @param[in] out where to output the queue
 * @param[in] s the queue to output
 * 
 * @return std::ostream& 
 * 
 * @par Example
 * @verbatim
 * 
 * @endverbatim
 */
std::ostream& operator<<(std::ostream& out, std::queue<card> s)
{
    card c;

    while (!s.empty())
    {
        c = s.front();

        s.pop();

        out << c;

        if (s.size() != 0)
        {
            out << " ";
        }
    }

    return out;
}


/**
 * @author Oliver Schwab
 * 
 * @par Description less then operator for card struct, 
 * ignores suit only evaluates face value
 * 
 * @param[in] c the card to compare to
 * 
 * @return bool if the card is less then the given card
 * 
 * @par Example
 * @verbatim
 * 
 * card a;
 * 
 * card b = card(10);
 * 
 * a < b; // would return true
 * 
 * a = card(10);
 * 
 * a < b; // would return false
 * @endverbatim
 */
bool card::operator <(card& c)
{
    return faceValue < c.faceValue;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description greater then operator for card struct, 
 * ignores suit only evaluates face value
 * 
 * @param[in] c the card to compare to
 * 
 * @return bool if the card is greater then the given card
 * 
 * @par Example
 * @verbatim
 * 
 * card a;
 * 
 * card b = card(10);
 * 
 * a > b; // would return false
 * 
 * a = card(10);
 * 
 * a > b; // would return false
 * 
 * @endverbatim
 */
bool card::operator >(card& c)
{
    return faceValue > c.faceValue;
}


/**
 * @author Oliver Schwab
 * 
 * @par Description returns the int representation of the card 0-51
 * 
 * 
 * @return int the integere representation
 * 
 * @par Example
 * @verbatim
 * 
 * card a = card(10);
 * 
 * a.intRep(); // would return 10
 * 
 * @endverbatim
 */
int card::intRep() {
    return suit * 13 + faceValue;
}


/**
 * @author Oliver Schwab
 * 
 * @par Description Creates the string representation of the card,
 *  containing the face value and suit.
 * The face values range from 1-12 and A
 * The suit will one of [H, D, C, S] [Hearts, Diamonds, Clubs, Spades]
 * 
 * 
 * @return std::string the string form of the card
 * 
 * @par Example
 * @verbatim
 * 
 * card a;
 * 
 * a.returnCard(); // would return AH
 * 
 * a = card(10);
 * 
 * a.returnCard(); // would return 10H
 * 
 * @endverbatim
 */
std::string card::returnCard()
{
    std::string stringForm = "";

    if (faceValue == 0)
    {
        stringForm += "A";
    }
    else
    {
        stringForm += std::to_string(faceValue + 1);
    }

    if (suit == 0)
    {
        stringForm += "H";
    }

    else if (suit == 1)
    {
        stringForm += "D";
    }

    else if (suit == 2)
    {
        stringForm += "C";
    }

    else if (suit == 3)
    {
        stringForm += "S";
    };

    return stringForm;
}

