#include "stdafx.h"
#include "KMeansClusterer.h"
#include "VectorExtender.h"


KMeansClusterer::KMeansClusterer(SetOfVectors& input)
{
	setInput(input);
}

KMeansClusterer::KMeansClusterer()
{
}

void KMeansClusterer::clusterInput()
{
	validateInput();
	calculateRandomCentroids();
	performExactClustering();
}

void KMeansClusterer::recomputeCentroidsPositions()
{
	for (int j = 0; j < NumberOfCentroids; j++)
	{
		if (clusters[j].size() != 0)
			centroids[j] = getMeanVectorOfCluster(clusters[j]);

	}
}

void KMeansClusterer::performExactClustering()
{
	int m = 0;
	bool canStop = false;

	double currentDm = DBL_MAX;

	while (!canStop) 
	{
		clearClusters();
		
		/* Przypisz punkty podane na wejściu do klastrow */

		for (int i = 0; i < input.size(); i++)
		{
			// znajdz najblizszy centroid
			int index = findNearestCentroidIndex(i);

			// przypisz wejscie do centroidu
			clusters[index].push_back(input[i]);
		}

		recomputeCentroidsPositions();

		double prevDm = currentDm;

		/* Obliczenie sredniego bledu kwantyzacji w m-tej iteracji */

		double sum = 0;

		// r to centroid, do którego został przypisany aktualny input.

		for (int i = 0; i < clusters.size(); i++)
		{
			Vector r = centroids[i];

			for (int j = 0; j < clusters[i].size(); j++)
			{
				sum += VectorExtender::getDistanceBetweenVectors(clusters[i][j], r);
			}

		}

		currentDm = (1 / (double) input.size()) * sum;


		canStop = ((prevDm - currentDm) / currentDm) < e;
		m++;
	}
}

void KMeansClusterer::assignInputPointsToClusters()
{

}

void KMeansClusterer::clearClusters()
{

	//for (auto x : clusters)
	//{
	//	x.clear();
	//}

	for (int i = 0; i<clusters.size(); i++)
	{
		clusters[i].clear();
	}

}

int KMeansClusterer::findNearestCentroidIndex(int inputIndex)
{
	int nearestCentroidIndex = 0;
	double nearestCentroidDistance = DBL_MAX;

	for (int j = 0; j < NumberOfCentroids; j++)
	{
		double currentDistance = VectorExtender::getDistanceBetweenVectors(input[inputIndex], centroids[j]);
		if (currentDistance < nearestCentroidDistance)
		{
			nearestCentroidIndex = j;
			nearestCentroidDistance = currentDistance;
		}
	}

	return nearestCentroidIndex;
}

void KMeansClusterer::calculateRandomCentroids()
{
	Random lotto;

	//// calculate random centroids (tested) 

	Vector emptyVector;

	for (int g = 0; g<NumberOfCentroids; g++)
	{
		centroids.push_back(emptyVector);
		for (int i = 0; i < VectorDimension; i++)
		{
			centroids[g].push_back(lotto.nextDoubleIncludingTop(0, MaxInputElementValue));
		}

		SetOfVectors initialGthCentroidCluster;
		initialGthCentroidCluster.push_back(centroids[g]);
		clusters.push_back(initialGthCentroidCluster);
	}
}

void KMeansClusterer::validateInput()
{
	// check if input is set

	if (input.size() == 0) cerr << "KMeansClusterer input is not set" << endl;

	// check input dimensions

	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < VectorDimension; j++)
		{
			if (input[i][j] > MaxInputElementValue)
			{
				cerr << "one of input values are too big" << endl;
			}
		}

	}
}

Vector KMeansClusterer::getMeanVectorOfCluster(SetOfVectors cluster)
{
	// initializing output
	Vector output;

	for (int i = 0; i < VectorDimension; i++)
		output.push_back(0);

	// calculating mean

	for (int w = 0; w < VectorDimension; w++)
	{
		double sum = 0;
		for (unsigned int i = 0; i < cluster.size(); i++)
		{
			sum += cluster[i][w];
		}
		output[w] = sum / ((double)cluster.size());

		if (output[w] > 1)
		{
			cout << "Something went wrong in getMeanVectorOfCluster!" << endl;
		}

	}

	return output;
}

void KMeansClusterer::setInput(SetOfVectors& input)
{
	this->input = input;
}

SetOfClusters KMeansClusterer::getOutput()
{
	return clusters;
}

SetOfVectors KMeansClusterer::getCentroids()
{
	return centroids;
}

void KMeansClusterer::setParameters
(
	int VectorDimension,
	int MaxInputElementValue,
	int NumberOfCentroids,
	int NumberOfIterations
)
{
	this->VectorDimension = VectorDimension;
	this->MaxInputElementValue = MaxInputElementValue;
	this->NumberOfCentroids = NumberOfCentroids;
	this->NumberOfIterations = NumberOfIterations;
}

void KMeansClusterer::setE(double e)
{
	this->e = e;
}
