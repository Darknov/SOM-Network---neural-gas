// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <vector>

#define USE_NORMALIZATION false
#define NUMBER_OF_REPETITIONS 7

using namespace std;

struct RGB
{
	double r;
	double b;
	double g;
};

typedef vector<double> Vector;
typedef vector<Vector> SetOfVectors;
typedef vector<SetOfVectors> SetOfClusters;
typedef vector<RGB> VectorRGB;
typedef vector<VectorRGB> SetOfChunks;