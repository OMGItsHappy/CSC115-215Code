#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "a0011.h"
const bool RUNCATCH = false;
int main(int argc, char **argv)
{
    Catch::Session session;
    int result1;
    if (RUNCATCH)
    {
        result1 = session.run();
        if (result1 != 0)
        {
            cout << "Test cases didn’t pass." << endl;
            return result1;
        }
    }

    if (argc != 5)
    {
        cout << "Usage: a0011.exe datafile primefile evenfile oddfile";
        exit(0);
    }

    ifstream dataFile;
    ofstream primeFile, evenFile, oddFile;
    
    bool result;
    int i, temp;

    result = openInput(dataFile, argv[1]);

    if (!result)
    {
        cout << "Unable to open file: " << argv[1] << endl;
    }

    result = openOutput(primeFile, argv[2]);

    if (!result)
    {
        cout << "Unable to open file: " << argv[2] << endl;
    }

    result = openOutput(evenFile, argv[3]);

    if (!result)
    {
        cout << "Unable to open file: " << argv[3] << endl;
    }
    result = openOutput(oddFile, argv[4]);

    if (!result)
    {
        cout << "Unable to open file: " << argv[4] << endl;
    }

    i = 0;
    while (i < 10000 && dataFile >> temp)
    {
        result = isPrime(temp);
        if (result)
        {
            primeFile << setw(10) << temp << endl;
        }   else if (temp % 2 == 0)
        {
            evenFile << setw(10) << temp << endl;
        }   else
        {
            oddFile << setw(10) << temp << endl;
        }
        i++;
    }

    cleanUp(dataFile, primeFile, evenFile, oddFile);
    

    // write your code here
    return 0;
}


TEST_CASE("openInput - intial test case")
{
    ifstream datapath;
    string fp = "here";
    bool result = openInput(datapath, fp);
    REQUIRE(result == false);
}


TEST_CASE("openInput - testing an openable file")
{
    ifstream df;
    string fp = "given1.txt";
    bool result = openInput(df, fp);
    REQUIRE(result == true);
    string output;
    getline(df, output);
    REQUIRE(output.substr(0, 3) == "81");
}


TEST_CASE("openInput - testing nonexistent file")
{
    ifstream df;
    string fp = "oliver.txt";
    bool result = openInput(df, fp);
    REQUIRE(result == false);
}


TEST_CASE("openOutput - intial test case")
{
    ofstream f;
    string fp = "oliver";
    bool result = openOutput(f, fp);
    REQUIRE(result == true);
}


TEST_CASE("openOutput - testing an unopenable file")
{
    ofstream df;
    string fp = "P:\\oliver.txt";
    bool result = openOutput(df, fp);
    REQUIRE(result == false);
}