#define CATCH_CONFIG_MAIN
#include "..\catch.hpp"
#include "a0005.h"

TEST_CASE("passwordCalc - testing password Hello")
{
    int entropy;
    string strength;
    string pw = "Hello";

    passwordCalc(pw, entropy, strength);

    REQUIRE(entropy == 29);
    REQUIRE(strength == "Weak");
}


TEST_CASE("passwordCalc - testing password hi")
{
    int entropy;
    string strength;
    string pw = "hi";

    passwordCalc(pw, entropy, strength);

    REQUIRE(entropy == 9);
    REQUIRE(strength == "Very Weak");
}


TEST_CASE("passwordCalc - testing password Poggers10")
{
    int entropy;
    string strength;
    string pw = "Poggers10";

    passwordCalc(pw, entropy, strength);

    REQUIRE(entropy == 54);
    REQUIRE(strength == "Reasonable");
}


TEST_CASE("passwordCalc - testing password Poggers10 ")
{
    int entropy;
    string strength;
    string pw = "Poggers10 ";

    passwordCalc(pw, entropy, strength);

    REQUIRE(entropy == 60);
    REQUIRE(strength == "Strong");
}


TEST_CASE("passwordCalc - testing password Poggers12345678901. ")
{
    int entropy;
    string strength;
    string pw = "Poggers12345678901. ";

    passwordCalc(pw, entropy, strength);

    REQUIRE(entropy == 132);
    REQUIRE(strength == "Very Strong");
}


TEST_CASE("passwordCalc - testing password Po")
{
    int entropy;
    string strength;
    string pw = "Po";

    passwordCalc(pw, entropy, strength);

    REQUIRE(entropy == 11);
    REQUIRE(strength == "Very Weak");
}