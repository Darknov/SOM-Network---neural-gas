#pragma once
#include "SOM.h"
#include "VectorExtender.h"
#include <iostream>
#include <algorithm>

class Gas : public SOM
{
private:

	struct Comparator
	{
		Gas* gas;
		Vector iV;

		Comparator( Gas* gas)
		{
			this->iV = gas->inputVector;
			this->gas = gas;
			
		}

		bool operator()(int aIndex, int bIndex)
		{
			Vector a = gas->weights[aIndex];
			Vector b = gas->weights[bIndex];
		
			double aDistance = VectorExtender::getDistanceBetweenVectors(a, iV);

			double bDistance = VectorExtender::getDistanceBetweenVectors(b, iV);

			
			//return aDistance < bDistance;
			return exp(-aDistance) < exp(-bDistance); // do zadania
		}
	};

	std::vector<int> sortedWeightsIndexes;

public:
	
	Gas(double initialPotential, double r0, double rMax, int kMax, double eta);

	void train();

	int getWinner();

	int getPriorityOfNeuron(int i);

private:

	double G(int i);

	




};

