
#include "stdafx.h"
#include <iostream>
#include "Gas.h"


Gas::Gas(double initialPotential, double r0, double rMin, int kMax, double eta) : SOM(initialPotential, r0, rMin, kMax, eta) 
{
	this->minimalPotential = this->initialPotential/4.0;

}

void Gas::train()
{


		for (int i = 0; i<weights.size(); i++)
			sortedWeightsIndexes.push_back(i);

		// posortuj wg. odleglosci od najblizszego. Zapisz w wektorze posortowane indeksy neuronow.
		
		std::sort(sortedWeightsIndexes.begin(), sortedWeightsIndexes.end(), Comparator(this));




		updateWeights();
		sortedWeightsIndexes.clear();



	
}

double Gas::G(int i)
{
	// zamien indeks i z wektora weights na indeks mi z wektora sortedWeights
	int mi = sortedWeightsIndexes[i];

	return exp(-mi / r);
}

int Gas::getWinner()
{
	for (int i = 0; i < sortedWeightsIndexes.size(); i++)
	{
		if (potentials[sortedWeightsIndexes[i]] > minimalPotential)
		{
			return sortedWeightsIndexes[i];
		}
	}
	return sortedWeightsIndexes[0];
}

int Gas::getPriorityOfNeuron(int i)
{
	for (int j = 0; j < sortedWeightsIndexes.size(); j++)
	{
		if (sortedWeightsIndexes[j] == i)
			return j;
	}

	return 0;
}


