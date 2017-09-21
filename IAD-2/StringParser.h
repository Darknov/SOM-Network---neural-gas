#pragma once

#include "stdafx.h"
#include <string>

using namespace std;

static class StringParser
{
public:
	
	static string convertToString(Vector v);
	static string convertToString(SetOfVectors cluster);
	static string convertToString(SetOfClusters set);
};

