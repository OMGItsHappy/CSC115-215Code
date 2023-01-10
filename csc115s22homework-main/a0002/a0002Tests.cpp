#define CATCH_CONFIG_MAIN
#include "..\catch.hpp"
#include "a0002.h"

using namespace std;

TEST_CASE("windChill - testing the min value of the windchill function is correct")
{
    int windSpeed = 4;
    int temp = 50;
    
    int result = windChill(temp, windSpeed);
    REQUIRE(result == 49);
}

TEST_CASE("windChill - testing a midrange value with the windchill function")
{
    int windSpeed = 10;
    int temp = 25;
    
    int result = windChill(temp, windSpeed);
    REQUIRE(result == 15);
}

TEST_CASE("windChill - testing an extreme value windSpeed = 50 temp = -20")
{
    int windSpeed = 50;
    int temp = -20;
    
    int result = windChill(temp, windSpeed);
    REQUIRE(result  == -59);
}

TEST_CASE("windChill - testing a even more extreme value windSpeed = 100 temp = -50")
{
    int windSpeed = 100;
    int temp = -50;
    
    int result = windChill(temp, windSpeed);
    REQUIRE(result == -114);
}

TEST_CASE("windChill - testing another midrange value windspeed = 20 temp = 30")
{
    int windSpeed = 20;
    int temp = 30;
    
    int result = windChill(temp, windSpeed);
    REQUIRE(result == 18);
}

TEST_CASE("windChillWarning - intial test case should be none temp = 38, v = 5")
{
    int windSpeed = 5;
    int temp = 38;
    
    string result = windChillWarning(temp, windSpeed);
    REQUIRE(result == "None");
}

TEST_CASE("windChillWarning - testing for midrange minimal, temp = 20, v = 6")
{
    int windSpeed = 6;
    int temp = 20;
    string result = windChillWarning(temp, windSpeed);
    REQUIRE(result == "Minimal");
}

TEST_CASE("windChillWarning - tesing upper edge case for minimal, temp = 35, v = 5")
{
    int windSpeed = 5;
    int temp = 35;
    REQUIRE(windChill(temp, windSpeed) == 31); // assert its an edge case
    string result = windChillWarning(temp, windSpeed);
    REQUIRE(result == "Minimal");
}

TEST_CASE("windChillWarning - tesing lower edge case of minimal, temp = 9, v = 5")
{
    int windSpeed = 5;
    int temp = 9;
    REQUIRE(windChill(temp, windSpeed) == 0); // assert its an edge case
    string result = windChillWarning(temp, windSpeed);
    REQUIRE(result == "Minimal");
}

TEST_CASE("windChillWarning - tesing upper edge case for Caution, temp = 8, v = 5")
{
    int windSpeed = 5;
    int temp = 8;
    REQUIRE(windChill(temp, windSpeed) == -1); // assert edge case
    string result = windChillWarning(temp, windSpeed);
    REQUIRE(result == "Caution");
}

TEST_CASE("windChillWarning - testing lower edge case for Caution, temp = -8, v = 5")
{
    int windSpeed = 5;
    int temp = -8;
    REQUIRE(windChill(temp, windSpeed) == -20); // assert edge case
    string result = windChillWarning(temp, windSpeed);
    REQUIRE(result == "Caution");
}

TEST_CASE("windChillWarning - tesing upper edge case for intermediate, temp = -9, v = 5")
{
    int windSpeed = 5;
    int temp = -9;
    REQUIRE(windChill(temp, windSpeed) == -21);
    string result = windChillWarning(temp, windSpeed);
    REQUIRE(result == "Intermediate");
}

TEST_CASE("windChillWarning testing lower edge case for intermediate, temp = -25, v = 5")
{
    int windSpeed = 5;
    int temp = -25;
    REQUIRE(windChill(temp, windSpeed) == -40);
    string result = windChillWarning(temp, windSpeed);
    REQUIRE(result == "Intermediate");
}

TEST_CASE("windChillWarning testing upper edge case for extreme, temp = -26, v = 5")
{
    int windSpeed =5;
    int temp = -26;
    REQUIRE(windChill(temp, windSpeed) == -41);
    string result = windChillWarning(temp, windSpeed);
    REQUIRE(result == "Extreme");
}

TEST_CASE("windChillWarning - tesing middleground for extreme, temp = -40, v = 30")
{
    int windSpeed = 30;
    int temp = -40;
    string result = windChillWarning(temp, windSpeed);
    REQUIRE(result == "Extreme");
}