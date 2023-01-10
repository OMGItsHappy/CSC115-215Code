/** ***************************************************************************
* @file
*
* @brief Plays a game of war with either passed in starting decks 
* or randomly generated decks based on passed in seed for the generator.
******************************************************************************/

/** ***************************************************************************
*
* @mainpage thpe04 - War
*
* @section course_section Course Information
*
* @authors Oliver Schwab
*
* @date December 8th, 2022
*
* @par Instructor
*          Dr. Schrader
*
* @par Course
*          CSC 215 - Section 1 - 2:00 pm
*
* @par Location
*          Classroom Building - Room 112
*
* @section program_section Program Information
*
* @details This program plays a game of war. 
* The decks used for each player are dependent on the command line arguments.
* If -s is given for the input type the following two commands are the seeds
* to generate each deck with, with the first seed coresponding to player one, 
* and the second corresponding to player 2.
* If -f is specified the the following two arguments are files containing the
* decks for player 1 and player 2 respectivly.
*
* @par Compiling Instruction:
*       None
*
* @par Usage
* @verbatim
* thpe04.exe [input type] arg1 arg2
*
* Invalid command line arguments
* thpe04.exe [input type] arg1 arg2
*
* @endverbatim
*
*/  
#include "thpe04.h"

/**
 * @author Oliver Schwab
 * 
 * @par Description plays a game of war based on passed in parameters
 * 
 * @param[in] argc how many arguments
 * @param[in] argv the arguments
 * 
 * @return int if the run was a success
 * 
 * @par Example
 * @verbatim
 * 
 * thpe04.exe [option] arg1 arg2
 * 
 * @endverbatim
 */
int main(int argc, char** argv)
{
    std::queue<card> player1, player2;

    card tmpCard, a = card(10), b = card(11);

    a <= b;

    int roundsPlayed = 0, i, size;

    runTestCases();

    

    //check for command arguments
    if (argc != 4) {
        std::cout << "Invalid command line arguments" << std::endl;

        std::cout << "thpe04.exe [input type] arg1 arg2";

        exit(0);
    }
    //check if files are valid
    if (strcmp(argv[1], "-f") == 0)
    {
        if (!readInDeck(player1, argv[2]))
        {
            std::cout << "Unable to open file: " << argv[2];
            exit(0);
        }
        if (!readInDeck(player2, argv[3]))
        {
            std::cout << "Unable to open file: " << argv[3];
            exit(0); 
        }
    }
    //generate decks using integer command line arguments for each player
    else if (strcmp(argv[1], "-s") == 0)
    {
        generateDeck(player1, std::stoi(argv[2]));
        generateDeck(player2, std::stoi(argv[3]));
    }
    //if neither files locations or integers, output usage statement
    else
    {
        std::cout << "Invalid input type, please use either -f for"
            << "file input or -s for seed input";
        exit(0);
    }
    //while neither deck is empty play round
    while (!player1.empty() && !player2.empty())
    {
        playRound(player1, player2);
        roundsPlayed++;
    }

    if (player2.empty())    // if player 2 is empty, player 1 won
    {
        size = player1.size(); 
        // assign size to a variable so that it stays constant 
        // as you change the size of the stack

        std::cout << "Player 1 wins after " << roundsPlayed 
            << " rounds." << std::endl << "Player 1 hand: ";
        // output all the cards in the stack using
        for (i = 0; i < size; i++)
        {
            tmpCard = player1.front();

            std::cout << tmpCard.returnCard() << " ";

            player1.pop();

        }
        // player 2's hand is empty so no need to output and cards in their hand
        std::cout << std::endl << "Player 2 Hand: " << std::endl;
    }

    else
    { // repeat the same process but for when player 2 win
        size = player2.size();

        std::cout << "Player 2 wins after " << roundsPlayed
            << " rounds." << std::endl;

        std::cout << "Player 1 Hand: " << std::endl;
        
        std::cout << "Player 2 hand: ";

        for (i = 0; i < size; i++)
        {
            tmpCard = player2.front();

            std::cout << tmpCard.returnCard() << " ";

            player2.pop();

        }
    
    }
}

/**
 * @author Oliver Schwab
 * 
 * @par Description plays one round of the war card game
 * 
 * @param[in, out] player1 the deck of cards for player one
 * @param[in, out] player2 the deck of cards for player 2
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * queue<card> player1, player2;
 * 
 * generateDeck(player1, 10);
 * 
 * generateDeck(player2, 11);
 * 
 * playerRound(player1, player2);
 * 
 * @endverbatim
 */
void playRound(std::queue<card>& player1, std::queue<card>& player2)
{

    stack<card> p1Discard, p2Discard;
    card p1Card, p2Card; // the current card of players 1 and 2

    int i, min, p1Size, p2Size;

    if (player1.empty() || player2.empty()) 
        // if either are empty the game is iver
    {
        return;
    }

    // get top cards of each players deck and add them to the stack

    p1Card = player1.front();
    p2Card = player2.front();

    player1.pop();
    player2.pop();

    p1Discard.push(p1Card);
    p2Discard.push(p2Card);

    // while both players have cards and the cards
    // are equal keep adding cards to the stack in 
    // increments of 3 or whoever has the leaset amount of cards

    while (!player1.empty() && !player2.empty() && p1Card == p2Card)
    {
        min = std::min(player1.size(), player2.size());
        for (i = 0; i < ((min > 3) ? 3 : min); i++)
        {
            p1Card = player1.front();
            p2Card = player2.front();

            player1.pop();
            player2.pop();

            p1Discard.push(p1Card);
            p2Discard.push(p2Card);
        }
    }

    // make sure the card vars have the right card stored

    p1Discard.top(p1Card);
    p2Discard.top(p2Card);

    // assign sizes to vars so that 
    // they dont change as you change the size of the stacks

    p1Size = p1Discard.size();
    p2Size = p2Discard.size();

    //handle case where both cards are equal and they are both out of cards

    if ((player1.empty() || player2.empty()) && p1Card == p2Card)
    {

        //go through each player and add cards back to their hands
        for (i = 0; i < p1Size; i++)
        {
            p1Discard.pop(p1Card);

            player1.push(p1Card);
        }

        for (i = 0; i < p2Size; i++)
        {
            p2Discard.pop(p2Card);

            player2.push(p2Card);
        }

        return;
    }
    // if player 1 won then add all the cards to their hand
    if (p1Card > p2Card)
    {
        for (i = 0; i < p2Size; i++)
        {
            p2Discard.pop(p2Card);

            player1.push(p2Card);
        }

        for (i = 0; i < p1Size; i++)
        {

            p1Discard.pop(p1Card);

            player1.push(p1Card);
        }
    }
    // do the samd thing if player 2 won but add to p2's hand
    else
    {
        for (i = 0; i < p1Size; i++)
        {

            p1Discard.pop(p1Card);

            player2.push(p1Card);
        }

        for (i = 0; i < p2Size; i++)
        {

            p2Discard.pop(p2Card);

            player2.push(p2Card);
        }
    }

}


/**
 * @author Oliver Schwab
 * 
 * @par Description Generates 52 cards with a random generator based on
 * the given seed.
 * 
 * @param[in, out] player1 the deck to generate cards for
 * @param[in] seed the seed for the random generator
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * stack<card> player1;
 * 
 * generateDecks(player1, 10); // player one would now cointain 52 unique cards
 * 
 * @endverbatim
 */
void generateDeck(std::queue<card>& player1, int seed)
{

    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 51);

    card aCard;
    int cardValue, i, sum;

    int cardsCreated[52]; // lookup array to avoid duplicates

    bool full = false;

    for (i = 0; i < 52; i++)
    {
        cardsCreated[i] = 0; //intialize array
    }

    while (!full)
    {   // continually generate cards while checking 
        // for uniqueness and add the to the players hand
        cardValue = distribution(generator);

        if (cardsCreated[cardValue] != 0)
        {
            continue;
        }

        player1.push(card(cardValue));

        cardsCreated[cardValue] = 1;

        sum = 0;

        for (i = 0; i < 52; i++)
        {
            sum += cardsCreated[i];
        }

        full = (sum == 52);
    }
}


/**
 * @author Oliver Schwab
 * 
 * @par Description generates a deck for the passed in player via the given
 * file containing the cards to use for generation.
 * 
 * @param[in, out] player1 the playerdeck to populate with the cards 
 * contained in the file
 * @param[in] fileLocation the location of the file to read in
 * 
 * @return bool if the operation was a success.
 * 
 * @par Example
 * @verbatim
 * 
 * queue<card> player1;
 * 
 * readInDeck(player1, "deck1.cards"); 
 * // where deck1.cards contains 52 unique cards.
 * // player1 would now contain those 52 unique cards.
 * 
 * @endverbatim
 */
bool readInDeck(std::queue<card>& player1, std::string fileLocation)
{

    // iterate through the file and add each card within to the deck
    std::ifstream file;

    int tmpInt;

    file.open(fileLocation);

    if (!file.is_open())
    {
        std::cout << "Failed to open file: " << fileLocation << std::endl;
        return false;
    }

    while (player1.size() != 52 && file >> tmpInt)
    {
        player1.push(tmpInt);
    }

    return true;
}
/**
 * @author Oliver Schwab
 * 
 * @par Description plays out a game given two decks
 * 
 * @param[in] player1 the first players cards
 * @param[in] player2 the second player hand
 * @param[in] out where to output the results
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * generateDeck(p1, p2, cout); // where p1 and p2 are valid hands
 * 
 * @endverbatim
 */
void playGame(std::queue<card> &player1, std::queue<card> &player2, std::ostream& out)
{
    int roundsPlayed = 0, size, i;
    card tmpCard;

    while (!player1.empty() && !player2.empty())
    {
        playRound(player1, player2);
        roundsPlayed++;
    }

    if (player2.empty())    // if player 2 is empty, player 1 won
    {
        size = player1.size();
        // assign size to a variable so that it stays constant 
        // as you change the size of the stack

        out << "Player 1 wins after " << roundsPlayed
            << " rounds.\n" << "Player 1 hand: ";
        // output all the cards in the stack using

        std::queue<card> p1 = player1;
        for (i = 0; i < size; i++)
        {
            tmpCard = p1.front();

            out << tmpCard.returnCard() << " ";

            p1.pop();

        }
        // player 2's hand is empty so no need to output and cards in their hand
        out << "\n" << "Player 2 Hand: " << "\n";
    }

    else
    { // repeat the same process but for when player 2 win
        size = player2.size();

        out << "Player 2 wins after " << roundsPlayed
            << " rounds." << std::endl;

        out << "Player 1 Hand: " << std::endl;

        out << "Player 2 hand: ";

        std::queue<card> p2 = player2;

        for (i = 0; i < size; i++)
        {
            tmpCard = p2.front();

            out << tmpCard.returnCard() << " ";

            p2.pop();

        }

    }
}
