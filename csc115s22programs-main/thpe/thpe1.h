/** ************************************************************
 * @file
***************************************************************/

#pragma once
#include <string>
#include <cctype>
#include <cmath> 

using namespace std;

string getCCType(string cardNumber);

int intOfNum(string cardNumber, int digits);

bool luhnsAlgo(string cardNumber);

int whatToAdd(char digit, bool toDouble);

bool isValidCC(string cardNumber);