#pragma once
#include "IClusterDisplayer.h"
class ConsoleSetOfClustersDisplayer :
	public ISetOfClustersDisplayer
{
public:
	
	void displayClusters(SetOfClusters);	
	void displayVector(Vector v);
	void displayCluster(SetOfVectors cluster);
	void displaySetOfClusters(SetOfClusters);
};

