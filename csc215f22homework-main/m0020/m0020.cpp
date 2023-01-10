#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include <iostream>

using namespace std;

float* minimum(float array[], int arraySize);
float* maximum(float array[], int arraySize);

// you must change this to false before submitting with a [ci test]
const bool RUNCATCH = false;

int main(int argc, char* argv[])
{

    float currentNumber;

    int arraySize, index = 0;

    ifstream inFile;
    ofstream outFile;

    Catch::Session session;
    int result;

    if (RUNCATCH)
    {
        result = session.run();
        if (result != 0)
        {
            cout << "Test cases didn't pass." << endl;
            return result;
        }
    }

    if (argc != 3)
    {
        cout << "Usage: m0020.exe inputfile outputfile" << endl;
        return 0;
    }

    inFile.open(argv[1]);

    if (!inFile.is_open())
    {
        cout << "Unable to open input file: " << argv[1] << endl;
        return 0;
    }

    outFile.open(argv[2]);

    if (!outFile.is_open())
    {
        cout << "Unable to open output file: " << argv[2] << endl;
        return 0;
    }

    inFile >> arraySize;

    float * arrayPtr = nullptr;

    arrayPtr = new (nothrow) float[arraySize];

    if (arrayPtr == nullptr)
    {
        cout << "Unable to allocate memory" << endl;
        return 0;
    }   

    while (inFile >> currentNumber && index < arraySize)
    {
        arrayPtr[index] = currentNumber;
        index++;
    }

    arraySize = index;

    outFile << arraySize << endl;

    outFile << fixed << setprecision(3);

    outFile << *minimum(arrayPtr, arraySize) << " - " << *maximum(arrayPtr, arraySize) << endl;

    for (index = 0; index < arraySize; index++)
    {
        outFile << setw(15) << fixed << setprecision(3);

        outFile << arrayPtr[index];

        if ((index + 1) % 5 == 0 || index + 1 == arraySize)
        {
            outFile << endl;
        }
    }

    delete[] arrayPtr;

    inFile.close();
    outFile.close();

    // write your code h ere.
    return 0;
}


float * minimum(float array[], int arraySize)
{
    float* currentValuePtr = nullptr;
    int index = 0;

    currentValuePtr = &array[0];

    for (index; index < arraySize; index++)
    {
        if (*currentValuePtr > array[index])
        {
            currentValuePtr = &array[index];
        }
    }

    return currentValuePtr;
}

float* maximum(float array[], int arraySize)
{
    float* currentValuePtr = nullptr;
    int index = 0;

    currentValuePtr = &array[0];

    for (index; index < arraySize; index++)
    {
        if (*currentValuePtr < array[index])
        {
            currentValuePtr = &array[index];
        }
    }

    return currentValuePtr;
}


