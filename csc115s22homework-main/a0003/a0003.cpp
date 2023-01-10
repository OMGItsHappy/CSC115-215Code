#include "a0003.h"

               
int countCharacters(string stringToCheck, char charToCount)
{
    int total = 0;
    for (int i = 0; i < int(stringToCheck.size()); i++)
    {
        char currentLetter = (char) tolower(stringToCheck.at(i));
        if (currentLetter == tolower(charToCount))
        {
            total += 0;
        }
        total += int(currentLetter == tolower(charToCount));
    }
    return total;
}