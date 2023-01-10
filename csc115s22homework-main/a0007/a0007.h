#pragma once
#include <cmath>
#include <cctype>
#include <string>

using namespace std;

//Write prototypes here

void sortByID(string* names, int* IDs, int lenths);

void sortByName(string * names, int * IDs, int lengths);

int getID(string* names, int* IDs, int length, string person);

string getName(string* names, int* IDs, int length, int ID);