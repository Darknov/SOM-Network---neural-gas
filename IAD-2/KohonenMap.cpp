#include "stdafx.h"
#include "KohonenMap.h"
#include "VectorExtender.h"

/* Ustawia niezbedne poczatkowe parametry. Po utworzeniu obiektu nalezy wywolac setInput, initializeWeights i train.*/
KohonenMap::KohonenMap(NeighMethod method, double initialPotential, double r0, double rMax, int kMax, double eta) : SOM(initialPotential, r0, rMax, kMax, eta)
{
	setLambda1(lambda1);
	setNeighMethod(method);
}

/* Ustawia funkcje sasiedztwa */
void KohonenMap::setNeighMethod(NeighMethod method)
{
	this->neighMethod = method;
}

/* Nauka dla JEDNEGO wzorca wejsciowego, "prezentacja" wzorca wejściowego */
void KohonenMap::train()
{
	// okreslenie najblizszego neuronu ma miejsce przy okazji wywolywania funkcji sasiedztwa, 
	// nie musimy wiedziec koniecznie ktory jest najblizej, tylko wywolujemy funkcje, ktorej de facto parametrem jest odleglosc miedzy wejsciem, a i-tym neuronem.

	updateWeights(); 
	//if(r>0) r -= lambda1; // to je źle
	//else r = 0;
}

/* Funkcja sasiedztwa. Jej dzialanie zalezy od wartosci pola neighMethod */
double KohonenMap::G(int i)
{

	switch (neighMethod)
	{
	case Rect:

			if (VectorExtender::getDistanceBetweenVectors(weights[i], weights[winnerIndex]) <= r) return 1;
			else return 0;

		break;
	case Gauss:

			double d = VectorExtender::getDistanceBetweenVectors(weights[i], weights[winnerIndex]);
			return exp(-(d*d) / (2 * r*r));

		break;
	}
}


/* Znajduje zwyciezce. A raczej jego index w wektorze wag.*/

int KohonenMap::getWinner()
{
	int winnerIndex;
	double winnerDistance = DBL_MAX;

	for (int i = 0; i < weights.size(); i++)
	{
		double currentDistance = VectorExtender::getDistanceBetweenVectors(weights[i], inputVector);

		if (currentDistance < winnerDistance)
		{
			winnerIndex = i;
			winnerDistance = currentDistance;
		}
	}
	return winnerIndex;
}

void KohonenMap::setLambda1(double l1)
{
	lambda1 = l1;
}