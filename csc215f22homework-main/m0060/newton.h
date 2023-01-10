#pragma once
#include <cmath> // required for some of my test cases
#include <functional> // required to pass functions
#include <iostream>

using namespace std;
// you will add the function prototype for the function named
// newtonApprox here. Parameters are the starting guess, the name of
// function being evaluated, the function that computes the derivative
// of the function and an epsilon value for computing if it is close
// enough. They must be in this order


double newtonApprox(double x, function<double(double)>, function<double(double)>, double epsilon);

double f(double x);

double fP(double x);

double fm(double x);

double fmP(double x);
