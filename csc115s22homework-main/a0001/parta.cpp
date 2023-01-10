#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include <cctype> 

using namespace std;

TEST_CASE("toupper - testing lower boundary of an a") 
{
    char achar = 'a';
    char result;
    
    result = char(toupper(achar));
    REQUIRE(result == 'A');
}


TEST_CASE("toupper - testing lower boundary of z")
{
    char achar = 'z';
    char result;
    
    result = char(toupper(achar));
    REQUIRE(result == 'Z');
}


TEST_CASE("toupper - testing middle char value")
{
    char achar = 'f';
    char result;
    
    result = char(toupper(achar));
    REQUIRE(result == 'F');
}


TEST_CASE("toupper - testing a char that should not be affected")
{
    char achar = 'A';
    char result;
    
    result = char(toupper(achar));
    REQUIRE(result == 'A');
}


TEST_CASE("toupper - testing a non aphabetic character")
{
    char achar = '4';
    char result;
    
    result = char(toupper(achar));
    REQUIRE(result == char('4'));
}

//Next function - islower

TEST_CASE("islower - testing a lower bound a")
{
    char achar = 'a';
    bool result = islower(achar);
    REQUIRE(result == true);
}


TEST_CASE("islower - testing a upper bound z")
{
    char achar = 'z';
    bool result = islower(achar);
    REQUIRE(result == true);
}


TEST_CASE("islower - testin a uppercase lowerbound A")
{
    char achar = 'A';
    bool result = islower(achar);
    REQUIRE(result == false);
}


TEST_CASE("islower - Testing a uppercase upperbound Z")
{
    char achar = 'Z';
    bool result = islower(achar);
    REQUIRE(result == false);
}

TEST_CASE("islower - tesing middle lower case value")
{
    char achar = 'g';
    bool result = islower(achar);
    REQUIRE(result == true);
}


TEST_CASE("islower - testing middle uppercase value")
{
    char achar = 'G';
    bool result = islower(achar);
    REQUIRE(result == false);
}


TEST_CASE("islower - testing a non char value")
{
    char achar = '4';
    bool result = islower(achar);
    REQUIRE(result == false);
}

//Next function - isdigit


TEST_CASE("isdigit - testing lower bound 0")
{
    char achar = '0';
    bool result = isdigit(achar);
    REQUIRE(result == true);
}


TEST_CASE("isdigit - testing upper bound 9")
{
    char achar = '9';
    bool result = isdigit(achar);
    REQUIRE(result == true);
}


TEST_CASE("isdigit - testing non digit value a")
{
    char achar = 'a';
    bool result = isdigit(achar);
    REQUIRE(result == false);
}


TEST_CASE("isdigit - testing middle digit value")
{
    char achar = '5';
    bool result = isdigit(achar);
    REQUIRE(result == true);
}
    