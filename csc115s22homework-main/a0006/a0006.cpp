#include "a0006.h"

void createLookup(int *lookUp, int *diceRolls, int rolls) 
{
    int i;
    for (i = 0; i < 7; i++) 
    {
        lookUp[i] = 0;
    }
    for (i = 0; i < rolls; i++)
    {
        if (diceRolls[i] != 0)
        {
            lookUp[diceRolls[i]]++;
        }
    }
}


int fewestRolled(int *lookup, int diceRolls)
{
    int i;
    int fewestRolls = lookup[diceRolls-1];
    int lowestIndex = diceRolls-1;

    for (i = diceRolls - 1; i > 0; i--)
    {
        if (lookup[i] <= fewestRolls)
        {
            fewestRolls = lookup[i];
            lowestIndex = i;
        }
    }

    return lowestIndex;
}

int mostRolled(int *lookup, int diceRolls)
{
    int i;
    int fewestRolls = lookup[diceRolls-1];
    int lowestIndex = diceRolls-1;

    for (i = diceRolls - 1; i > 0; i--)
    {
        if (lookup[i] >= fewestRolls)
        {
            fewestRolls = lookup[i];
            lowestIndex = i;
        }
    }

    return lowestIndex;
}


int sumRolls(int *lookup, int diceRolls)
{
    int i;
    int total = 0;

    for (i = 1; i < diceRolls; i++)
    {
        total += lookup[i] * i;
    }
//
    return total;
}