#include "stdafx.h"
#include "KohonenSOM.h"
#include "Random.h"
#include "VectorExtender.h"
#include <iostream>
#include <algorithm>

void KohonenSOM::setInput(SetOfVectors input)
{
	this->input = input;
	normalizeInput();
}

Vector KohonenSOM::getOutput()
{
	return output;
}

void KohonenSOM::mixInputs()
{
	random_shuffle(input.begin(), input.end());
}

void KohonenSOM::organize()
{
	// initialization
	randomizeNeurons();

	mixInputs();

	// competition
	for (int i = 0; i < input.size(); i++)
	{
		int closestNeuronIndex = findNearestNeuronIndex(i);

		for (int j = 0; j < neurons.size(); j++)
		{
			for (int k = 0; k < NumberOfDimensions; k++)
			{
				// co-op

				//adaptation

				//// t- epoch number
				//neurons[j][k] +=
				//	getLearningRate(t) *
				//	neighbourhoodFunction(...) *
				//	(input[i][k] - neurons[j][k]);
			}
		}
		// classify i-th input data // dunno if it should be in loop
		 
	}

}

double neighourhoodFunction(int j, int winnerIndex, double distance)
{
	double sigma = 666; // funkcja
	double S = distance;
	return pow(2.72, -S*S / 2 * (sigma * sigma));
}

void KohonenSOM::randomizeNeurons()
{
	Random lotto;

	for (int i = 0; i < NumberOfNeurons; i++)
	{
		Vector randomVector;

		for (int i = 0; i < NumberOfDimensions; i++)
		{
			randomVector.push_back(lotto.nextDoubleIncludingTop(0, MaxInputElementValue));
		}

		neurons.push_back(randomVector);
	}


}

int KohonenSOM::findNearestNeuronIndex(int inputIndex)
{
	int nearestCentroidIndex = 0;
	double nearestCentroidDistance = DBL_MAX;

	for (int j = 0; j < NumberOfNeurons; j++)
	{
		double currentDistance = VectorExtender::getDistanceBetweenVectors(input[inputIndex], neurons[j]);
		if (currentDistance < nearestCentroidDistance)
		{
			nearestCentroidIndex = j;
			nearestCentroidDistance = currentDistance;
		}
	}

	return nearestCentroidIndex;
}




void KohonenSOM::setParameters(
	unsigned int NumberOfDimensions,
	unsigned int NumberOfNeurons,
	unsigned int MaxNumberOfEpochs,
	unsigned int MaxInputElementValue,
	double learningRate,
	double neighbourhoodRadius
)
{														
	this->NumberOfDimensions = NumberOfDimensions;
	this->NumberOfNeurons = NumberOfNeurons;
	this->MaxNumberOfEpochs = MaxNumberOfEpochs;
	this->MaxInputElementValue = MaxInputElementValue;
	this->learningRate = learningRate;
	this->neighbourhoodRadius = neighbourhoodRadius;
}

void KohonenSOM::normalizeInput()
{
	// i leci po SetOfVectors
	// j leci po Vector

	double sum = 0;

	for (int v = 0; v < input.size(); v++)
		for(int j=0; j<input[v].size(); j++)
			sum += (input[v][j] * input[v][j]);
		

	for(int i=0; i<input.size(); i++)
		for(int j=0; j<input[i].size(); j++)
			input[i][j] = (input[i][j]) / (sqrt(sum));
}


