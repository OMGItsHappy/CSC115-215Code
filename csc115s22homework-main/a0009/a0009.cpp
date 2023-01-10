#include "a0009.h"

//write functions here

void swapStrings(char s1[], char s2[])
{
    int i;
    char temp;
    int maxLength = (strlen(s1) > strlen(s2)) ? strlen(s1) : strlen(s2);

    for (i = 0; i < (int) maxLength; i++)
    {
        temp = s1[i];
        s1[i] = s2[i];
        s2[i] = temp;
    }
}


void sortOrder(char array[][21], int size)
{
    int i;
    int z;

    for (i = 0; i < size; i++)
    {
        for (z = 0; z < size - i - 1; z++)
        {
            if (strcmp(array[z], array[z+1]) > 0)
            {
                swapStrings(array[z], array[z+1]);
            }
        }
    }
}


void sortLen(char array[][21], int size)
{
    int maxLen;
    int i;
    int z;

    for (i = 0; i < size; i++)
    {
        maxLen = i;
        for (z = i; z < size; z++)
        {
            if (strlen(array[z]) < strlen(array[maxLen]))
            {
                maxLen = z;
            }
        }

        swapStrings(array[i], array[maxLen]);
    }
} 