#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "thpe2.h"

/*
TEST_CASE("mySqrt - testing value of ")
{
    double testVal = ;
    double result = mySqrt(testVal);

    REQUIRE(result == Approx(sqrt()));
}
*/

TEST_CASE("mySqrt - intial test case, using value of 1")
{
    double testVal = 1.0;
    double result = mySqrt(testVal);
    double expected = 1.0;

    REQUIRE(result == Approx(expected));
}


TEST_CASE("mySqrt - testing value of ")
{
    double testVal = 4.0;
    double result = mySqrt(testVal);

    REQUIRE(result == Approx(2.0));
}

TEST_CASE("mySqrt - testing value of 1.1")
{
    double testVal = 1.1;
    double result = mySqrt(testVal);

    REQUIRE(result == Approx(sqrt(1.1)));
}


TEST_CASE("mySqrt - testing value of 10")
{
    double testVal = 10;
    double result = mySqrt(testVal);

    REQUIRE(result == Approx(sqrt(10)));
}


TEST_CASE("mySqrt - testing value of 100")
{
    double testVal = 100;
    double result = mySqrt(testVal);

    REQUIRE(result == Approx(sqrt(100)));
}


TEST_CASE("mySqrt - testing value of .8")
{
    double testVal = 0.8;
    double result = mySqrt(testVal);

    REQUIRE(result == Approx(sqrt(0.8)));
}


TEST_CASE("mySqrt - testing value of 1212")
{
    double testVal = 1212;
    double result = mySqrt(testVal);

    REQUIRE(result == Approx(sqrt(1212)));
}

TEST_CASE("mySqrt - testing value of 0")
{
    double testVal = 0;
    double result = mySqrt(testVal);

    REQUIRE(result == Approx(sqrt(0)));
}


TEST_CASE("mySqrt - testing value of -1")
{
    double testVal = -1;
    double result = mySqrt(testVal);

    REQUIRE(result == 0);
}


TEST_CASE("myCbrt - Intial test case, using -1")
{   
    double testVal = -1;
    double result = myCbrt(testVal);

    REQUIRE(result == 0);
}
/*
TEST_CASE("testing  ")
{
    double testVal = ;
    double result = myCbrt(testVal);

    REQUIRE(result == Approx(cbrt(testVal)));
}
*/

TEST_CASE("myCbrt - testing  1")
{
    double testVal = 1;
    double result = myCbrt(testVal);

    REQUIRE(result == Approx(cbrt(testVal)));
}


TEST_CASE("myCbrt - testing  2")
{
    double testVal = 2;
    double result = myCbrt(testVal);

    REQUIRE(result == Approx(cbrt(testVal)));
}


TEST_CASE("myCbrt - testing  3")
{
    double testVal = 3;
    double result = myCbrt(testVal);

    REQUIRE(result == Approx(cbrt(testVal)));
}


TEST_CASE("myCbrt - testing  10")
{
    double testVal = 10;
    double result = myCbrt(testVal);

    REQUIRE(result == Approx(cbrt(testVal)));
}


TEST_CASE("myCbrt - testing  0")
{
    double testVal = 0;
    double result = myCbrt(testVal);

    REQUIRE(result == 0);
}


TEST_CASE("myCbrt - testing  .5")
{
    double testVal = .5;
    double result = myCbrt(testVal);

    REQUIRE(result == Approx(cbrt(testVal)));
}

/*
TEST_CASE("myLog - intial test case  base")
{
    double testVal = ;
    int testBase = ;
    double result = myLog(testVal, testBase);

    REQUIRE(result == Approx(log(testVal)/log(testBase)));
}
*/

TEST_CASE("myLog - intial test case 1 base 10")
{
    double testVal = 1;
    int testBase = 10;
    double result = myLog(testVal, testBase);

    REQUIRE(result  * 0 == Approx(log(testVal)/log(testBase)));
}

TEST_CASE("myLog - intial test case 2 base 10")
{
    double testVal = 2;
    int testBase = 10;
    double result = myLog(testVal, testBase);

    REQUIRE(result == Approx(log(testVal)/log(testBase)));
}


TEST_CASE("myLog - intial test case 3 base 9")
{
    double testVal = 3;
    int testBase = 9;
    double result = myLog(testVal, testBase);

    REQUIRE(result == Approx(log(testVal)/log(testBase)));
}


TEST_CASE("myLog - intial test case 10 base 15")
{
    double testVal = 10;
    int testBase = 15;
    double result = myLog(testVal, testBase);

    REQUIRE(result == Approx(log(testVal)/log(testBase)));
}


TEST_CASE("myLog - intial test case 435 base 21")
{
    double testVal = 435;
    int testBase = 21;
    double result = myLog(testVal, testBase);

    REQUIRE(result == Approx(log(testVal)/log(testBase)));
}

/*
TEST_CASE("mySin - testing radian value of ")
{
    double testVal = ;
    double result = mySin(testVal);

    REQUIRE(result == Approx(sin(testVal)));
}
*/

TEST_CASE("mySin - testing radian value of PI/2")
{
    double testVal = PI/2;
    double result = mySin(testVal);

    REQUIRE(fabs(result - 1) < ERRORTOLERANCE);
}


TEST_CASE("mySin - testing radian value of 0")
{
    double testVal = 0;
    double result = mySin(testVal);

    REQUIRE(fabs(sin(testVal) - result) < ERRORTOLERANCE);
}


TEST_CASE("mySin - testing radian value of pi/4")
{
    double testVal = PI/4;
    double result = mySin(testVal);

    REQUIRE(fabs(sin(testVal) - result) < ERRORTOLERANCE);
}


TEST_CASE("mySin - testing radian value of 1")
{
    double testVal = 1;
    double result = mySin(testVal);

    REQUIRE(fabs(sin(testVal) - result) < ERRORTOLERANCE);
}


TEST_CASE("mySin - testing radian value of -1")
{
    double testVal = -1;
    double result = mySin(testVal);

    REQUIRE(fabs(result - sin(testVal)) < ERRORTOLERANCE);
}


TEST_CASE("mySin - testing radian value of -PI/2")
{
    double testVal = PI/2 * -1;
    double result = mySin(testVal);

    REQUIRE(fabs(result - -1) < ERRORTOLERANCE);
}


TEST_CASE("factorial - intial test case of 1")
{
    int val = 1;
    double result = factorial(val);
    REQUIRE(result == 1);
}

TEST_CASE("factorial - test case of 3")
{
    int val = 3;
    double result = factorial(val);
    REQUIRE(result == 6);
}


TEST_CASE("factorial - test case of 5")
{
    int val = 5;
    double result = factorial(val);
    REQUIRE(result == 120);
}


TEST_CASE("factorial - test case of 9")
{
    int val = 9;
    double result = factorial(val);
    REQUIRE(result == 362880);
}


TEST_CASE("factorial - test case of 4")
{
    int val = 4;
    double result = factorial(val);
    REQUIRE(result == 24);
}



TEST_CASE("mySinD - intial test case of 0")
{
    REQUIRE((mySinD(0) - sin(0)) < ERRORTOLERANCE);
}


TEST_CASE("mySinD - testing degree value of 180/2")
{
    double testVal = 180/2;
    double result = mySinD(testVal);

    REQUIRE((result - sin(PI/2)) < ERRORTOLERANCE);
}


TEST_CASE("mySinD - testing degree value of 60")
{
    double testVal = 60;
    double result = mySinD(testVal);

    REQUIRE((result - sin(PI/3)) < ERRORTOLERANCE);
}


TEST_CASE("mySinD - testing degree value of -60")
{
    double testVal = -60;
    double result = mySinD(testVal);

    REQUIRE((result - sin(-PI/3)) < ERRORTOLERANCE);
}


TEST_CASE("mySinD - testing degree value of -180/2")
{
    double testVal = 180/2 * -1;
    double result = mySinD(testVal);

    REQUIRE((result - sin(-PI/2)) < ERRORTOLERANCE);
}


TEST_CASE("mySinD - testing degree value of 45")
{
    double testVal = 180/2 * -1;
    double result = mySinD(testVal);

    REQUIRE((result - sin(45)) < ERRORTOLERANCE);
}


TEST_CASE("myCos - intial test case of 0")
{
    REQUIRE(myCos(0) == Approx(cos(0)));
}


TEST_CASE("myCos - test case of Pi/2")
{
    REQUIRE(fabs(cos(PI/2) - myCos(PI/2)) <= ERRORTOLERANCE);
}


TEST_CASE("myCos - test case of -Pi/3")
{
    REQUIRE(fabs(cos(-PI/3) - myCos(-PI/3)) <= ERRORTOLERANCE);
}


TEST_CASE("myCos - test case of Pi/3")
{
    REQUIRE(fabs(cos(PI/3) - myCos(PI/3)) <= ERRORTOLERANCE);
}


TEST_CASE("myCos - test case of -Pi/2")
{
    REQUIRE(fabs(cos(-PI/2) - myCos(-PI/2)) <= ERRORTOLERANCE);
}


//cosD


TEST_CASE("myCosD - intial test case of 0")
{
    REQUIRE(myCosD(0) == Approx(cos(0)));
}


TEST_CASE("myCosD - test case of 90")
{
    REQUIRE(fabs(cos(PI/2) - myCosD(90)) <= ERRORTOLERANCE);
}


TEST_CASE("myCosD - test case of -60")
{
    REQUIRE(fabs(cos(-PI/3) - myCosD(-60)) <= ERRORTOLERANCE);
}


TEST_CASE("myCosD - test case of60")
{
    REQUIRE(fabs(cos(PI/3) - myCosD(60)) <= ERRORTOLERANCE);
}


TEST_CASE("myCosD - test case of -90")
{
    REQUIRE(fabs(cos(-PI/2) - myCosD(-90)) <= ERRORTOLERANCE);
}

// tan

TEST_CASE("myTan - intial test case of PI/4")
{
    REQUIRE(fabs(tan(PI/4) - myTan(PI/4)) <= ERRORTOLERANCE);
}


TEST_CASE("myTan - test case of -PI/4")
{
    REQUIRE(fabs(tan(-PI/4) - myTan(-PI/4)) <= ERRORTOLERANCE);
}

TEST_CASE("myTan - test case of PI/3")
{
    REQUIRE(fabs(tan(PI/3) - myTan(PI/3)) <= ERRORTOLERANCE);
}


TEST_CASE("myTan - test case of PI/6")
{
    REQUIRE(fabs(tan(PI/6) - myTan(PI/6)) <= ERRORTOLERANCE);
}


TEST_CASE("myTan - test case of -PI/6")
{
    REQUIRE(fabs(tan(-PI/6) - myTan(-PI/6)) <= ERRORTOLERANCE);
}


TEST_CASE("myTan - test case of 0")
{
    REQUIRE(fabs(tan(0) - myTan(0)) <= ERRORTOLERANCE);
}


//myTanD


TEST_CASE("myTanD - intial test case of 45")
{
    REQUIRE(fabs(tan(PI/4) - myTanD(45)) <= ERRORTOLERANCE);
}


TEST_CASE("myTanD - test case of -45")
{
    REQUIRE(fabs(tan(-PI/4) - myTanD(-45)) <= ERRORTOLERANCE);
}

TEST_CASE("myTanD - test case of 60")
{
    REQUIRE(fabs(tan(PI/3) - myTanD(60)) <= ERRORTOLERANCE);
}


TEST_CASE("myTanD - test case of 30")
{
    REQUIRE(fabs(tan(PI/6) - myTanD(30)) <= ERRORTOLERANCE);
}


TEST_CASE("myTanD - test case of -30")
{
    REQUIRE(fabs(tan(-PI/6) - myTanD(-30)) <= ERRORTOLERANCE);
}


TEST_CASE("myTanD - test case of 0")
{
    REQUIRE(fabs(tan(0) - myTanD(0)) <= ERRORTOLERANCE);
}


//copy array


TEST_CASE("copyArray - intial test case")
{
    int i;
    double source[3] = {0,0,0};
    double dest[3] = {1,2,3};

    copyArray(dest, source, 3);

    for (i = 0; i < 3; i++)
    {
        REQUIRE(dest[i] == source[i]);
    }
}


TEST_CASE("copyArray - testing lenght of 4")
{
    int i;
    double source[4] = {1,3,5,2};
    double dest[4];

    copyArray(dest, source, 4);

    for (i = 0; i < 4; i++)
    {
        REQUIRE(dest[i] == source[i]);
    }
}


TEST_CASE("copyArray - testing length of 7")
{
    int i;
    double source[7] = {6,4,2,7,8,9,0};
    double dest[7];

    copyArray(dest, source, 7);

    for (i = 0; i < 7; i++)
    {
        REQUIRE(dest[i] == source[i]);
    }
}


TEST_CASE("copyArray - testing length of 2") 
{
    int i;
    double source[2] = {-2,5};
    double dest[2];

    copyArray(dest, source, 2);

    for (i = 0; i < 2; i++)
    {
        REQUIRE(dest[i] == source[i]);
    }
}


// intialize


TEST_CASE("initialize - intial test case of length 2")
{
    int i;
    double array[2];
    double intializeVal = 1;

    initialArray(array, 2, intializeVal);

    for (i = 0; i < 2; i++)
    {
        REQUIRE(array[i] == intializeVal);
    }
}


TEST_CASE("initialize - test case of length 3 uninitialized")
{
    int i;
    double array[3];
    double intializeVal = 1;

    initialArray(array, 3, intializeVal);

    for (i = 0; i < 3; i++)
    {
        REQUIRE(array[i] == intializeVal);
    }
}


TEST_CASE("initialize - test case of length 4 initialized")
{
    int i;
    double array[4] = {1,2,3,4};
    double intializeVal = 1;

    initialArray(array, 4, intializeVal);

    for (i = 0; i < 4; i++)
    {
        REQUIRE(array[i] == intializeVal);
    }
}


TEST_CASE("initialize - test case of length 8 initialized")
{
    int i;
    double array[8] = {1,2,3,4,5,6,7,8};
    double intializeVal = 1;

    initialArray(array, 8, intializeVal);

    for (i = 0; i < 8; i++)
    {
        REQUIRE(array[i] == intializeVal);
    }
}


TEST_CASE("initialize - test case of length 8 uninitialized")
{
    int i;
    double array[8];
    double intializeVal = 1;

    initialArray(array, 8, intializeVal);

    for (i = 0; i < 8; i++)
    {
        REQUIRE(array[i] == intializeVal); 
    }
}


//sum array


TEST_CASE("sumArray - intial test case of 0 array")
{
    double array[2] = {0,0};

    double sum = sumArray(array, 2);

    REQUIRE(sum == 0);
}


TEST_CASE("sumArray - test case of 3 values")
{
    double array[3] = {1,2,3};

    double sum = sumArray(array, 3);

    REQUIRE(sum == 6);
}


TEST_CASE("sumArray - test case of six values")
{
    double array[6] = {1,2,3,3,2,1};

    double sum = sumArray(array, 6);

    REQUIRE(sum == 12);
}


TEST_CASE("sumArray - test case of 8 values")
{
    double array[8] = {10,15,5,20,6,4,7,3};

    double sum = sumArray(array, 8);

    REQUIRE(sum == 70);
}


TEST_CASE("sumArray - test case of 5 values with negitives")
{
    double array[5] = {1,-5,2,-4,10};

    double sum = sumArray(array, 5);

    REQUIRE(sum == 4);
}


TEST_CASE("averageArray - intial test case of zeros")
{
    double array[3] = {0,0,0};

    double average = averageArray(array, 3);

    REQUIRE(average == 0);
}


TEST_CASE("averageArray - test case of 3 values")
{
    double array[3] = {1,2,3};

    double average = averageArray(array, 3);

    REQUIRE(average == 2);
}


TEST_CASE("averageArray - test case of six values")
{
    double array[6] = {1,2,3,3,2,1};

    double average = averageArray(array, 6);

    REQUIRE(average == 2);
}


TEST_CASE("averageArray - test case of 8 values")
{
    double array[8] = {10,15,5,20,6,4,7,3};

    double average = averageArray(array, 8);

    double expected = 70/8.0;

    REQUIRE(average == expected);
}


TEST_CASE("averageArray - test case of 5 values with negitives")
{
    double array[5] = {1,-5,2,-4,10};

    double average = averageArray(array, 5);

    double expected = 4/5.0;

    REQUIRE(average == expected);
}


//minLocation

TEST_CASE("maxLocation - initial test case of array with one value")
{
    double array[1] = {0};

    int max = maxLocation(array, 1);

    REQUIRE(max == 0);
}


TEST_CASE("maxLocation - testing array of increasing value")
{
    double array[4] = {1,2,3,4};

    int max = maxLocation(array, 4);

    REQUIRE(max == 3);
}


TEST_CASE("maxLocation - testing array of max not at an endpoint")
{
    double array[6] = {0,4,-2,6,4,2};

    int max = maxLocation(array, 6);

    REQUIRE(max == 3);
}


TEST_CASE("maxLocation - two max values")
{
    double array[4] = {6,5,6,3};

    int max = maxLocation(array, 4);

    REQUIRE(max == 0);
}

// value


TEST_CASE("maxValue - intial test case with one vlaue in the array")
{
    double array[1] = {0};

    double max = maxValue(array,1);

    REQUIRE(max == 0);
}


TEST_CASE("maxValue - testing array of increasing value")
{
    double array[4] = {1,2,3,4};

    double max = maxValue(array, 4);

    REQUIRE(max == 4);
}


TEST_CASE("maxValue - testing array of max not at an endpoint")
{
    double array[6] = {0,4,-2,6,4,2};

    double max = maxValue(array, 6);

    REQUIRE(max == 6);
}


TEST_CASE("maxValue - two max values")
{
    double array[4] = {6,5,6,3};

    double max = maxValue(array, 4);

    REQUIRE(max == 6);
}


// min location


TEST_CASE("minLocation - intial test case with one vlaue in the array")
{
    double array[1] = {0};

    double min = minLocation(array, 1);

    REQUIRE(min == 0); 
}


TEST_CASE("minLocation - testing array of increasing value")
{
    double array[4] = {1,2,3,4};

    int max = minLocation(array, 4);

    REQUIRE(max == 0);
}


TEST_CASE("minLocation - testing array of min not at an endpoint")
{
    double array[6] = {0,4,-2,6,4,2};

    int max = minLocation(array, 6);

    REQUIRE(max == 2);
}


TEST_CASE("minLocation - two min values")
{
    double array[4] = {6,5,6,3};

    int max = minLocation(array, 4);

    REQUIRE(max == 3);
}


TEST_CASE("minValue - initial test case, 1 value in array")
{
    double array[1] = {0};

    double min = minValue(array, 1);

    REQUIRE(min == 0);
}


TEST_CASE("minValue - testing array of increasing value")
{
    double array[4] = {1,2,3,4};

    double min = minValue(array, 4);

    REQUIRE(min == 1);
}


TEST_CASE("minValue - testing array of min not at an endpoint")
{
    double array[6] = {0,4,-2,6,4,2};

    double min = minValue(array, 6);

    REQUIRE(min == -2);
}


TEST_CASE("minValue - two min values")
{
    double array[4] = {6,5,6,3};

    double min = minValue(array, 4);

    REQUIRE(min == 3);
}


//count if


TEST_CASE("countIf - intial test case with one value in array")
{
    double array[1] = {0};

    int count = countIf(array, 1, 0);

    REQUIRE(count == 1);
}


TEST_CASE("countIf - testing array of with two values")
{
    double array[4] = {1,2,3,3};

    int count = countIf(array, 4, 3);

    REQUIRE(count == 2);
}


TEST_CASE("countIf - testing array of count not at an endpoint")
{
    double array[6] = {0,4,-2,6,4,2};

    int count = countIf(array, 6, 4);

    REQUIRE(count == 2);
}


TEST_CASE("countIf - two endpoints")
{
    double array[4] = {6,5,3,6};

    int count = countIf(array, 4, 6);

    REQUIRE(count == 2);
}


TEST_CASE("countIf - 5 things to count")
{
    double array[6] = {1,2,1,1,1,1};

    int count = countIf(array, 6, 1);

    REQUIRE(count == 5);
}


// dsc sort


TEST_CASE("mySort - intial test case for a 1 element array")
{
    double array[1] = {0};

    mySort(array, 1, "DSC");

    REQUIRE(array[0] == 0);
}


TEST_CASE("mySort - testing 2 element array")
{
    double array[2] = {2,1};

    mySort(array, 2, "DSC");

    REQUIRE(array[0] == 2);
    REQUIRE(array[1] == 1);
}


TEST_CASE("mySort - testing 5 element array DSC")
{
    double array[5] = {2,3,5,9,1};

    mySort(array, 5, "DSC");

    REQUIRE(array[0] == 9);
    REQUIRE(array[2] == 3);
    REQUIRE(array[4] == 1);
}


TEST_CASE("mySort - testing duplicate values DSC 5 elements")
{
    double array[5] = {1,3,6,6,2};

    mySort(array, 5, "DSC");

    REQUIRE(array[0] == 6);
    REQUIRE(array[1] == 6);
    REQUIRE(array[2] == 3);
    REQUIRE(array[4] == 1);
}


// ASC


TEST_CASE("mySort - testing 2 element array ASC")
{
    double array[2] = {2,1};

    mySort(array, 2, "ASC");

    REQUIRE(array[0] == 1);
    REQUIRE(array[1] == 2);
}


TEST_CASE("mySort - testing 5 element array ASC")
{
    double array[5] = {2,3,5,9,1};

    mySort(array, 5, "ASC");

    REQUIRE(array[0] == 1);
    REQUIRE(array[2] == 3);
    REQUIRE(array[4] == 9);
}


TEST_CASE("mySort - testing duplicate values ASC 5 elements")
{
    double array[5] = {1,3,6,6,2};

    mySort(array, 5, "ASC");

    REQUIRE(array[0] == 1);
    REQUIRE(array[1] == 2);
    REQUIRE(array[2] == 3);
    REQUIRE(array[4] == 6);
}


TEST_CASE("mySort - testing when invalid sort method is passed")
{
    double array[4] = {0,5,2,6};

    mySort(array, 4, "ASP");

    REQUIRE(array[0] == 0);
    REQUIRE(array[3] == 6);
}


// linear search


TEST_CASE("linearSearch - intial test case with one value in array")
{
    double array[1] = {0};

    int result = linearSearch(array, 1, 0);

    REQUIRE(result == 0);
}


TEST_CASE("linearSearch - test case with 3 values in array")
{
    double array[3] = {0, 5, 7};

    int result = linearSearch(array, 3, 5);

    REQUIRE(result == 1);
}


TEST_CASE("linearSearch - test case with 10 values in array")
{
    double array[10] = {0, 5, 7, 1, 3, 5, 6, 7, 4, 2};

    int result = linearSearch(array, 10, 6);

    REQUIRE(result == 6);
}


TEST_CASE("linearSearch - test case with missing value")
{
    double array[3] = {0, 5, 7};

    int result = linearSearch(array, 3, 2);

    REQUIRE(result == -1);
}


// binarySearch


TEST_CASE("binarySearch - intial test case with one value in array")
{
    double array[1] = {0};

    int result = binarySearch(array, 1, 0);

    REQUIRE(result == 0);
}


TEST_CASE("binarySearch - test case with 2 values in array")
{
    double array[2] = {1,2};

    int result = binarySearch(array, 2, 2);

    REQUIRE(result == 1);

    result = binarySearch(array, 2, 1);

    REQUIRE(result == 0);
}


TEST_CASE("binarySearch - testing 5 elements in array")
{
    double array[5] = {4,2,5,6,3};

    int result = binarySearch(array, 5, 4);

    REQUIRE(result == 2);   

    result = binarySearch(array, 5, 3);

    REQUIRE(result == 1);
}


TEST_CASE("binarySearch - testing 15 elements")
{
    double array[15] = {1,5,7,8,2,4,5,6,2,5,66,2,4,6,7};

    int result = binarySearch(array, 15, 5);

    REQUIRE(result == 7 );

    result = binarySearch(array, 15, 66);

    REQUIRE(result == 14);
}


TEST_CASE("binarySearch - testing non existing element")
{
    double array[4] = {1,2,3,4};

    int result = binarySearch(array, 4, 5);

    REQUIRE(result == -1);
}