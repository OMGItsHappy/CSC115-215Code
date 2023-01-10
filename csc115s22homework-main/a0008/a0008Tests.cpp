#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "a0008.h"

//write test cases here


TEST_CASE("splitNameLF - test case Schwab, Oliver testing with a comma")
{
    string fullName = "Schwab, Oliver";
    string firstName, lastName;

    splitNameLF(fullName, firstName, lastName);

    REQUIRE(fullName == "Schwab, Oliver");
    REQUIRE(firstName == "Oliver");
    REQUIRE(lastName == "Schwab");
}


TEST_CASE("splitNameLF - testing Rubble, Barney") 
{
    string fullName = "Rubble, Barney";
    string firstName, lastName;

    splitNameLF(fullName, firstName, lastName);

    REQUIRE(fullName == "Rubble, Barney");
    REQUIRE(firstName == "Barney");
    REQUIRE(lastName == "Rubble");
}

// first last


TEST_CASE("splitNameLF- intial test case Oliver Schwab testing without a comma")
{
    string fullName = "Oliver Schwab";
    string firstName, lastName;

    splitNameFL(fullName, firstName, lastName);

    REQUIRE(fullName == "Oliver Schwab");
    REQUIRE(firstName == "Oliver");
    REQUIRE(lastName == "Schwab");
}   


TEST_CASE("splitNameFL - testing Barney Rubble")
{
    string fullName = "Barney Rubble";
    string firstName, lastName;

    splitNameFL(fullName, firstName, lastName);

    REQUIRE(fullName == "Barney Rubble");
    REQUIRE(firstName == "Barney");
    REQUIRE(lastName == "Rubble");
}


// email


TEST_CASE("createEmail - intial test case Oliver Schwab mines.sdsmt.edu")
{
    string firstName = "Oliver";
    string lastName = "Schwab";
    string domainName = "mines.sdsmt.edu";
    string email = createEmail(firstName, lastName, domainName);

    REQUIRE(email == "Oliver.Schwab@mines.sdsmt.edu");
}


TEST_CASE("createEmail - testing Barney Rubble gmail.com")
{
    string firstName = "Barney";
    string lastName = "Rubble";
    string domainName = "gmail.com";
    string email = createEmail(firstName, lastName, domainName);

    REQUIRE(email == "Barney.Rubble@gmail.com");
}


TEST_CASE("createEmail - testing sara sherman discoveryhorse.com")
{
    string firstName = "sara";
    string lastName = "sherman";
    string domainName = "discoveryhorse.com";
    string email = createEmail(firstName, lastName, domainName);

    REQUIRE(email == "sara.sherman@discoveryhorse.com");
}


// fixList


TEST_CASE("fixList - intial test case for one item")
{
    string mixed[1] = {"oliver schwab"};

    string firstLast[1];
    string lastFirst[1];
    string email[1];
    fixList(mixed, firstLast, lastFirst, email, 1, "gmail.com");

    REQUIRE(mixed[0] == "oliver schwab");
    REQUIRE(firstLast[0] == "oliver schwab");
    REQUIRE(lastFirst[0] == "schwab, oliver");
    REQUIRE(email[0] == "oliver.schwab@gmail.com");
}


TEST_CASE("fixList - test case for 3 items")
{
    string mixed[3] = {"oliver schwab", "Robble, Barney", "Sherman, Sara"};

    string firstLast[3];
    string lastFirst[3];
    string email[3];
    fixList(mixed, firstLast, lastFirst, email, 3, "mines.sdsmt.edu");

    REQUIRE(mixed[0] == "oliver schwab");
    REQUIRE(firstLast[0] == "oliver schwab");
    REQUIRE(lastFirst[0] == "schwab, oliver");
    REQUIRE(email[0] == "oliver.schwab@mines.sdsmt.edu");

    REQUIRE(mixed[1] == "Robble, Barney");
    REQUIRE(firstLast[1] == "Barney Robble");
    REQUIRE(lastFirst[1] == "Robble, Barney");
    REQUIRE(email[1] == "Barney.Robble@mines.sdsmt.edu");

    REQUIRE(mixed[2] == "Sherman, Sara");
    REQUIRE(firstLast[2] == "Sara Sherman");
    REQUIRE(lastFirst[2] == "Sherman, Sara");
    REQUIRE(email[2] == "Sara.Sherman@mines.sdsmt.edu"); 
}