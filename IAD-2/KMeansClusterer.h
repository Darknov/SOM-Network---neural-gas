#pragma once
#include "stdafx.h"
#include <iostream>
#include "Random.h"

using namespace std;

class KMeansClusterer
{
private:
	// main parameters
	SetOfVectors input;
	SetOfClusters clusters;

	/* Wektory kodowe r */
	SetOfVectors centroids;

	int VectorDimension			= 2   ;	
	int MaxInputElementValue	= 1	  ;
	int NumberOfCentroids		= 2	  ; //k
	int NumberOfIterations		= 100 ;

	double e = 0.01;

public:
	KMeansClusterer();
	KMeansClusterer(SetOfVectors& input);
	void setInput(SetOfVectors& input);
	SetOfClusters getOutput();
	SetOfVectors getCentroids();
	void clusterInput();
	void setParameters
	(
		int VectorDimension,
		int MaxInputElementValue,
		int NumberOfCentroids,
		int NumberOfIterations
	);

	void setK(int k) { NumberOfCentroids = k; }
	/*
		Ustaw maksymalny blad kwantyzacji
	*/
	void setE(double e);

private:

	Vector getMeanVectorOfCluster(SetOfVectors cluster);
	void recomputeCentroidsPositions();
	void validateInput();
	void calculateRandomCentroids();
	void assignInputPointsToClusters();
	void performExactClustering();
	void clearClusters();
	int findNearestCentroidIndex(int inputIndex);


};
