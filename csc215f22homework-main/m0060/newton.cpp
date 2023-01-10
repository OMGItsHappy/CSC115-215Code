#include "newton.h"



double newtonApprox(double x, function<double(double)> f, function<double(double)> dx, double epsilon)
{
	if (fabs(f(x)) < epsilon) return x;

	x -= f(x) / dx(x);

	return newtonApprox(x, f, dx, epsilon);
}	