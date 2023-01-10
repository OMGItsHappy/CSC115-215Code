/** ***************************************************************************
* @file
******************************************************************************/

#include "thpe3.h"

// write functions here
/**
 * @author Oliver Schwab
 * 
 * @par Description Sorts a given array using the bubble sort method
 * Sorted into ascending order
 * 
 * @param[in] array the array to sort
 * @param[in] size the size of the given array
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * int array[5] = {5,4,3,2,1};
 * 
 * sort(array, 5); / array = {1,2,3,4,5}
 * 
 * int array1[6] = {327,23,78,22,1,3};
 * 
 * sort(array1, 6); // array = {1,3,22,23,78,327}
 * 
 * @endverbatim
 */
void sort(int array[], int size)
{

    int i;
    int j;
    int temp;

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[i])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

/**
 * @author Oliver Schwab
 * 
 * @par given an already populated hand of five cards this function determines
 * if it contains a royal flush
 * 
 * @param[in] hand an array of 5 integers representing a poker hand
 * 
 * @return A boolean indicating if the hand contains a royal flush
 * 
 * @par Example
 * @verbatim
 * 
 * int hand[5] = {13, 22, 23, 24, 25};
 *
 * bool result = findRoyalFlush(hand);  // result = true
 * 
 * int hand[5] = {13, 22, 23, 24, 15};
 *
 * bool result = findRoyalFlush(hand); // result = false
 * 
 * @endverbatim
 */
bool findRoyalFlush(int hand[])
{

    int i;
    int z;
    int sum = 0;
    int suit = hand[0] / 13;
    int rqCards[] = {suit * 13, suit * 13 + 9, suit * 13 + 10,
                     suit * 13 + 11, suit * 13 + 12};

    for (i = 0; i < 5; i++)
    {
        for (z = 0; z < 5; z++)
        {
            if (hand[i] == rqCards[z])
            {
                rqCards[z] = -1;
                sum++;
            }
        }
    }

    return sum == 5;
}


/**
 * @author Oliver Schwab
 * 
 * @par given an already populated hand of five cards this function determines
 * if it contains a Straight Flush 
 * 
 * @param[in] hand an array of 5 integers representing a poker hand 
 * 
 * @return A boolean indicating if the hand contains a royal flush
 * 
 * @par Example
 * @verbatim
 * 
 * int hand[5] = {0,1,2,3,4};
 *
 * bool result = findStraightFlush(hand); // result = true
 * 
 * int hand[5] = {0,1,2,3,6};
 *
 * bool result = findStraightFlush(hand); // result = false
 * 
 * @endverbatim
 */
bool findStraightFlush(int hand[])
{
    int i, suit;

    sort(hand, 5);
    suit = hand[0]/13;
    for (i = 1; i < 5; i++)
    {
        if (hand[i - 1] + 1 != hand[i] || hand[i]/13 != suit)
        {
            return false;
        }
    }

    return true;
}


/**
 * @author Oliver Schwab
 * 
 * @par given an already populated hand of five cards this function determines
 * if it contains a Four of a Kind
 * 
 * @param[in] hand an array of 5 integers representing a poker hand
 * 
 * @return A boolean indicating if the hand contains a Four of a Kind
 * 
 * @par Example
 * @verbatim
 * 
 * int hand[5] = {0,13,26,39, 2};
 *
 * bool result = findFourOfAKind(hand); // result = true
 * 
 * int hand[5] = {1,2,3,4,6};
 *
 * bool result = findFourOfAKind(hand); // result = false
 * 
 * @endverbatim
 */
bool findFourOfAKind(int hand[])
{
    int i, z, sum;
    sum = 0;
    for (i = 0; i < 5; i++)
    {
        for (z = 0; z < 5; z++)
        {
            if (hand[i] % 13 == hand[z] % 13 && i != z)
            {
                sum++;
            }
        }

        if (sum == 3)
        {
            return true;
        }

        sum = 0;
    }

    return false;
}


/**
 * @author Oliver Schwab
 * 
 * @par given an already populated hand of five cards this function determines
 * if it contains a three of a kind
 * 
 * @param[in] hand an array of 5 integers representing a poker hand
 * 
 * @return A boolean indicating if the hand contains a three of a kind
 * 
 * @par Example
 * @verbatim
 * 
 * int hand[5] = {0,13,26,2,3};
 *
 * bool result = findThreeOfAKind(hand); // result = true
 * 
 * int hand[5] = {1,2,3,4,14};
 *
 * bool result = findThreeOfAKind(hand); // result = false
 * 
 * @endverbatim
 */
bool findThreeOfAKind(int hand[])
{
    int i, z, sum;
    sum = 0;
    for (i = 0; i < 5; i++)
    {
        for (z = 0; z < 5; z++)
        {
            if (hand[i] % 13 == hand[z] % 13 && i != z)
            {
                sum++;
            }
        }

        if (sum == 2)
        {
            return true;
        }

        sum = 0;
    }

    return false;
}


/**
 * @author Oliver Schwab
 * 
 * @par given an already populated hand of five cards this function determines
 * if it contains a two of a kind
 * 
 * @param[in] hand an array of 5 integers representing a poker hand
 * 
 * @return A boolean indicating if the hand contains a two of a kind
 * 
 * @par Example
 * @verbatim
 * 
 * int hand[5] = {0, 13, 2,3,4};
 *
 * bool result = findTwoOfAKind(hand); // result = true
 * 
 * int hand[5] = {0, 4, 3, 5,6};
 *
 * bool result = findTwoOfAKind(hand); // result = false
 * 
 * @endverbatim
 */
bool findTwoOfAKind(int hand[])
{
    int i, z, sum, pairsFound;
    sum = 0;
    pairsFound = 0;
    for (i = 0; i < 5; i++)
    {
        for (z = 0; z < 5; z++)
        {
            if (hand[i] % 13 == hand[z] % 13 && i != z)
            {
                sum++;
            }
        }

        if (sum == 1)
        {
            pairsFound++;
        }

        sum = 0;
    }

    return pairsFound == 2;

}


/**
 * @author Oliver Schwab
 * 
  * @par given an already populated hand of five cards this function determines
 * if it contains a Full house
 * 
 * @param[in] hand an array of 5 integers representing a poker hand
 * 
 * @return A boolean indicating if the hand contains a Full House
 * 
 * @par Example
 * @verbatim
 * 
 * int hand[5] = {0, 13, 1, 14, 27};

 * bool result = findFullHouse(hand); // result = true
 * 
 * int hand[5] = {0, 13, 1, 14, 5};
 *
 * bool result = findFullHouse(hand); // result = false
 * @endverbatim
 */
bool findFullHouse(int hand[])
{
    return findThreeOfAKind(hand) && findTwoOfAKind(hand);
}


/**
 * @author Oliver Schwab
 * 
 * @par given an already populated hand of five cards this function determines
 * if it contains a Flush
 * 
 * @param[in] hand an array of 5 integers representing a poker hand
 * 
 * @return A boolean indicating if the hand contains a Flush
 * 
 * @par Example
 * @verbatim
 * 
 * int hand[5] = {0,1,2,3,4};
 *
 * bool result = findFlush(hand); // result = true
 * 
 * int hand[5] = {0,1,2,3,14};
 *
 * bool result = findFlush(hand); // result = false
 * 
 * @endverbatim
 */
bool findFlush(int hand[])
{
    int i;

    for (i = 0; i < 5; i++)
    {
        if (hand[i]/13 != hand[0]/13)
        {
            return false;
        }
    }

    return true;
}

/**
 * @author Oliver Schwab
 * 
 * @par given an already populated hand of five cards this function determines
 * if it contains a Straight
 * 
 * @param[in] hand an array of 5 integers representing a poker hand
 * 
 * @return A boolean indicating if the hand contains a Straight
 * 
 * @par Example
 * @verbatim
 * 
 * int hand[5] = {0,1,2,3,4};
 *
 * bool result = findStraight(hand); // result = true
 * 
 * int hand[5] = {0,1,2,3,6};
 *
 * bool result = findStraight(hand); // result = false
 * 
 * @endverbatim
 */
bool findStraight(int hand[])
{
    int tempHand[5];
    int i, low = 0, high = 0;
    int sum = 0;

    int lowStraight[5] = {0, 1, 2, 3, 4};
    int highStraight[5] = {0, 9, 10, 11, 12};

    for (i = 0; i < 5; i++)
    {
        tempHand[i] = hand[i]%13;
        sum += hand[i] % 13;
    }

    sort(tempHand, 5);

    for (i = 0; i < 5; i++)
    {
        if (lowStraight[i] == tempHand[i]) low++;

        if (highStraight[i] == tempHand[i]) high++;
    }

    if (low == 5 || high == 5) return true;

    sum = 0;

    for (i = 0; i < 4; i++)
    {
        if (tempHand[i] == tempHand[i + 1] - 1)
        {
            sum++;
        }
    }

    return sum == 4;
    
}

/**
 * @author Oliver Schwab
 * 
 * @par given an already populated hand of five cards this function determines
 * if it contains a two pair
 * 
 * @param[in] hand an array of 5 integers representing a poker hand
 * 
 * @return A boolean indicating if the hand contains a two pair
 * 
 * @par Example
 * @verbatim
 * 
 * int hand[5] = {0, 13, 1, 14, 5};
 *
 * bool result = findTwoPair(hand); // result = true
 * 
 * int hand[5] = {0, 13, 1, 15, 5};
 *
 * bool result = findTwoPair(hand); // result = false
 * 
 * @endverbatim
 */
bool findTwoPair(int hand[])
{
    
    int i, z, sum, pairsFound;
    sum = 0;
    pairsFound = 0;
    for (i = 0; i < 5; i++)
    {
        for (z = 0; z < 5; z++)
        {
            if (hand[i] % 13 == hand[z] % 13 && i != z)
            {
                sum++;
            }
        }

        if (sum == 1)
        {
            pairsFound++;
        }

        sum = 0;
    }

    return pairsFound == 4;
}

/**
 * @author Oliver Schwab
 * 
 * @par Given a populated hand of five cards it will return a numeber
 * from 0 to 9 indicating what hand is passed in.
 * 
 * @param[in] hand an array of 5 integers representing a poker hand
 * @param[in] size the size of the array passed in
 * 
 * @return int representing the hand
 * 
 * @par Example
 * @verbatim
 * 
 * int hand[5] = {0,13, 26, 6,7};
 *
 * int result = classifyHand(hand, 5); // result = 3
 * 
 * int hand[5] = {0,1,2,3,4};
 *
 * int result = classifyHand(hand, 5); // result = 8
 * 
 * @endverbatim
 */
int classifyHand(int hand[], int size)
{

    size;

    if (findRoyalFlush(hand)) return ROYALFLUSH;

    if (findStraightFlush(hand)) return STRAIGHTFLUSH;

    if (findFourOfAKind(hand)) return FOUROFAKIND;

    if (findFullHouse(hand)) return FULLHOUSE;

    if (findFlush(hand)) return FLUSH;

    if (findStraight(hand)) return STRAIGHT;

    if (findThreeOfAKind(hand)) return THREEOFAKIND;

    if (findTwoPair(hand)) return TWOPAIR;

    if (findTwoOfAKind(hand)) return TWOOFAKIND;

    return HIGHCARD;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description searches through the given array trying to find
 * the given int.
 * 
 * @param[in] array an integer array to search through
 * @param[in] size the size of the array
 * @param[in] toSearch the int to find within the array
 * 
 * @return A boolean indicating if the given integer was found
 * 
 * @par Example
 * @verbatim
 * 
 * int array[5] = {1,2,3,4,5};
 * 
 * bool result = search(arrray, 5, 4); // result = true
 * 
 * int array[7] = {5,8,2,9,2,4, 6};
 * 
 * result = search(array, 7, 10); // result = false
 * 
 * @endverbatim
 */
bool search(int array[], int size, int toSearch)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (toSearch == array[i]) return true;
    }

    return false;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description Writes the output of all the 10 hands classified
 * to the given file.
 * 
 * @param[in] outFile the file to write to
 * @param[in] handsDelt the list of hands that were dealt
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * int hands[10] = {1,2,3,4,5,6,7,8,9};
 * ofstream file;
 * file.open("file path");
 * 
 * writeOutput(file, hands);
 * 
 * @endverbatim
 */
void writeOutput(ofstream& outFile, int handsDelt[])
{
    double sum = 0; 
    int i;

    for (i = 0; i < 10; i++) 
    {
        sum += handsDelt[i];
    }

    outFile << fixed; 
    outFile << showpoint;
    outFile << setprecision(6);

    handsDelt;
    outFile << left << setw(20) << "Hand Name" << right << setw(10) << "Dealt" << setw(15) << "Chance" << endl;
    outFile << left << setw(20) << "Royal Flush" << right << setw(10) <<handsDelt[9] << setw(15) << (((double) handsDelt[9]/sum)*100) << "%\n";
    outFile << left << setw(20) << "Straight Flush" << right << setw(10) <<handsDelt[8] << setw(15) << ((double) handsDelt[8]/sum)*100 << "%\n";
    outFile << left << setw(20) << "Four of a Kind" << right << setw(10) <<handsDelt[7] << setw(15) << ((double) handsDelt[7]/sum)*100 << "%\n";
    outFile << left << setw(20) << "Full House" << right << setw(10) <<handsDelt[6] << setw(15) << ((double) handsDelt[6]/sum)*100 << "%\n";
    outFile << left << setw(20) << "Flush" << right << setw(10) <<handsDelt[5] << setw(15) << ((double) handsDelt[5]/sum)*100 << "%\n";
    outFile << left << setw(20) << "Straights" << right << setw(10) <<handsDelt[4] << setw(15) << ((double) handsDelt[4]/sum)*100 << "%\n";
    outFile << left << setw(20) << "Three of a Kind" << right << setw(10) <<handsDelt[3] << setw(15) << ((double) handsDelt[3]/sum)*100 << "%\n";
    outFile << left << setw(20) << "Two Pair" << right << setw(10) <<handsDelt[2] << setw(15) << ((double) handsDelt[2]/sum)*100 << "%\n";
    outFile << left << setw(20) << "Two of a Kind" << right << setw(10) <<handsDelt[1] << setw(15) << ((double) handsDelt[1]/sum)*100 << "%\n";
    outFile << left << setw(20) << "High Card" << right << setw(10) <<handsDelt[0] << setw(15) << ((double) handsDelt[0]/sum)*100 << "%\n\n";
    outFile << noshowpoint << fixed << setprecision(0);
    outFile << left << setw(20) << "Total Hands Dealt" << right << setw(10) << sum << "\n";

    outFile.close();
}

/**
 * @author Oliver Schwab
 * 
 * @par Description Writes the output of all the 10 hands classified
 * to the given file.
 * 
 * @param[in] handsDelt the list of hands that were dealt
 *  
 * 
 * @par Example
 * @verbatim
 * 
 * int hands[10] = {1,2,3,4,5,6,7,8,9};
 * 
 * printOutput(hands);
 * 
 * @endverbatim
 */
void printOutput(int handsDelt[])
{
    {
    double sum = 0; 
    int i;

    for (i = 0; i < 10; i++) 
    {
        sum += handsDelt[i];
    }

    cout << fixed; 
    cout << showpoint;
    cout << setprecision(6);

    handsDelt;
    cout << left << setw(20) << "Hand Name" << right << setw(10) << "Dealt" << setw(15) << "Chance" << endl;
    cout << left << setw(20) << "Royal Flush" << right << setw(10) <<handsDelt[9] << setw(15) << (((double) handsDelt[9]/sum)*100) << "%\n";
    cout << left << setw(20) << "Straight Flush" << right << setw(10) <<handsDelt[8] << setw(15) << ((double) handsDelt[8]/sum)*100 << "%\n";
    cout << left << setw(20) << "Four of a Kind" << right << setw(10) <<handsDelt[7] << setw(15) << ((double) handsDelt[7]/sum)*100 << "%\n";
    cout << left << setw(20) << "Full House" << right << setw(10) <<handsDelt[6] << setw(15) << ((double) handsDelt[6]/sum)*100 << "%\n";
    cout << left << setw(20) << "Flush" << right << setw(10) <<handsDelt[5] << setw(15) << ((double) handsDelt[5]/sum)*100 << "%\n";
    cout << left << setw(20) << "Straights" << right << setw(10) <<handsDelt[4] << setw(15) << ((double) handsDelt[4]/sum)*100 << "%\n";
    cout << left << setw(20) << "Three of a Kind" << right << setw(10) <<handsDelt[3] << setw(15) << ((double) handsDelt[3]/sum)*100 << "%\n";
    cout << left << setw(20) << "Two Pair" << right << setw(10) <<handsDelt[2] << setw(15) << ((double) handsDelt[2]/sum)*100 << "%\n";
    cout << left << setw(20) << "Two of a Kind" << right << setw(10) <<handsDelt[1] << setw(15) << ((double) handsDelt[1]/sum)*100 << "%\n";
    cout << left << setw(20) << "High Card" << right << setw(10) <<handsDelt[0] << setw(15) << ((double) handsDelt[0]/sum)*100 << "%\n\n";
    cout << noshowpoint << fixed << setprecision(0);
    cout << left << setw(20) << "Total Hands Dealt" << right << setw(10) << sum << "\n";
    
    cout << defaultfloat;
}
}