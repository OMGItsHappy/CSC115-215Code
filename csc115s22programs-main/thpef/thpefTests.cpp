#define CATCH_CONFIG_RUNNER
#define _CRT_SECURE_NO_WARNINGS
#include "..\\catch.hpp"
#include "thpef.h"
#include "ourDate.h"

const bool RUNCATCH = false;
int main(int argc, char **argv)
{
    argv;
    Catch::Session session;
    int result;
    if (RUNCATCH)
    {
        result = session.run();
        if (result != 0)
        {
            cout << "Test cases didn't pass." << endl;
            return result;
        }
    }

    ifstream dataFile;
    string fileToOpen, date;
    transaction tempCustomer, reset;

    if (argc != 5) 
        cout << "Usage: thpef.exe datafile template1 template2 template3\n"
             <<   "       datafile --name of input data file\n"
             <<   "       template1 --name of purchase template file\n"
             <<   "       template2 --name of payment template file\n"
             <<   "       template3 --name of overdue template file";

    fileToOpen = argv[1];

    if (openInput(dataFile, fileToOpen) == false) exit(0);

    while (!dataFile.eof())
    {
        getClient(dataFile, tempCustomer);

        fileToOpen = argv[2];

        if (tempCustomer.transAmount == 0 && tempCustomer.curBal == 0)
        {
            continue;
        }
        else if (tempCustomer.transAmount == 0)
        {
            fileToOpen = argv[4];
        }
        else if (tempCustomer.transAmount < 0)
        {
            fileToOpen = argv[3];
        }

        tempCustomer.curBal += tempCustomer.transAmount;

        date = currDate;

        if (currDate == "") date = getDate();

        writeLetter(tempCustomer, fileToOpen, date);

        tempCustomer = reset;
    }

    

    return 0;
} 

// write test cases here


TEST_CASE("getDate - test case with currect date")
{

    REQUIRE(getDate().compare("30 Apr, 2022") == 0);

}


TEST_CASE("getClient - intial test case")
{
    ifstream inFile;
    ofstream tempFile;

    tempFile.open("test1.txt");

    tempFile << "James,Smith,123 Main St,Rapid City,SD,57701,89.55,12.5";

    tempFile.close();

    inFile.open("test1.txt");

    transaction test;

    REQUIRE(getClient(inFile, test) == true);

    inFile.close();
}


TEST_CASE("getClient - testing empty file")
{
    ifstream inFile;
    ofstream tempFile;

    tempFile.open("test1.txt");

    tempFile << "";

    tempFile.close();

    inFile.open("test1.txt");

    transaction test;

    REQUIRE(getClient(inFile, test) == false);

    inFile.close();
}


TEST_CASE("getClient - testing data was correctly read")
{
    ifstream inFile;
    ofstream tempFile;

    tempFile.open("test1.txt");

    tempFile << "James,Smith,123 Main St,Rapid City,SD,57701,89.55,12.5";

    tempFile.close();

    inFile.open("test1.txt");

    transaction test;

    REQUIRE(getClient(inFile, test) == true);

    REQUIRE(test.zipCode == "57701");

    inFile.close();
}


TEST_CASE("writeLetter - intial test case")
{
    ifstream clients;
    transaction customer;
    ofstream tempFile;
    
    tempFile.open("test1.txt");

    tempFile << "James,Smith,123 Main St,Rapid City,SD,57701,89.55,12.5";

    tempFile.close();

    openInput(clients, "test1.txt");

    getClient(clients, customer);

    writeLetter(customer, "purchaseTemplate.txt", getDate());

    REQUIRE(true == true); //testing that the function caled without and error
}



TEST_CASE("writeLetter - testing a paymentTemplate")
{
    ifstream clients;
    transaction customer;
    ofstream tempFile;
    string tempStr;
    
    tempFile.open("test1.txt");

    tempFile << "Kelly,Bundy,9801 5th St,Rapid City,SD,57702,-901.55,901.55";

    tempFile.close();

    openInput(clients, "test1.txt");

    getClient(clients, customer);

    writeLetter(customer, "paymentTemplate.txt", getDate());

   clients.close();
   clients.clear();

    openInput(clients, customer.firstName + "." + customer.lastName + ".txt");

    clients >> tempStr;
    
    REQUIRE(tempStr == "Kelly");

    clients.close();
    clients.clear();
}


TEST_CASE("writeLetter - testing purchase template")
{
    ifstream clients;
    transaction customer;
    ofstream tempFile;
    string tempStr;
    
    tempFile.open("test1.txt");

    tempFile << "James,Smith,123 Main St,Rapid City,SD,57701,-89.55,100.00";

    tempFile.close();

    openInput(clients, "test1.txt");

    getClient(clients, customer);

    writeLetter(customer, "paymentTemplate.txt", getDate());

   clients.close();
   clients.clear();

    openInput(clients, customer.firstName + "." + customer.lastName + ".txt");

    clients >> tempStr;
    
    REQUIRE(tempStr == "James");

       clients.close();
   clients.clear();
}


TEST_CASE("writeLetter - testing overdue template")
{
    ifstream clients;
    transaction customer;
    ofstream tempFile;
    string tempStr;
    
    tempFile.open("test1.txt");

    tempFile << "Elon,Musk,1001 Wizard Ave,Buena Vista,CA,90210,0.0,2304500.0";

    tempFile.close();

    openInput(clients, "test1.txt");

    getClient(clients, customer);

    writeLetter(customer, "overdueTemplate.txt", getDate());

   clients.close();
   clients.clear();

    openInput(clients, customer.firstName + "." + customer.lastName + ".txt");

    clients >> tempStr;
    
    REQUIRE(tempStr == "Elon");

       clients.close();
   clients.clear();
}


TEST_CASE("openInput - intial test case")
{
    ifstream datapath;
    string fp = "here";
    bool result = openInput(datapath, fp);
    REQUIRE(result == false);
}


TEST_CASE("openInput - testing an openable file")
{
    ofstream testFile;

    testFile.open("given1.txt");

    testFile.close();

    ifstream df;
    string fp = "given1.txt";
    bool result = openInput(df, fp);
    REQUIRE(result == true);
}


TEST_CASE("openInput - testing nonexistent file")
{
    ifstream df;
    string fp = "oliver.txt";
    bool result = openInput(df, fp);
    REQUIRE(result == false);
}


TEST_CASE("openOutput - intial test case")
{
    ofstream f;
    string fp = "oliver";
    bool result = openOutput(f, fp);
    REQUIRE(result == true);
}

TEST_CASE("openOutput - testing an unopenable file")
{
    ofstream df;
    string fp = "P:\\oliver.txt";
    bool result = openOutput(df, fp);
    REQUIRE(result == false);
}


TEST_CASE("openTemplate - intial test case")
{
    ifstream datapath;
    string fp = "here";
    bool result = openTemplate(datapath, fp);
    REQUIRE(result == false);
}


TEST_CASE("openTemplate - testing an openable file")
{
    ofstream testFile;

    testFile.open("given1.txt");

    testFile.close();

    ifstream df;
    string fp = "given1.txt";
    bool result = openTemplate(df, fp);
    REQUIRE(result == true);
}


TEST_CASE("openTemplate - testing nonexistent file")
{
    ifstream df;
    string fp = "oliver.txt";
    bool result = openTemplate(df, fp);
    REQUIRE(result == false);
} 