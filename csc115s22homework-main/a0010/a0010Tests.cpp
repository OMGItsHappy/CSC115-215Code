#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "a0010.h"

//write test cases here

const bool RUNCATCH = false;
//while cin >> num
int main()
{
    Catch::Session session;
    int result;

    if (RUNCATCH)
    {
        result = session.run();
        if(result != 0)
        {
            cout << "Test cases didn't pass" << endl;
            return result;
        }
    }


    cout << fixed << showpoint << setprecision(4);

    // first one ready for file

    int total = 0;
    int array[1000] = {};
    cout << "Enter up to 1000 integers, <ctrl>-z to stop: " << endl;
    while (total < 1000 && cin >> array[total])
    {
        total += 1;
    }
    sortArray(array, total);
    cout << "Quantity: " << total << endl;
    cout << "Range: ";
    cout << min(array, total);
    cout << " to ";
    cout << max(array, total);
    cout << "\nSum: ";
    cout << sumArray(array, total);
    cout << "\nAverage: ";

    cout << average(array, total) << "\nData: " << endl;
    int i;
    for (i = 0; i < total; i++) 
    {
        cout << setw(10) << array[i];
        if ((i + 1) % 5 == 0)
        {
            cout << endl;
        }
       
    }
    
    cout << endl;

    return 0;
}


TEST_CASE("sortArray - intial test case with already sorted array")
{
    int array[2] = {1,2};

    sortArray(array, 2);

    REQUIRE(array[0] == 1);
    REQUIRE(array[1] == 2);
}


TEST_CASE("sortArray - testing array with 5 elements")
{
    int array[5] = {2,5,1,4,8};

    sortArray(array, 5);

    REQUIRE(array[0] == 1);
    REQUIRE(array[2] == 4);
    REQUIRE(array[4] == 8);
}


TEST_CASE("sortArray - testing array with 10 elements including negitives")
{

    int array[10] = {2,5,1,4,8, -2, -66, -6, 15, 2};

    sortArray(array, 10);

    REQUIRE(array[0] == -66);
    REQUIRE(array[5] == 2);
    REQUIRE(array[9] == 15);

}


TEST_CASE("sumArray - intial test case for array with 1 elemnt of zero")
{
    int array[1] = {0};

    int sum = sumArray(array, 1);

    REQUIRE(sum == 0);
}


TEST_CASE("sumArray - testing array with 5 elements")
{
    int array[5] = {2,5,1,4,8};

    int sum = sumArray(array, 5);

    REQUIRE(sum == 20);
}


TEST_CASE("sumArray - testing array with 10 elements including negitives")
{

    int array[10] = {2,5,1,4,8, -2, -66, -6, 15, 2};

    int sum = sumArray(array, 10);

    REQUIRE(sum == -37);

}