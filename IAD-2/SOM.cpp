#include "stdafx.h"
#include "SOM.h"
#include "Gas.h"
#include "VectorExtender.h"
#include <algorithm>
#include <iostream>
SOM::SOM(double initialPotential, double r0, double rMin, int kMax, double eta)
{
	setR0(r0);
	setRMin(rMin);
	setEta(eta);
	setKMax(kMax);
	this->r = r0;
	this->initialPotential = initialPotential;
}

void SOM::setInput(Vector inputVector)
{
	this->inputVector = inputVector;
	//if(USE_NORMALIZATION) normalizeInput();
}

void SOM::initializeWeights(int howMuchWeights, double min, double max)
{
	Random lotto;

	for (int z = 0; z < howMuchWeights; z++)
	{
		Vector randomVector;

		for (int j = 0; j < inputVector.size(); j++)
		{
			randomVector.push_back(lotto.nextDoubleIncludingTop(min, max));
		}

		weights.push_back(randomVector);
		potentials.push_back(initialPotential);
	}


}

void SOM::initializeWeights(int howMuchWeights, int min, int max)
{
	Random lotto;

	for (int z = 0; z < howMuchWeights; z++)
	{
		Vector randomVector;

		for (int j = 0; j < inputVector.size(); j++)
		{
			randomVector.push_back(lotto.nextIntIncludingTop(min, max)); // int
		}

		weights.push_back(randomVector);
		potentials.push_back(initialPotential);

	}
}

SetOfVectors SOM::getWeights()
{
	return weights;
}

void SOM::setR0(double r0)
{
	this->r0 = r0;

}

void SOM::setRMin(double rMin)
{
	this->rMin = rMin;
}

void SOM::setEta(double eta)
{
	this->eta = eta;
}

void SOM::normalizeInput()
{
	for (int i = 0; i < inputVector.size(); i++)
	{
		double sum = 0;

		for (int j = 0; j < inputVector.size(); j++)
		{
			sum += inputVector[j] * inputVector[j];
		}

		inputVector[i] = inputVector[i] / (sqrt(sum));

		if (sum == 0) inputVector[i] = 0;
	}
}

void SOM::setKMax(int kmax)
{
	this->kMax = kmax;
}

void SOM::updateWeights()
{
	// szukanie zwycięzcy

	winnerIndex = getWinner();

	// aktualizowanie wag w sasiedztwie

	//for (int k = 0; k < kMax; k++)
	//{
	//	for (int i = 0; i < weights.size(); i++)
	//	{
	//		double g = G(i);
	//		if (potentials[i] < minimalPotential) continue;

	//		for (int j = 0; j < weights[i].size(); j++)
	//		{
	//			weights[i][j] += eta *g*(inputVector[j] - weights[i][j]);
	//		}

	//	}

	//	r = r0*pow((rMin/r0), (k / kMax));

	//}


	for (int k = 0; k < kMax; k++)
	{

		for (int i = 0; i < weights.size(); i++)
		{

			double g = G(i);
			if (potentials[i] < minimalPotential) continue;
			if (winnerIndex == i)
			{
				for (int j = 0; j < weights[i].size(); j++)
				{

					weights[winnerIndex][j] += eta *(inputVector[j] - weights[winnerIndex][j]);
				}
			}
			else {
					for (int j = 0; j < weights[i].size(); j++)
					{

						weights[i][j] += eta*g*(inputVector[j] - weights[i][j]) * 0.1;
					}
			}


		}
	}

	 //aktualizacja potencjalow czynnosciowych

	for (int i = 0; i < potentials.size(); i++)
	{

		if (i == winnerIndex)
		{
			potentials[i] -= minimalPotential;
		}
		else 
			potentials[i] += 1.0/potentials.size();
		if (potentials[i] > 1) 
			potentials[i] = 1;
	}
}