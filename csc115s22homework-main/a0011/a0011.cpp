#include "a0011.h"

//write functions here



bool openInput(ifstream& file, string filePath)
{
    file.open(filePath);

    if (!file.is_open())
    {
        return false;
    }

    return true;
}


bool openOutput(ofstream& file, string filePath)
{
    file.open(filePath);

    if (!file.is_open())
    {
        return false;
    }

    return true;
}


void cleanUp(ifstream& inFile, ofstream& f1, ofstream& f2, ofstream& f3)
{
    inFile.close();
    f1.close();
    f2.close();
    f3.close();
    exit(0);
}