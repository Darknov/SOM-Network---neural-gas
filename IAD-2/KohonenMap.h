#pragma once
#include "SOM.h"

enum NeighMethod
{
	Rect = 0,
	Gauss = 1
};

class KohonenMap : public SOM
{
private:

	/* Krok zmniejszania promienia sasiedztwa r*/
	double lambda1;

	NeighMethod neighMethod;

public:

	KohonenMap::KohonenMap(NeighMethod method, double initialPotential, double r0, double rMax, int kMax, double eta);

	/* Ustawia, jaką metodę sąsiedztwa będzie wykorzystywała siec */
	void setNeighMethod(NeighMethod method);

	void train();

	double G(int i);

	int getWinner();

	void setLambda1(double l1);

};

