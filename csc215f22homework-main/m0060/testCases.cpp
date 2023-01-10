#include "newton.h"
#include "..\catch.hpp"
// add in the test case provided below.
// write a least 4 other test case in addition to the one provided.

double f(double x)
{
	return pow(x, 3) + 2;
}
double fP(double x)
{
	return 3 * pow(x, 2);
}

double fm(double x)
{
	return 5*pow(x, 3/2) + 2;
}

double fmP(double x)
{
	return 5*(3/2) * pow(x, 1/2);
}

TEST_CASE("newtonApprox - x^3 + 2")
{
	double epsilon = .001;
	double n = 2;
	double ans;
	ans = newtonApprox(n, f, fP, epsilon); // note, you pass the name of your functions
	REQUIRE(fabs(f(ans)) <= epsilon);
}

TEST_CASE("newtonApprox - 5x^(3/2)+2")
{
	double epsilon = .001;
	double n = 2;
	double ans;
	ans = newtonApprox(n, fm, fmP, epsilon);
	REQUIRE(fabs(fm(ans)) <= epsilon);
}

TEST_CASE("newtonApprox - testing intial n value = 0, 5x^(3/2)+2")
{
	double epsilon = .001;
	double n = 0;
	double ans;
	ans = newtonApprox(n, fm, fmP, epsilon);
	REQUIRE(fabs(fm(ans)) <= epsilon);
}

TEST_CASE("newtonApprox - testing intial n value = 10000000000, 5x^(3/2)+2")
{
	double epsilon = .001;
	double n = 10000000000;
	double ans;
	ans = newtonApprox(n, fm, fmP, epsilon);
	REQUIRE(fabs(fm(ans)) <= epsilon);
}

TEST_CASE("newtonApprox - testing intial n value = -10000000000, 5x^(3/2)+2")
{
	{
		double epsilon = .001;
		double n = -10000000000;
		double ans;
		ans = newtonApprox(n, fm, fmP, epsilon);
		REQUIRE(fabs(fm(ans)) <= epsilon);
	}
}