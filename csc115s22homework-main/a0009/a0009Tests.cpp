#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "a0009.h"

//write test cases here


TEST_CASE("swapStrings - intial test case with one character string")
{
    char s1[10] = "a";
    char s2[10] = "b";

    swapStrings(s1, s2);

    REQUIRE(strcmp(s1, "b") == 0);
    REQUIRE(strcmp(s2, "a") == 0);
}


TEST_CASE("swapStrings - oliver, sara")
{
    char s1[10] = "oliver";
    char s2[10] = "sara";

    swapStrings(s1, s2);

    REQUIRE(strcmp(s1, "sara") == 0);
    REQUIRE(strcmp(s2, "oliver") == 0);
}


TEST_CASE("swapStrings - testing spaces")
{
    char s1[15] = "hi im here";
    char s2[15] = "whats goin on";

    swapStrings(s1, s2);

    REQUIRE(strcmp(s1, "whats goin on") == 0);
    REQUIRE(strcmp(s2, "hi im here") == 0);
}


TEST_CASE("sortOrder - initial test case testing already sorted list")
{
    char array[2][21] = {"a", "b"};

    sortOrder(array, 2);

    REQUIRE(strcmp(array[0], "a") == 0);
    REQUIRE(strcmp(array[1], "b") == 0);
}


TEST_CASE("sortOrder - oliver, sara, matt, bea")
{
    char array[4][21] = {"oliver", "sara", "matt", "bea"};

    sortOrder(array, 4);

    REQUIRE(strcmp(array[0], "bea") == 0);
    REQUIRE(strcmp(array[1], "matt") == 0);
    REQUIRE(strcmp(array[3], "sara") == 0);
}


TEST_CASE("sortOrder - assorted capilization")
{
    char array[7][21] = {"Oliver", "sAra", "sara", "sarA", "Bea", "bEa", "Matt"};

    sortOrder(array, 7);

    REQUIRE(strcmp(array[0], "Bea") == 0);
    REQUIRE(strcmp(array[1], "Matt") == 0);
    REQUIRE(strcmp(array[3], "bEa") == 0);
    REQUIRE(strcmp(array[6], "sara") == 0);

}


TEST_CASE("sortLen - intial test with two items already sorted")
{
    char array[2][21] = {"a", "ab"};

    sortLen(array, 2);

    REQUIRE(strcmp(array[0], "a") == 0);
    REQUIRE(strcmp(array[1], "ab") == 0);
}


TEST_CASE("sortLen - testing 4 entrys in array all different length")
{
    char array[4][21] = {"a", "tre", "it", "lala"};

    sortLen(array, 4);

    REQUIRE(strcmp(array[0], "a") == 0);
    REQUIRE(strcmp(array[3], "lala") == 0);
    REQUIRE(strcmp(array[2], "tre") == 0);
}


TEST_CASE("sortLen - testing array with containing strings of same length")
{
    char array[5][21] = {"happy", "sad", "apple", "day", "milk"};

    sortLen(array, 5);

    REQUIRE(strcmp(array[0], "sad") == 0);
    REQUIRE(strcmp(array[4], "apple") == 0);
    REQUIRE(strcmp(array[2], "milk") == 0); 
}