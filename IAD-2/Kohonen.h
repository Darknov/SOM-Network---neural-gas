//#pragma once
//class Kohonen
//{
//public:
//
//	//enum NeighMethod
//	//{
//	//	GNF = 0,
//	//	inne = 1
//	//};
//
//private:
//
//	SetOfVectors inputVectors;
//	Vector inputVector;
//	int size = 5;
//
//	/* Każdy bezpośredni element tego wektora (każdy wektor w nim zawarty) to wektor wag neuronu. Indeksy tego wektora to odpowiadające numery neuronów. */
//	SetOfVectors weights;
//	
//	/* Szybkość uczenia */
//	double eta; 
//	double maxEta;
//
//	/* Promien sasiedztwa */
//	double maxLambda;
//	double lambda;
//
//public:
//
//	Kohonen(SetOfVectors inputVectors, double maxLambda, double maxEta);
//
//	/* Ustawia ile jest neuronów */
//	void setSize(int size);
//
//	/* Zwraca aktualne wagi sieci. */
//	SetOfVectors getWeights();
//
//	/* Pozwala ustawić wagi.*/
//	void setWeights(SetOfVectors weights);
//
//	/* Ustaw początkową szybkość uczenia neuronów (póki co w trakcie działania programu ona się nie zmienia, a nie wiem teraz nawet czy ma się zmieniać.*/
//	void setEta(double eta);
//
//	/* Gwóźdź programu, tutaj wszystko się dzieje. */
//	void work();
//
//private:
//
//	/* Normalizuje wektor wejściowy (jego długość będzie równa 1). Metoda jest troche niedokladna, ale nie ma czasu, zeby nad tym teraz siedziec.*/
//	void normalizeInputVector();
//
//	/* Ustawia losowe wartości początkowe dla wag. */
//	void initializeWeights();
//
//	/* Ustawia wektor wejściowy sieci i normalizuje go. */
//	void setInputVector(Vector input);
//
//	/* Zwraca wyjście neuronu o podanym numerze */
//	double getNeuronOutput(int vectorIndex);
//
//	/* Podaje wejście neuronom. */
//	void feedNeurons();
//
//	/* Funkcja sąsiedztwa Gaussa */
//	double gnf(int max, int m, double lambda);
//
//	/* Wykonanie odpowiedniej funkcji sąsiedztwa */
//	double neigh(NeighMethod method, int max, int m, double lambda);
//
//
//
//};
//
