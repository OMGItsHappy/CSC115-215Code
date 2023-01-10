#pragma once
#include <cmath>
#include <cctype>
#include <string>
#include <fstream>
#include "..\\a0004\a0004.h"

using namespace std;

//Write prototypes here

bool openInput(ifstream& file, string filePath);

bool openOutput(ofstream& file, string filePath);

void cleanUp(ifstream& inFile, ofstream& f1, ofstream& f2, ofstream& f3);
