#include "stdafx.h"
#include "VectorExtender.h"
#include <iostream>

double VectorExtender::getDistanceBetweenVectors(Vector a, Vector b)
{
	if (a.size() != b.size())
	{
		cerr << "Vectors sizes are not the same (calculateDistanceBetweenVectors)" << endl;
	}

	double thisShouldBeUnderSqrt = 0;

	for (unsigned int i = 0; i < a.size(); i++)
	{
		double diffSquared = (a[i] - b[i])*(a[i] - b[i]);
		thisShouldBeUnderSqrt += diffSquared;
	}

	double result = sqrt(thisShouldBeUnderSqrt);

	return result;

}
