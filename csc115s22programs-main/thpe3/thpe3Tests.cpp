#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "thpe3.h" 

const bool RUNCATCH = false;
uniform_int_distribution<int> deck(0,51);


int main(int argc, char **argv)
{
    Catch::Session session;
    int result, i;
    int handsRecived[10] = {0,0,0,0,0,0,0,0,0,0};
    if (RUNCATCH) 
    {
        result = session.run();
        if (result != 0)
        {
            cout << "Test cases didn't pass." << endl;
            return result;
        }
    }

    if (argc != 4)
    {
        cout << "Usage: thpe3.exe -s seedValue quantity\n"
        << "       seedValue - # is integer for random numbers\n"
        << "       quantity - # of hands to deal\n\n"
        << "       thpe3.exe -f inputfilename outputfilename\n"
        << "       inputfilename - filename containing the poker hands to classify\n"
        << "       outputfilename - filename to output the statistics in";
        exit(0);
    }

    if (strcmp(argv[1], "-s") != 0 && strcmp(argv[1], "-f") != 0)
    {
        cout << "Invalid Option";
        exit(0);
    }

    if (strcmp(argv[1], "-s") == 0)
    {
        int z, tempNum;
        int tempHand[] = {-1,-1,-1,-1,-1};
        int seed = stoi(argv[2]);
        static default_random_engine engine( seed );
        int hands = stoi(argv[3]);

        for (z = 0; z < hands; z++)
        {
            for (i = 0; i < 5; i++)
            {
                tempNum = deck(engine);
                while (search(tempHand, 5, tempNum)) tempNum = deck(engine);
                tempHand[i] = tempNum;
            }

            handsRecived[classifyHand(tempHand, 5)]++;
            for (i = 0; i < 5; i++) tempHand[i] = -1;
        }

        printOutput(handsRecived);
    }

    else
    {
        ifstream inFile;
        ofstream outFile;

        inFile.open(argv[2]);

        if (!inFile.is_open())
        {
            cout << "Unable to open the file: " << argv[2];
            exit(0);
        }

        outFile.open(argv[3]);

        if (!outFile.is_open())
        {
            cout << "Unable to open the file: " << argv[3];
            exit(0);
        }

        int tempNum;
        int tempHand[5];

        i = 0;
        while (inFile >> tempNum)
        {
            tempHand[i] = tempNum;

            i++;

            if (i == 5)
            {
                i = 0;

                handsRecived[classifyHand(tempHand, 5)]++;
            }
        }

        writeOutput(outFile, handsRecived);
        inFile.close();

    }

    
    return 0;
}


TEST_CASE("findRoyalFlush - intial test case")
{
    int hand[5] = {1,2,3,4,5};

    bool result = findRoyalFlush(hand);

    REQUIRE(result == false);
}


TEST_CASE("findRoyalFlush - testing royal flush")
{
    int hand[5] = {13, 22, 23, 24, 25};

    bool result = findRoyalFlush(hand); 

    REQUIRE(result == true);
}


TEST_CASE("findRoyalFlush - invalid royal flush")
{
    int hand[5] = {13, 22, 23, 24, 15};

    bool result = findRoyalFlush(hand);

    REQUIRE(result == false);
}


TEST_CASE("findRoyalFlush - another royalFlush")
{
    int hand[5] = {0, 9,10,11,12};

    bool result = findRoyalFlush(hand); 

    REQUIRE(result == true);
}


// straight flush


TEST_CASE("findStraightFlush - intial test case")
{
    int hand[5] = {0,1,2,3,4};

    bool result = findStraightFlush(hand);

    REQUIRE(result == true);
}


TEST_CASE("findStraightFlush - invalid test case")
{
    int hand[5] = {0,1,2,3,6};

    bool result = findStraightFlush(hand);

    REQUIRE(result == false);
}


TEST_CASE("findStraightFlush - unsorted valid straight flush")
{
    int hand[5] = {45, 46, 44, 47, 48};

    bool result = findStraightFlush(hand);

    REQUIRE(result == true);
}


// four of a kind


TEST_CASE("findFourOfAKind - intial test case with a four of a kind")
{
    int hand[5] = {0,13,26,39, 2};

    bool result = findFourOfAKind(hand);

    REQUIRE(result == true);
}


TEST_CASE("findFourOfAKind - not a match")
{
    int hand[5] = {1,2,3,4,6};

    bool result = findFourOfAKind(hand);

    REQUIRE(result == false);
}


TEST_CASE("findFourOfAKind - a four of a kind out of order")
{
    int hand[5] = {46, 7, 33, 20, 2};

    bool result = findFourOfAKind(hand);

    REQUIRE(result == true);
}


TEST_CASE("findFourOfAKind - three of a kind")
{
    int hand[5] = {46, 7, 33, 21, 2};

    bool result = findFourOfAKind(hand);

    REQUIRE(result == false);
}


// three of a kind


TEST_CASE("findThreeOfAKind - intial test case with valid three of a kind")
{
    int hand[5] = {0,13,26,2,3};

    bool result = findThreeOfAKind(hand);

    REQUIRE(result == true);
}


TEST_CASE("findThreeOfAKind - two pair")
{
    int hand[5] = {1,2,3,4,14};

    bool result = findThreeOfAKind(hand);

    REQUIRE(result == false);
}


TEST_CASE("findThreeOfAKind - valid three of a kind")
{
    int hand[5] = {3,16,29,2,4};

    bool result = findThreeOfAKind(hand);

    REQUIRE(result == true);
}


//two of a kind

TEST_CASE("findTwoOfAKind - intial test case for two of a kind")
{
    int hand[5] = {0, 13, 2,3,4};

    bool result = findTwoOfAKind(hand);

    REQUIRE(result == true);
}


TEST_CASE("findTwoOfAKind - no pairs")
{
    int hand[5] = {0, 4, 3, 5,6};

    bool result = findTwoOfAKind(hand);

    REQUIRE(result == false);
}


TEST_CASE("findTwoOfAKind - testing two pairs")
{
    int hand[5] = {0, 13, 1, 14, 5};

    bool result = findTwoOfAKind(hand);

    REQUIRE(result == false);
}


// full house


TEST_CASE("findFullHouse - intial test case")
{
    int hand[5] = {0, 13, 1, 14, 27};

    bool result = findFullHouse(hand);

    REQUIRE(result == true);
}


TEST_CASE("findFullHouse - two pair")
{
    int hand[5] = {0, 13, 1, 14, 5};

    bool result = findFullHouse(hand);

    REQUIRE(result == false);
}


TEST_CASE("findFullHouse - three pair")
{
    int hand[5] = {0, 13, 26, 5, 6,};

    bool result = findFullHouse(hand);

    REQUIRE(result == false);
}


TEST_CASE("findFullHouse - valid full house")
{
    int hand[5] = {0, 13, 1, 14, 27};

    bool result = findFullHouse(hand);

    REQUIRE(result == true);
}


// flush


TEST_CASE("findFlush - intial test case with valid flush")
{
    int hand[5] = {0,1,2,3,4};

    bool result = findFlush(hand);

    REQUIRE(result == true);
}


TEST_CASE("findFlush - 4 cards in suit")
{
    int hand[5] = {0,1,2,3,14};

    bool result = findFlush(hand);

    REQUIRE(result == false);
}


TEST_CASE("findFlush - 3 cards in suit")
{
    int hand[5] = {0,1,2,14, 15};

    bool result = findFlush(hand);

    REQUIRE(result == false);
}


TEST_CASE("findFlush - valid flush")
{
    int hand[5] = {13, 16, 18, 20, 22};

    bool result = findFlush(hand);

    REQUIRE(result == true);
}


// straight


TEST_CASE("findStraight - intial test case")
{
    int hand[5] = {0,1,2,3,4};

    bool result = findStraight(hand);

    REQUIRE(result == true);
}


TEST_CASE("findStraight - 4 in a row")
{
    int hand[5] = {0,1,2,3,6};

    bool result = findStraight(hand);

    REQUIRE(result == false);
}


TEST_CASE("findStraight - 10-K without ace")
{
    int hand[5] = {9, 10, 11, 12, 2};

    bool result = findStraight(hand);

    REQUIRE(result == false);
}


TEST_CASE("findStraight - 2-5 without ace")
{
    int hand[5] = {6,1,2,3,4};

    bool result = findStraight(hand);

    REQUIRE(result == false);
}

TEST_CASE("findStraight - ace high straight")
{
    int hand[5] = {9,10,11,12,0};

    bool result = findStraight(hand);

    REQUIRE(result == true);
}


TEST_CASE("findStraight - ace low straight")
{
    int hand[5] = {0,1,2,3,4};

    bool result = findStraight(hand);

    REQUIRE(result == true);
}


TEST_CASE("findStraight - normal straight")
{
    int hand[5] = {34,35,36,37,38};

    bool result = findStraight(hand);

    REQUIRE(result == true);
}


TEST_CASE("findStraight - normal straight second test")
{
    int hand[5] = {42,43,44,45,46};

    bool result = findStraight(hand);

    REQUIRE(result == true);
}


// two pair


TEST_CASE("findTwoPair - initial test case with valid two pair")
{
    int hand[5] = {0, 13, 1, 14, 5};

    bool result = findTwoPair(hand);

    REQUIRE(result == true);
}

TEST_CASE("findTwoPair - one pair")
{
    int hand[5] = {0, 13, 1, 15, 5};

    bool result = findTwoPair(hand);

    REQUIRE(result == false);
}


TEST_CASE("findTwoPair - three of a kind")
{
    int hand[5] = {0, 13, 1, 14, 5};

    bool result = findTwoPair(hand);

    REQUIRE(result == true);
}


TEST_CASE("findTwoPair - two pair")
{
    int hand[5] = {4, 17, 6, 19, 5};

    bool result = findTwoPair(hand);

    REQUIRE(result == true);
}


// classify hand


TEST_CASE("classifyHand - intial test case, high card")
{
    int hand[5] = {0, 14, 28, 42, 49};

    int result = classifyHand(hand, 5);

    REQUIRE(result == HIGHCARD);
}

TEST_CASE("classifyHand - royalFlush")
{
    int hand[5] = {12, 11, 10, 9, 0};

    int result = classifyHand(hand, 5);

    REQUIRE(result == ROYALFLUSH);
}


TEST_CASE("classifyHand - straight flush")
{
    int hand[5] = {0,1,2,3,4};

    int result = classifyHand(hand, 5);

    REQUIRE(result == STRAIGHTFLUSH);
}


TEST_CASE("classifyHand - 4 of a kind")
{
    int hand[5] = {0,13, 26, 39, 4};

    int result = classifyHand(hand, 5);

    REQUIRE(result == FOUROFAKIND);
}


TEST_CASE("classifyHand - full house")
{
    int hand[5] = {0,13, 1, 14, 27};

    int result = classifyHand(hand, 5);

    REQUIRE(result == FULLHOUSE);
}


TEST_CASE("classifyHand - flush")
{
    int hand[5] = {7,1,2,3,4};

    int result = classifyHand(hand, 5);

    REQUIRE(result == FLUSH);
}


TEST_CASE("classifyHand - straight")
{
    int hand[5] = {0,14, 28, 42, 4};

    int result = classifyHand(hand, 5);

    REQUIRE(result == STRAIGHT);
}


TEST_CASE("classifyHand - three of a kind")
{
    int hand[5] = {0,13, 26, 6,7};

    int result = classifyHand(hand, 5);

    REQUIRE(result == THREEOFAKIND);
}


TEST_CASE("classifyHand - two pair")
{
    int hand[5] = {0,13, 1, 14, 6};

    int result = classifyHand(hand, 5);

    REQUIRE(result == TWOPAIR);
}


TEST_CASE("classifyHand - two of a kind")
{
    int hand[5] = {0,13, 5,6, 7};

    int result = classifyHand(hand, 5);

    REQUIRE(result == TWOOFAKIND);
}


TEST_CASE("classifyHand - intial test case")
{
    int hand[5] = {0,1,2,3,4};

    int result = classifyHand(hand, 5);

    REQUIRE(result == STRAIGHTFLUSH);
}


TEST_CASE("classifyHand - invalid test case")
{
    int hand[5] = {0,1,2,3,6};

    int result = classifyHand(hand, 5);

    REQUIRE(result == FLUSH);
}


TEST_CASE("classifyHand - unsorted valid straight flush")
{
    int hand[5] = {45, 46, 44, 47, 48};

    int result = classifyHand(hand, 5);

    REQUIRE(result == STRAIGHTFLUSH);
}