// IAD-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

#include "Random.h"
#include "ConsoleSetOfClustersDisplayer.h"
#include "KMeansClusterer.h"
#include "KohonenMap.h"
#include "Gas.h"
#include "BMPManager.h"
#include "Compressor.h"


using namespace::std;

ConsoleSetOfClustersDisplayer* displayer = new ConsoleSetOfClustersDisplayer();


int main()
{
	double iP = 0.75;
	double r0 = 5;
	double rMin = 0.1;
	int kMax = 1;
	double eta = 0.95;

	for (int k = 0; k < 1; k++)
	{

		string name = "data\\graphics\\output\\Large20" + std::to_string(k);


		SOM* gas = new Gas(iP, r0, rMin, kMax, eta);
		Compressor comp;
		comp.setSOM(gas);
		comp.compress("data\\graphics\\input\\Large53.bmp", "");
		comp.decompress("",  name + ".bmp");
	}

	

	cout << "KONIEC!!!" << endl;

	cin.ignore();
	cin.get();
	
    return 0;
}
