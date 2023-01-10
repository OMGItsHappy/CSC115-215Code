#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "a0007.h"

//write test cases here

TEST_CASE("sortByID - intial test case {1,2,3,4}")
{
    int testValue[4] = {1,2,3,4};
    int length = 4;
    string testNames[4] = {"oliver", "sara", "bog", "asa"};
    sortByID(testNames, testValue, 4);
    int expected[4] = {1,2,3,4};

    for (int i = 0; i < length; i++)
    {
        REQUIRE(testValue[i] == expected[i]);
    }
}



TEST_CASE("sortByID - intial test case {4,3,2,1}")
{
    int testValue[4] = {4,3,2,1};
    int length = 4;
    string testNames[4] = {"oliver", "sara", "bog", "asa"};
    string expectedNames[4] = {"asa", "bog", "sara", "oliver"};
    sortByID(testNames, testValue, 4);
    int expected[4] = {1,2,3,4};

    for (int i = 0; i < length; i++)
    {
        REQUIRE(testValue[i] == expected[i]);
        REQUIRE(testNames[i] == expectedNames[i]);
    }
}


TEST_CASE("sortByID - test case {1,3,45,25,32,2}")
{
    int length = 6;
    int testValue[6] = {1,3,45,25,32,2};

    string testNames[6] = {"1", "2", "3", "4", "5", "6"};
    string expectedNames[6] = {"1", "6", "2", "4", "5", "3"};
    sortByID(testNames, testValue, length);
    int expected[6] = {1,2,3,25,32,45};

    for (int i = 0; i < length; i++)
    {
        REQUIRE(testValue[i] == expected[i]);
        REQUIRE(testNames[i] == expectedNames[i]);
    }
}

/*
TEST_CASE("sortByName - test case ")
{
    int length = ;
    int testValue[] = {};

    string testNames[] = {};
    string expectedNames[] = {};
    sortByName(testNames, testValue, length);
    int expected[] = {};

    for (int i = 0; i < length; i++)
    {
        REQUIRE(testValue[i] == expected[i]);
        REQUIRE(testNames[i] == expectedNames[i]);
    }
}
*/


TEST_CASE("sortByName - test case {a,b,c}")
{
    int length = 3;
    int testValue[3] = {1,2,3};

    string testNames[3] = {"a", "b", "c"};
    string expectedNames[3] = {"a","b", "c"};
    sortByName(testNames, testValue, length);
    int expected[3] = {1,2,3};

    for (int i = 0; i < length; i++)
    {
        REQUIRE(testValue[i] == expected[i]);
        REQUIRE(testNames[i] == expectedNames[i]);
    }
}


TEST_CASE("sortByName - test case {c,b,a")
{
    int length = 3;
    int testValue[3] = {1,2,3};

    string testNames[3] = {"c","b","a"};
    string expectedNames[3] = {"a", "b", "c"};
    sortByName(testNames, testValue, length);
    int expected[3] = {3,2,1};

    for (int i = 0; i < length; i++)
    {
        REQUIRE(testValue[i] == expected[i]);
        REQUIRE(testNames[i] == expectedNames[i]);
    }
}


TEST_CASE("sortByName - test case {dog, anteater, pull, cat}")
{
    int length = 4;
    int testValue[4] = {1,2,3,4};

    string testNames[4] = {"dog", "anteater", "pull", "cat"};
    string expectedNames[4] = {"anteater", "cat", "dog", "pull"};
    sortByName(testNames, testValue, length);
    int expected[4] = {2,4,1,3};

    for (int i = 0; i < length; i++)
    {
        REQUIRE(testValue[i] == expected[i]);
        REQUIRE(testNames[i] == expectedNames[i]);
    }
} 


TEST_CASE("sortByName - test case {dog, anteater, Anteater, cat} testing uppercase")
{
    int length = 4;
    int testValue[4] = {1,2,3,4};

    string testNames[4] = {"dog", "anteater", "Anteater", "cat"};
    string expectedNames[4] = {"Anteater", "anteater", "cat", "dog"};
    sortByName(testNames, testValue, length);
    int expected[4] = {3,2,4,1};

    for (int i = 0; i < length; i++)
    {
        REQUIRE(testValue[i] == expected[i]);
        REQUIRE(testNames[i] == expectedNames[i]);
    }
} 


TEST_CASE("getID - intial test case ")
{
    int length = 4;
    int testIDs[4] = {1,2,3,4};

    string testNames[4] = {"dog", "anteater", "Anteater", "cat"};
    sortByName(testNames, testIDs, length);

    int result = getID(testNames, testIDs, length, "dog");

    REQUIRE(result == 1);

}


TEST_CASE("getID - testing {to, hi, pog, home, song, here, walk}")
{
    int length = 7;
    string testNames[7] = {"to", "hi", "pog", "home", "song", "here", "walk"};
    int testIDs[7] = {1,2,3,4,5,6,7};

    sortByName(testNames, testIDs, length);

    int result = getID(testNames, testIDs, length, "song");

    REQUIRE(result == 5);

    SECTION("Testing out of bounds")
    {
        result = getID(testNames, testIDs, length, "oliver");
        
        REQUIRE(result == -1);
    }
}


TEST_CASE("getName - intial test case ")
{
    int length = 4;
    int testIDs[4] = {1,2,3,4};

    string testNames[4] = {"dog", "anteater", "Anteater", "cat"};
    sortByID(testNames, testIDs, length);

    string result = getName(testNames, testIDs, length, 1);

    REQUIRE(result == "dog");

}


TEST_CASE("getName - testing to, hi, pog, home, song, here, walk} ")
{
    int length = 7;
    string testNames[7] = {"to", "hi", "pog", "home", "song", "here", "walk"};
    int testIDs[7] = {1,2,3,4,5,6,7};

    sortByID(testNames, testIDs, length);

    string result = getName(testNames, testIDs, length, 4);

    REQUIRE(result == "home");

    SECTION("Testing out of bounds")
    {
        result = getName(testNames, testIDs, length, 11);
        
        REQUIRE(result == "");
    }

}