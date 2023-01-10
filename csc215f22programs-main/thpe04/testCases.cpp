#include "thpe04.h"
#define CATCH_CONFIG_RUNNER 
#include "..\\catch.hpp"


const bool RUNCATCH = false;

/** **************************************************************************
 * @author Oliver Schwab
 *
 * @par Description:
 * Runs the test cases when RUNCATCH is true
 *
 * @return always 0
 *
 *
 * @par Example:
@verbatim
runTestCases();
@endverbatim
*****************************************************************************/
int runTestCases()
{
    Catch::Session session;
    int result;

    if (RUNCATCH)
    {
        result = session.run();
        if (result != 0)
        {
            std::cout << "Test cases didn't pass." << std::endl;
            return result;
        }
    }
    return 0;
}


/*****************************************************************************
 * TEST CASES
 ****************************************************************************/


TEST_CASE("")
{
    stack<card> a;
}

 /*****************************************************************************
  * stack class
  ****************************************************************************/
TEST_CASE("constructor")
{
    stack<int> stack1;
    CHECK(stack1.empty());
    CHECK(stack1.size() == 0);

    stack<card> stack2;
    CHECK(stack2.empty());
    CHECK(stack2.size() == 0);
}


TEST_CASE("push")
{
    stack<int> numStack;
    stack<card> stack1;

    card newCard;
    newCard.faceValue = 3;
    newCard.suit = 2;

    SECTION("one item")
    {
        // ints
        CHECK(numStack.size() == 0);
        CHECK(numStack.push(1));
        CHECK(numStack.size() == 1);

        // cards
        CHECK(stack1.size() == 0);
        stack1.push(newCard);
        CHECK(stack1.size() == 1);
    }

    SECTION("two items")
    {
        // ints
        CHECK(numStack.size() == 0);
        CHECK(numStack.push(1));
        CHECK(numStack.size() == 1);
        CHECK(numStack.push(3));
        CHECK(numStack.size() == 2);

        // cards
        CHECK(stack1.size() == 0);
        CHECK(stack1.push(newCard));
        CHECK(stack1.size() == 1);
        CHECK(stack1.push(newCard));
        CHECK(stack1.size() == 2);
    }

    SECTION("multiple items")
    {
        // ints
        CHECK(numStack.size() == 0);
        CHECK(numStack.push(1));
        CHECK(numStack.size() == 1);
        CHECK(numStack.push(3));
        CHECK(numStack.size() == 2);
        CHECK(numStack.push(5));
        CHECK(numStack.size() == 3);
        CHECK(numStack.push(7));
        CHECK(numStack.size() == 4);

        // cards
        CHECK(stack1.size() == 0);
        CHECK(stack1.push(newCard));
        CHECK(stack1.size() == 1);
        CHECK(stack1.push(newCard));
        CHECK(stack1.size() == 2);
        CHECK(stack1.push(newCard));
        CHECK(stack1.size() == 3);
        CHECK(stack1.push(newCard));
        CHECK(stack1.size() == 4);
        CHECK(stack1.push(newCard));
        CHECK(stack1.size() == 5);
        }
}


TEST_CASE("pop")
{
    stack<int> numStack;
    stack<card> stack1;

    int item = 0;
    card newCard, popCard;
    newCard.faceValue = 3;
    newCard.suit = 2;
    popCard.faceValue = 0;
    popCard.suit = 0;

    SECTION("pop from empty stack")
    {
        CHECK(!numStack.pop(item));
        CHECK(!stack1.pop(popCard));
    }

    SECTION("remove last item in stack")
    {
        // ints
        CHECK(numStack.push(1));
        CHECK(!numStack.empty());
        CHECK(numStack.size() == 1);
        CHECK(numStack.pop(item));
        CHECK(numStack.empty());
        CHECK(numStack.size() == 0);
        CHECK(item == 1);

        // cards
        CHECK(stack1.push(newCard));
        CHECK(!stack1.empty());
        CHECK(stack1.size() == 1);
        CHECK(stack1.pop(popCard));
        CHECK(stack1.empty());
        CHECK(stack1.size() == 0);
        CHECK(popCard.faceValue == 3);
        CHECK(popCard.suit == 2);
    }

    SECTION("remove from a populated stack")
    {
        // ints
        CHECK(numStack.push(1));
        CHECK(numStack.push(13));
        CHECK(numStack.push(78));
        CHECK(!numStack.empty());
        CHECK(numStack.size() == 3);
        CHECK(numStack.pop(item));
        CHECK(numStack.size() == 2);

        // cards
        CHECK(stack1.push(newCard));
        CHECK(stack1.push(newCard));
        CHECK(stack1.push(newCard));
        CHECK(stack1.push(newCard));
        CHECK(!stack1.empty());
        CHECK(stack1.size() == 4);
        CHECK(stack1.pop(popCard));
        CHECK(stack1.size() == 3);
        CHECK(stack1.pop(popCard));
        CHECK(stack1.size() == 2);
    }
}


TEST_CASE("top")
{
    stack<int> numStack;
    stack<card> stack;

    int item = 0;
    card newCard, popCard;
    newCard.faceValue = 3;
    newCard.suit = 2;
    popCard.faceValue = 0;
    popCard.suit = 0;

    SECTION("top from empty set")
    {
        CHECK(!numStack.top(item));
        CHECK(!stack.top(popCard));
    }

    SECTION("top from filled set")
    {
        // ints
        CHECK(numStack.push(1));
        CHECK(!numStack.empty());
        CHECK(numStack.size() == 1);
        CHECK(numStack.top(item));
        CHECK(!numStack.empty());
        CHECK(numStack.size() == 1);
        CHECK(item == 1);

        // cards
        CHECK(stack.push(newCard));
        CHECK(!stack.empty());
        CHECK(stack.size() == 1);
        CHECK(stack.top(popCard));
        CHECK(!stack.empty());
        CHECK(stack.size() == 1);
        CHECK(popCard.faceValue == 3);
        CHECK(popCard.suit == 2);
    }

    SECTION("top & pop")
    {
        // ints
        CHECK(numStack.push(1));
        CHECK(numStack.push(13));
        CHECK(numStack.push(78));
        CHECK(!numStack.empty());
        CHECK(numStack.size() == 3);
        CHECK(numStack.top(item));
        CHECK(!numStack.empty());
        CHECK(numStack.size() == 3);
        CHECK(item == 78);
        numStack.pop(item);
        CHECK(numStack.top(item));
        CHECK(item == 13);

        // cards
        CHECK(stack.push(newCard));
        CHECK(!stack.empty());
        CHECK(stack.size() == 1);
        CHECK(stack.top(popCard));
        CHECK(!stack.empty());
        CHECK(stack.size() == 1);
        CHECK(popCard.faceValue == 3);
        CHECK(popCard.suit == 2);
    }
}


TEST_CASE("size")
{
    stack<int> numStack;
    stack<card> stack;

    card newCard;
    newCard.faceValue = 3;
    newCard.suit = 2;

    SECTION("one item")
    {
        // ints
        CHECK(numStack.size() == 0);
        CHECK(numStack.push(1));
        CHECK(numStack.size() == 1);

        // cards
        CHECK(stack.size() == 0);
        CHECK(stack.push(newCard));
        CHECK(stack.size() == 1);
    }

    SECTION("two items")
    {
        // ints
        CHECK(numStack.size() == 0);
        CHECK(numStack.push(1));
        CHECK(numStack.size() == 1);
        CHECK(numStack.push(3));
        CHECK(numStack.size() == 2);

        // cards
        CHECK(stack.size() == 0);
        CHECK(stack.push(newCard));
        CHECK(stack.size() == 1);
        CHECK(stack.push(newCard));
        CHECK(stack.size() == 2);
    }

    SECTION("multiple items")
    {
        // ints
        CHECK(numStack.size() == 0);
        CHECK(numStack.push(1));
        CHECK(numStack.size() == 1);
        CHECK(numStack.push(3));
        CHECK(numStack.size() == 2);
        CHECK(numStack.push(5));
        CHECK(numStack.size() == 3);
        CHECK(numStack.push(7));
        CHECK(numStack.size() == 4);

        // cards
        CHECK(stack.size() == 0);
        CHECK(stack.push(newCard));
        CHECK(stack.size() == 1);
        CHECK(stack.push(newCard));
        CHECK(stack.size() == 2);
        CHECK(stack.push(newCard));
        CHECK(stack.size() == 3);
        CHECK(stack.push(newCard));
        CHECK(stack.size() == 4);
        CHECK(stack.push(newCard));
        CHECK(stack.size() == 5);
    }
}


TEST_CASE("empty")
{
    stack<int> numStack;
    stack<card> stack1;
    card newCard = card(29);
    int item = 0;

    CHECK(numStack.empty());
    CHECK(stack1.empty());

    numStack.push(20);
    CHECK(!(numStack.empty()));
    numStack.pop(item);
    CHECK(numStack.empty());

    stack1.push(newCard);
    CHECK(!stack1.empty());
    stack1.pop(newCard);
    CHECK(stack1.empty());
}


TEST_CASE("clear")
{
    stack<int> numStack;
    stack<card> stack1;
    card newCard = card(29);

    CHECK(numStack.empty());
    CHECK(stack1.empty());

    numStack.push(20);
    numStack.push(20);
    numStack.push(20);

    stack1.push(newCard);
    stack1.push(newCard);
    stack1.push(newCard);
    stack1.push(newCard);

    CHECK(numStack.size() == 3);
    CHECK(stack1.size() == 4);

    numStack.clear();
    stack1.clear();

    CHECK(numStack.empty());
    CHECK(stack1.empty());
}


/*****************************************************************************
 * outside of class
 ****************************************************************************/
TEST_CASE("playRound")
{
    std::queue<card> p1;
    std::queue<card> p2;
    card c1 = card(1), c2 = card(39), c3 = card(2), c4 = card(20), c5 = card(30), c6 = card(8),
        c7 = card(43), c8 = card(12), c9 = card(25), c10 = card(0);
    // c1 = 2, c2 = A, c3 = 3, c4 = 8, c5 = 5, c6 = 9, c7 = 5, c8 = K, c9 = K, c10 = J

    SECTION("p1 wins")
    {
        p1.push(c1);
        p2.push(c2);
        p1.push(c3);
        p2.push(c4);
        p1.push(c5);
        p2.push(c6);

        playRound(p1, p2);

    }

    SECTION("p2 wins")
    {
        p1.push(c2);
        p2.push(c5);

        playRound(p1, p2);
        std::cout << std::endl << std::endl;
    }

    SECTION("war - just need to draw the additional 3 tho")
    {
        // same first card
        p1.push(c1);
        p2.push(c1);

        // will just draw an additional two, then compare the third
        p1.push(c2);
        p2.push(c3);
        p1.push(c4);
        p2.push(c5);

        p1.push(c6);
        p2.push(c7);

        playRound(p1, p2);
        std::cout << std::endl << std::endl;
    }

    SECTION("war, draw three then an additional 3")
    {
        // fisrt compare --> war
        p1.push(c1);
        p2.push(c1);

        p1.push(c1);
        p2.push(c1);
        p1.push(c1);
        p2.push(c1);
        p1.push(c1);
        p2.push(c1); // war again!

        p1.push(c1);
        p2.push(c1);
        p1.push(c1);
        p2.push(c1);

        p1.push(c2);
        p2.push(c3); // p2 wins

        playRound(p1, p2);
        std::cout << std::endl << std::endl;
    }

    SECTION("war, not enough for three more, draw two more")
    {
        // fisrt compare --> war
        p1.push(c1);
        p2.push(c1);

        p1.push(c1);
        p2.push(c1);
        p1.push(c4);
        p2.push(c5); // p1 wins

        playRound(p1, p2);
        std::cout << std::endl << std::endl;

    }

    SECTION("war, not enough for three more, draw one more")
    {
        // fisrt compare --> war
        p1.push(c1);
        p2.push(c1);

        p1.push(c4);
        p2.push(c5); // p1 wins

        playRound(p1, p2);
        std::cout << std::endl << std::endl;

    }

    SECTION("war, one player out of cards, each get their own discard piles back")
    {
        // fisrt compare --> war
        p1.push(c1);
        p2.push(c1);

        p1.push(c4);

        playRound(p1, p2);
        std::cout << std::endl << std::endl;

    }
}


TEST_CASE("populateHand - seed")
{
    std::queue<card> player1, player2;
    int seed1 = 132, seed2 = 29;

    generateDeck(player1, seed1);
    generateDeck(player2, seed2);

    std::cout << std::endl << std::endl << "populate hand - seed" << std::endl;
    std::cout << "p1: " << player1 << std::endl;
    std::cout << "p2: " << player2 << std::endl;
}


TEST_CASE("populateHand - file")
{
    std::queue<card> player1, player2;

    SECTION("test1")
    {
        readInDeck(player1, "deck1.cards");
        readInDeck(player2, "deck2.cards");

        std::cout << std::endl << std::endl << "populate hand - files" << std::endl;
        std::cout << "p1: " << player1 << std::endl;
        std::cout << "p2: " << player2 << std::endl;
    }
}






