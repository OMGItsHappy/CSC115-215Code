#include "a0007.h"

//write functions here

void sortByID(string* names, int* IDs, int lengths)
{
    int out;
    int in;
    int temp;
    string tempStr;
    for (out = 0; out < lengths - 1; out++)
    {
        for (in = 0; in < lengths - out - 1; in++)
        {
            if (IDs[in] > IDs[in + 1])
            {
                temp = IDs[in];
                IDs[in] = IDs[in + 1];
                IDs[in + 1] = temp;

                tempStr = names[in];
                names[in] = names[in + 1];
                names[in + 1] = tempStr;
            }
        }
    }
}


void sortByName(string * names, int * IDs, int lengths)
{
    int out;
    int in;
    int temp;
    string tempStr;
    string str1;
    string str2;
    for (out = 0; out < lengths - 1; out++)
    {
        for (in = 0; in < lengths - out - 1; in++)
        {           
            str1 = names[in];
            str2 = names[in + 1];
            if (strcmp(str1.c_str(), str2.c_str()) > 0)
            {
                temp = IDs[in];
                IDs[in] = IDs[in + 1];
                IDs[in + 1] = temp;

                tempStr = names[in];
                names[in] = names[in + 1];
                names[in + 1] = tempStr;
            }
        }
    }
}

int getID(string* names, int* IDs, int length, string person)
{
    int i;

    for (i = 0; i < length; i++) 
    {
        if (names[i] == person)
        {
            return IDs[i];
        }
    }

    return -1;
}

string getName(string* names, int* IDs, int length, int ID)
{
    int i;

    for (i = 0; i < length; i++)
    {
        if(IDs[i] == ID)
        {
            return names[i];
        }
    }

    return "";
}