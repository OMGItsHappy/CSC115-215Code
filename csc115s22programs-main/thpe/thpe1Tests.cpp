#define CATCH_CONFIG_MAIN
#include "..\catch.hpp"
#include "thpe1.h"

/*
card numbers
4794630503276178 valid visa
343669144240775 ae valid
5023589379548211 m v
6440747636070782 d v
7425473237792 uk v

4425473125791 v invalid
34564959068090 ae i
53828876876874 m i
6585288877768476 d i 
741615u722142577 uk i

*/



TEST_CASE("getCCType - testing card number 4425473125791 (Visa)") 
{
    string cardNumber = "4425473125791";
    string result = getCCType(cardNumber);
    REQUIRE(result == "Visa");
}


TEST_CASE("getCCType - testing card number 343669144240775") 
{
    string cardNumber = "343669144240775";
    string result = getCCType(cardNumber);
    REQUIRE(result == "American Express");
}


TEST_CASE("getCCType - testing card number 5023589379548211") 
{
    string cardNumber = "5023589379548211";
    string result = getCCType(cardNumber);
    REQUIRE(result == "Mastercard");
}


TEST_CASE("getCCType - testing card number 6440747636070782") 
{
    string cardNumber = "6440747636070782";
    string result = getCCType(cardNumber);
    REQUIRE(result == "Discover");
}


TEST_CASE("getCCType - testing card number 7425473237792") 
{
    string cardNumber = "7425473237792";
    string result = getCCType(cardNumber);
    REQUIRE(result == "Unknown");
}


TEST_CASE("getCCType - testing card number 4425473125791") 
{
    string cardNumber = "4425473125791";
    string result = getCCType(cardNumber);
    REQUIRE(result == "Visa");
}


TEST_CASE("getCCType - testing card number 34564959068090") 
{
    string cardNumber = "34564959068090";
    string result = getCCType(cardNumber);
    REQUIRE(result == "Unknown");
}


TEST_CASE("getCCType - testing card number 53828876876874") 
{
    string cardNumber = "53828876876874";
    string result = getCCType(cardNumber);
    REQUIRE(result == "Unknown");
}


TEST_CASE("getCCType - testing card number 6585288877768476") 
{
    string cardNumber = "6585288877768476";
    string result = getCCType(cardNumber);
    REQUIRE(result == "Discover");
}


TEST_CASE("getCCType - testing card number 741615u722142577") 
{
    string cardNumber = "741615u722142577";
    string result = getCCType(cardNumber);
    REQUIRE(result == "Unknown");
}

//intOfNum Test Cases

TEST_CASE("intOfNum - tesing first 4 digits of card number 4425473125791")
{
    string cardNumber = "4425473125791";
    int result = intOfNum(cardNumber, 4);
    REQUIRE(result == 4425);
}

TEST_CASE("intOfNum - tesing first 8 digits of card number 4425473125791")
{
    string cardNumber = "4425473125791";
    int result = intOfNum(cardNumber, 8);
    REQUIRE(result == 44254731);
}


TEST_CASE("intOfNum - tesing first 13 digits of card number 4425473125791")
{
    string cardNumber = "4425473125791";
    int result = intOfNum(cardNumber, 9); // cant go higher as integer overflow is an issue
    REQUIRE(result == 442547312);
}

// testing whatToAdd function

TEST_CASE("whatToAdd - tesing 1 not doubed")
{
    char digit = '1';
    int result = whatToAdd(digit, false);
    REQUIRE(result == 1);
}

TEST_CASE("whatToAdd - tesing 9 not doubed")
{
    char digit = '9';
    int result = whatToAdd(digit, false);
    REQUIRE(result == 9);
}

TEST_CASE("whatToAdd - tesing 9 doubed")
{
    char digit = '9';
    int result = whatToAdd(digit, true);
    REQUIRE(result == 9);
}


TEST_CASE("whatToAdd - tesing 4 doubed")
{
    char digit = '4';
    int result = whatToAdd(digit, true);
    REQUIRE(result == 8);
}


TEST_CASE("whatToAdd - tesing 5 doubed")
{
    char digit = '5';
    int result = whatToAdd(digit, true);
    REQUIRE(result == 1);
}

//luhnsAlgo testing 

TEST_CASE("luhnsAlgo - tesing card number 4716150722142577, 16 digit")
{
    string cardNumber = "4716150722142577";
    bool result = luhnsAlgo(cardNumber);
    REQUIRE(result == true);
}


TEST_CASE("luhnsAlgo - tesing card number 4456895832624, 13 digit")
{
    string cardNumber = "4456895832624";
    bool result = luhnsAlgo(cardNumber);
    REQUIRE(result == true);
}


TEST_CASE("luhnsAlgo - tesing card number 345649595062090, 15 digit")
{
    string cardNumber = "345649595062090";
    bool result = luhnsAlgo(cardNumber);
    REQUIRE(result == true);
}


TEST_CASE("luhnsAlgo - tesing card number 3456305812624, 13 digit")
{
    string cardNumber = "3456305812624";
    bool result = luhnsAlgo(cardNumber);
    REQUIRE(result == false);
}


TEST_CASE("luhnsAlgo - tesing card number 6440747636070782, 16 digit")
{
    string cardNumber = "6440747636070782";
    bool result = luhnsAlgo(cardNumber);
    REQUIRE(result == true);
}


TEST_CASE("luhnsAlgo - tesing card number 741615u722142577, 16 digit")
{
    string cardNumber = "741615u722142577";
    bool result = luhnsAlgo(cardNumber);
    REQUIRE(result == false);
}

// Testing isValidCC

/*
card numbers
4794630503276178 valid visa
343669144240775 ae valid
5023589379548211 m v
6440747636070782 d v
7425473237792 uk v

4425473125791 v invalid
34564959068090 ae i
53828876876874 m i
6585288877768476 d i
741615u722142577 uk i

*/

TEST_CASE("isValidCC - tesing card number 4794630503276178, 16 digit")
{
    string cardNumber = "4794630503276178";
    bool result = isValidCC(cardNumber);
    REQUIRE(result == true);
}


TEST_CASE("isValidCC - tesing card number 343669144240775, 15 digit")
{
    string cardNumber = "343669144240775";
    bool result = isValidCC(cardNumber);
    REQUIRE(result == true);
}


TEST_CASE("isValidCC - tesing card number 5023589379548211, 16 digit")
{
    string cardNumber = "5023589379548211";
    bool result = isValidCC(cardNumber);
    REQUIRE(result == true);
}


TEST_CASE("isValidCC - tesing card number 6440747636070782, 16 digit")
{
    string cardNumber = "6440747636070782";
    bool result = isValidCC(cardNumber);
    REQUIRE(result == true);
}


TEST_CASE("isValidCC - tesing card number 7425473237792, 13 digit")
{
    string cardNumber = "7425473237792";
    bool result = isValidCC(cardNumber);
    REQUIRE(result == true);
}


TEST_CASE("isValidCC - tesing card number 4425473125791, 13 digit")
{
    string cardNumber = "4425473125791";
    bool result = isValidCC(cardNumber);
    REQUIRE(result == false);
}


TEST_CASE("isValidCC - tesing card number 34564959068090, 14 digit")
{
    string cardNumber = "34564959068090";
    bool result = isValidCC(cardNumber);
    REQUIRE(result == false);
}


TEST_CASE("isValidCC - tesing card number 53828876876874, 15 digit")
{
    string cardNumber = "53828876876874";
    bool result = isValidCC(cardNumber);
    REQUIRE(result == false);
}


TEST_CASE("isValidCC - tesing card number 6585288877768476, 16 digit")
{
    string cardNumber = "6585288877768476";
    bool result = isValidCC(cardNumber);
    REQUIRE(result == false);
}


TEST_CASE("isValidCC - tesing card number 741615u722142577, 16 digit")
{
    string cardNumber = "741615u722142577";
    bool result = isValidCC(cardNumber);
    REQUIRE(result == false);
}