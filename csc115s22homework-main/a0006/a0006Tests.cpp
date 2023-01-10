#define CATCH_CONFIG_MAIN
#include "..\catch.hpp"
#include "a0006.h"

TEST_CASE("createLookup - intial test case, dice rolls of []")
{
    int lookUp[7] = {};
    int diceRolls[1] = {};
    int rolls = 1;
    int i;
    int emptyArray [7] = {};
    createLookup(lookUp, diceRolls, rolls);

    for (i = 0; i < 7; i++) {
        REQUIRE(lookUp[i] == emptyArray[i]);
    }
    
}


TEST_CASE("createLookup - intial test case, dice rolls of [1, 1, 1, 5, 5, 6, 3, 3]")
{
    int lookUp[7] = {};
    int diceRolls [8] = {1, 1, 1, 5, 5, 6, 3, 3};
    int rolls = 8;
    int i;
    int resultArray [7] = {0, 3, 0, 2, 0, 2, 1};

    createLookup(lookUp, diceRolls, rolls);

    for (i = 0; i < 7; i++) {
        REQUIRE(lookUp[i] == resultArray[i]);
    }
    
}


TEST_CASE("createLookup - dice rolls of [1,5,5,5,5,5,6,6,6,6,6,6,3,3,3,4,4,4,4,2,2]")
{
    int lookUp[7] = {0,0,0,0,0,0,0};
    int diceRolls [21] = {1,5,5,5,5,5,6,6,6,6,6,6,3,3,3,4,4,4,4,2,2};
    int rolls = 21;
    int i;
    int resultArray [7] = {0, 1, 2, 3, 4, 5, 6};

    createLookup(lookUp, diceRolls, rolls);

    for (i = 0; i < 7; i++) {
        REQUIRE(lookUp[i] == resultArray[i]);
    }
    
}


TEST_CASE("createLookup - dice rolls of [1,3,6,3,5,4,2,3,2,6,1,1,2,4]")
{
    
    int lookUp[7] = {0,0,0,0,0,0,0};
    int diceRolls [14] = {1,3,6,3,5,4,2,3,2,6,1,1,2,4};
    int rolls = 14;
    int i;
    int resultArray [7] = {0, 3, 3, 3, 2, 1, 2};

    createLookup(lookUp, diceRolls, rolls);

    for (i = 0; i < 7; i++) {
        REQUIRE(lookUp[i] == resultArray[i]);
    }
    
}


TEST_CASE("fewestRolled - intial test case with nothing rolled, should return 1")
{

    int lookUp[7] = {};
    int diceRolls[1] = {};
    int rolls = 1;
    int lowestRolled;
    createLookup(lookUp, diceRolls, rolls);
    lowestRolled = fewestRolled(lookUp, 7);

    REQUIRE(lowestRolled == 1);

}


TEST_CASE("fewestRolled - testing when two values have been rolled the same number of times. lowest one(2) should be selected")
{
    int lookUp[7] = {};
    int diceRolls [8] = {1, 1, 1, 5, 5, 6, 3, 3};
    int rolls = 8;
    int resultArray [7] = {0, 3, 0, 2, 0, 2, 1};
    int lowestRolled;

    createLookup(lookUp, diceRolls, rolls);

    lowestRolled = fewestRolled(lookUp, 7);

    REQUIRE(lowestRolled == 2);
}


TEST_CASE("fewestRolled - testing values {1,5,5,5,5,5,6,6,6,6,6,6,3,3,3,4,4,4,4,2,2}")
{
    int lookUp[7] = {0,0,0,0,0,0,0};
    int diceRolls [21] = {1,5,5,5,5,5,6,6,6,6,6,6,3,3,3,4,4,4,4,2,2};
    int rolls = 21;
    int resultArray [7] = {0, 1, 2, 3, 4, 5, 6};
    int lowestRolled;

    createLookup(lookUp, diceRolls, rolls);

    lowestRolled = fewestRolled(lookUp, 7);

    REQUIRE(lowestRolled == 1);
}


TEST_CASE("fewestRolled - a number of values randomly placed {1,3,6,3,5,4,2,3,2,6,1,1,2,4}")
{
    int lookUp[7] = {0,0,0,0,0,0,0};
    int diceRolls [14] = {1,3,6,3,5,4,2,3,2,6,1,1,2,4};
    int rolls = 14;
    int lowestRolled;
    int resultArray [7] = {0, 3, 3, 3, 2, 1, 2};

    createLookup(lookUp, diceRolls, rolls);

    lowestRolled = fewestRolled(lookUp, 7);

    REQUIRE(lowestRolled == 5);
}


TEST_CASE("mostRolled - testing when all values are zero, should return 1 as thats the lowest order digit")
{
    int lookUp[7] = {};
    int diceRolls[1] = {};
    int rolls = 1;
    int mRolled;
    createLookup(lookUp, diceRolls, rolls);

    mRolled = mostRolled(lookUp, 7);

    REQUIRE(mRolled == 1);
}


TEST_CASE("mostRolled - testing when two values have been rolled the same number of times. lhighest one(1) should be selected")
{
    int lookUp[7] = {};
    int diceRolls [9] = {1, 1, 1, 5, 5, 6, 3, 3, 3};
    int rolls = 9;
    int resultArray [7] = {0, 3, 0, 3, 0, 2, 1};
    int mRolled;

    createLookup(lookUp, diceRolls, rolls);

    mRolled = mostRolled(lookUp, 7);

    REQUIRE(mRolled == 1);
}


TEST_CASE("mostRolled - testing values {1,5,5,5,5,5,6,6,6,6,6,6,3,3,3,4,4,4,4,2,2}")
{
    int lookUp[7] = {0,0,0,0,0,0,0};
    int diceRolls [21] = {1,5,5,5,5,5,6,6,6,6,6,6,3,3,3,4,4,4,4,2,2};
    int rolls = 21;
    int resultArray [7] = {0, 1, 2, 3, 4, 5, 6};
    int mRolled;

    createLookup(lookUp, diceRolls, rolls);

    mRolled = mostRolled(lookUp, 7);

    REQUIRE(mRolled == 6);
}


TEST_CASE("mostRolled - a number of values randomly placed {1,3,6,3,5,4,2,3,2,6,1,1,2,4}")
{
    int lookUp[7];
    int diceRolls [14] = {1,3,6,3,5,4,2,3,2,6,1,1,2,4};
    int rolls = 14;
    int mRolled;
    int resultArray [7] = {0, 3, 3, 3, 2, 1, 2};

    createLookup(lookUp, diceRolls, rolls);

    mRolled = mostRolled(lookUp, 7);

    REQUIRE(mRolled == 1);
}


TEST_CASE("sumRolls - testing when nothing has been rolled, all zeros")
{
    int lookUp[7] = {};
    int diceRolls[1] = {};
    int rolls = 1;
    int total;
    createLookup(lookUp, diceRolls, rolls);

    total = sumRolls(lookUp, 7);

    REQUIRE(total == 0);
}


TEST_CASE("sumRolls - testing a number of random values")
{
    int lookUp[7] = {};
    int diceRolls [9] = {1, 1, 1, 5, 5, 6, 3, 3, 3};
    int rolls = 9;
    int resultArray [7] = {0, 3, 0, 3, 0, 2, 1};
    int total;

    createLookup(lookUp, diceRolls, rolls);

    total = sumRolls(lookUp, 7);

    REQUIRE(total == 28);
}


TEST_CASE("sumRolls - incremental values {1,5,5,5,5,5,6,6,6,6,6,6,3,3,3,4,4,4,4,2,2}")
{
    int lookUp[7] = {0,0,0,0,0,0,0};
    int diceRolls [21] = {1,5,5,5,5,5,6,6,6,6,6,6,3,3,3,4,4,4,4,2,2};
    int rolls = 21;
    int resultArray [7] = {0, 1, 2, 3, 4, 5, 6};
    int total;

    createLookup(lookUp, diceRolls, rolls);

    total = sumRolls(lookUp, 7);

    REQUIRE(total == 91);
}


TEST_CASE("sumRolls - a number of values randomly placed {1,3,6,3,5,4,2,3,2,6,1,1,2,4}")
{
    int lookUp[7] = {0,0,0,0,0,0,0};
    int diceRolls [14] = {1,3,6,3,5,4,2,3,2,6,1,1,2,4};
    int rolls = 14;
    int total;
    int resultArray [7] = {0, 3, 3, 3, 2, 1, 2};

    createLookup(lookUp, diceRolls, rolls);

    total = sumRolls(lookUp, 7);

    REQUIRE(total == 43);
}
//