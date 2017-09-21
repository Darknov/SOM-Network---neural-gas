#include "stdafx.h"
#include "StringParser.h"

string StringParser::convertToString(Vector v)
{
	string output = "";

	output += " [ ";

	for (double x : v)
	{
		output += to_string(x);
		output += " ";
	}

	output += "] ";

	return output;
}

string StringParser::convertToString(SetOfVectors cluster)
{
	string out = "";
	for (Vector v : cluster)
	{
		out += StringParser::convertToString(v);
		out += " ";
	}

	return out;
}

string StringParser::convertToString(SetOfClusters set)
{
	string out = "";
	int count = 0;
	for (SetOfVectors vectors : set)
	{
		out += to_string(count); 
		out += convertToString(vectors);
		out += "\n";

		count++;
	}

	return out;
}