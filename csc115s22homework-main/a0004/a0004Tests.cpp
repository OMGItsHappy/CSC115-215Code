#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "a0004.h"

TEST_CASE("isPrime - testing the int value 2")
{
    int testValue = 2;
    bool result = isPrime(testValue);
    result;
    REQUIRE(result == true);
}


TEST_CASE("isPrime - testing the int value 0") {
    int testValue = 0;
    bool result = isPrime(testValue);
    REQUIRE(result == false);
}


TEST_CASE("isPrime - testing the int value 1") {
    int testValue = 1;
    bool result = isPrime(testValue);
    REQUIRE(result == false);
}


TEST_CASE("isPrime - testing the int value 7919") {
    int testValue = 7919;
    bool result = isPrime(testValue);
    REQUIRE(result == true);
}

TEST_CASE("isPrime - testing the int value 17") {
    int testValue = 17;
    bool result = isPrime(testValue);
    REQUIRE(result == true);
}


TEST_CASE("isPrime - testing the int value -5") {
    int testValue = -5;
    bool result = isPrime(testValue);
    REQUIRE(result == false);
}


TEST_CASE("isPrime - testing the int value 4") {
    int testValue = 4;
    bool result = isPrime(testValue);
    REQUIRE(result == false);
}


TEST_CASE("isTwinPrime - testing the int value 3") {
    int testValue = 3;
    bool result = isTwinPrime(testValue);
    REQUIRE(result == true);
}


TEST_CASE("isTwinPrime - testing the int value 5") {
    int testValue = 5;
    bool result = isTwinPrime(testValue);
    REQUIRE(result == true);
}


TEST_CASE("isTwinPrime - testing the int value 17") {
    int testValue = 17;
    bool result = isTwinPrime(testValue);
    REQUIRE(result == true);
}


TEST_CASE("isTwinPrime - testing the int value 10007") {
    int testValue = 10007;
    bool result = isTwinPrime(testValue);
    REQUIRE(result == true);
}


TEST_CASE("isTwinPrime - testing the int value 2") {
    int testValue = 2;
    bool result = isTwinPrime(testValue);
    REQUIRE(result == false);
}


TEST_CASE("isTwinPrime - testing the int value 0") {
    int testValue = 0;
    bool result = isTwinPrime(testValue);
    REQUIRE(result == false);
}


TEST_CASE("NextPrime - testing the int value 2") {
    int testValue = 2;
    int result = nextPrime(testValue);
    REQUIRE(result == 3);
}


TEST_CASE("NextPrime - testing the int value 3") {
    int testValue = 3;
    int result = nextPrime(testValue);
    REQUIRE(result == 5);
}


TEST_CASE("NextPrime - testing the int value 4") {
    int testValue = 4;
    int result = nextPrime(testValue);
    REQUIRE(result == 5);
}


TEST_CASE("NextPrime - testing the int value 10") {
    int testValue = 10;
    int result = nextPrime(testValue);
    REQUIRE(result == 11);
}


TEST_CASE("NextPrime - testing the int value 7") {
    int testValue = 7;
    int result = nextPrime(testValue);
    REQUIRE(result == 11);
}


TEST_CASE("NextPrime - testing the int value 0") {
    int testValue = 0;
    int result = nextPrime(testValue);
    REQUIRE(result == 2);
}


TEST_CASE("NextPrime - testing the int value 1") {
    int testValue = 1;
    int result = nextPrime(testValue);
    REQUIRE(result == 2);
}


TEST_CASE("NextPrime - testing the int value ") {
    int testValue = 1000003;
    int result = nextPrime(testValue);
    REQUIRE(result == 1000033);
}

