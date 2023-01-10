#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include <cmath>

using namespace std;

//testing the functions pow and log10
//will be evaluating answers using approx

TEST_CASE("pow - testing 2 to the 0 power")
{
    double base = 2;
    double expo = 0;
    double answer = pow(base, expo);
    REQUIRE(answer == Approx(1));
}


TEST_CASE("pow - testing 2 to the 1 power")
{
    double base = 2;
    double expo = 1;
    double answer = pow(base, expo);
    REQUIRE(answer == Approx(2));
}


TEST_CASE("pow - testing 5.4 to the 4.8 power")
{
    double base = 5.4;
    double expo = 4.8;
    double answer = pow(base, expo);
    REQUIRE(answer == Approx(3277.1026649004110239699052256613));
}


TEST_CASE("pow - testing 3.8 to the 0.7 power")
{
    double base = 3.8;
    double expo = 0.7;
    double answer = pow(base, expo);
    REQUIRE(answer == Approx(2.5459420704451699974944460934679));
}


//moving on to log10 

TEST_CASE("log10 - testing log10 of 1")
{
    double base = 1;
    double answer = log10(base);
    REQUIRE(answer == Approx(0));
}


TEST_CASE("log10 - testing base .076")
{
    double base = 0.076;
    double answer = log10(base);
    REQUIRE(answer == Approx(-1.1191864077192086480361887347941));
}


TEST_CASE("log10 - testing base 10")
{
    double base = 10;
    double answer = log10(base);
    REQUIRE(answer == Approx(1));
}


TEST_CASE("log10 - testing base 12.87")
{
    double base = 12.87;
    double answer = log10(base);
    REQUIRE(answer == Approx(1.1095785469043866845467609356956));
}

