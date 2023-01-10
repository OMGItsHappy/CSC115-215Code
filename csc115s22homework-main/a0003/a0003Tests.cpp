#define CATCH_CONFIG_MAIN
#include "..\catch.hpp"
#include "a0003.h"
               
TEST_CASE("countCharacters - tesing a single character")
{
    char testCharacter = 'a';
    string testString = "a";
    
    int result = countCharacters(testString, testCharacter);
    
    REQUIRE(result == 1);
}


TEST_CASE("countCharacters - tesing a number of random letters, all lower case")
{
    char testCharacter = 'a';
    string testString = "123asdadfsadfsdfasgdsfa"; // 5
    
    int result = countCharacters(testString, testCharacter);
    
    REQUIRE(result == 5);
}


TEST_CASE("countCharacters - Testing uppercase characters")
{
    char testCharacter = 'a';
    string testString = "A";
    
    int result = countCharacters(testString, testCharacter);
    
    REQUIRE(result == 1);
}


TEST_CASE("countCharacters - testing a number of upper case letters")
{
    char testCharacter = 'A';
    string testString = "AsdsdsFAsdsdsArtertA"; // 4
    
    int result = countCharacters(testString, testCharacter);
    
    REQUIRE(result == 4);
}


TEST_CASE("countCharacters - testing uppercase char and uppercase string")
{
    char testCharacter = 'A';
    string testString = "A"; // 1
    
    int result = countCharacters(testString, testCharacter);
    
    REQUIRE(result == 1);
}


TEST_CASE("countCharacters - Testing uppercase char and lowercase string")
{
    char testCharacter = 'A';
    string testString = "a"; // 1
    
    int result = countCharacters(testString, testCharacter);
    
    REQUIRE(result == 1);
}


TEST_CASE("countCharacters - Testing uppercase char and both uppercase and lowercase string")
{
    char testCharacter = 'A';
    string testString = "AdfdaAasdsaA"; // 6
    
    int result = countCharacters(testString, testCharacter);
    
    REQUIRE(result == 6);
}


TEST_CASE("countCharacters - testing lowercase char and both upper and lowercase string")
{
    char testCharacter = 'a';
    string testString = "AasdaaaFSFAAa"; // 8
    
    int result = countCharacters(testString, testCharacter);
    
    REQUIRE(result == 8);
}