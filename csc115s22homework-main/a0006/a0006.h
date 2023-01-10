#pragma once
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

void createLookup(int *lookUp, int *diceRolls, int rolls);

int fewestRolled(int *lookup, int diceRolls);

int mostRolled(int *lookup, int diceRolls);

int sumRolls(int *lookup, int diceRolls);

//