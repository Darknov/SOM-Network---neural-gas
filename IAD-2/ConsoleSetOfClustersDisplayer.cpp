#include "stdafx.h"
#include "ConsoleSetOfClustersDisplayer.h"

#include <iostream>

void ConsoleSetOfClustersDisplayer::displayClusters(SetOfClusters set)
{
	displaySetOfClusters(set);
}

void ConsoleSetOfClustersDisplayer::displayVector(Vector v)
{
	cout << " [ ";

	for (double x : v)
	{
		cout << x << " ";
	}

	cout << "] ";
}

void ConsoleSetOfClustersDisplayer::displayCluster(SetOfVectors cluster)
{
	for (Vector v : cluster)
	{
		displayVector(v);
		cout << " ";
	}
}

void ConsoleSetOfClustersDisplayer::displaySetOfClusters(SetOfClusters set)
{
	int count = 0;
	for (SetOfVectors vectors : set)
	{
		cout << count;
		displayCluster(vectors);
		cout << endl;

		count++;
	}
}