/** ***************************************************************************
* @file
******************************************************************************/

#pragma once

#include <cmath>
#include <string>

using namespace std;

/**`
* @brief The number of terms in the taylor series to approx. sine/cosine/tangent
*/
const int TERMS=10;

/**
* @brief The math constant pi
*/
const double PI = atan(1.0) * 4;

/**
* @brief The error value acceptable for estimating sqrt, cbrt, and logarithms
*/
const double ERRORVALUE = .000000000001;

/**
* @brief The maximum number of times to loop for Newton's Method
*/
const int ITERATIONMAX = 5000;

/**
* @brief The error tolerance for sine/cosine/tangent
*/
const double ERRORTOLERANCE = .000001;

double mySqrt(double x);

double myCbrt(double x);

double myLog(double x, int base);

double mySin(double x);

double factorial(double x);

double mySinD(double x);

double myCos(double x);

double myCosD(double x);

double myTan(double x);

double myTanD(double x);

void copyArray(double * dest, double * source, int size);

void initialArray(double array[], int size, double val);

double sumArray(double array[], int size); 

double averageArray(double array[], int size);

int maxLocation(double array[], int size);

double maxValue(double array[], int size);

int minLocation(double array[], int size);

double minValue(double array[], int size);

int countIf(double array[], int size, double toCount);

void mySort(double array[], int size, string method);

int linearSearch(double array[], int size, double toFind);

int binarySearch(double array[], int size, double toFind);