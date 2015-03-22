// RootFinder.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "RootFinder.h"
#include <math.h>
#include <stdexcept>

// This is an example of an exported variable
ROOTFINDER_API int nRootFinder=0;

// This is an example of an exported function.
ROOTFINDER_API int fnRootFinder(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see RootFinder.h for the class definition
CRootFinder::CRootFinder()
{
	return;
}

double CRootFinder::SquareRoot(double v)
{
	double result = v;
	double diff = v;
	while (diff > result / 1000)
	{
		double oldResult = result;
		// old code:
		//   result = result - (result*result - v)/(2*result);
		// new code:
		result = (result + v / result) / 2.0;
		diff = abs(oldResult - result);
	}
	
	
	if (v < 0.0)
	{
		throw std::out_of_range("Can't do square roots of negatives");
	}
return result;
}
