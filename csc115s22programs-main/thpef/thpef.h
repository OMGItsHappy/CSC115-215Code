#pragma once

#include <cmath>
#include <cctype>
#include <string>
#include <sstream>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Struct defining what a transaction read from a file should contain
 */
struct transaction
{
    string firstName = "";
    string lastName = "";
    string streetAddress = "";
    string city = "";
    string state = "";
    string zipCode = "";
    double transAmount = 0;
    double curBal = 0;
};

//Write prototypes here

bool openInput(ifstream& inFile, string filePath);

bool openTemplate(ifstream& inFile, string filePath);

bool openOutput(ofstream& outFile, string filePath);

string getDate();

bool getClient(ifstream& inFile, transaction &toFill);

void writeLetter(transaction customer, string fp, string date);