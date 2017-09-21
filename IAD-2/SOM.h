#pragma once
#include "Random.h"
#include "stdafx.h"
class SOM
{
public:

	int kMax;

	/* Wektor wejsciowy */
	Vector inputVector;

	/* Każdy bezpośredni element tego wektora (każdy wektor w nim zawarty) to wektor wag neuronu. Indeksy tego wektora to odpowiadające numery neuronów. */
	SetOfVectors weights;

	/* Szybkość uczenia */
	double eta;

	/* Promien sasiedztwa */
	double r, r0, rMin;

	/* Wartosc potencjalu czynnosciowego dla kazdego neuronu */
	Vector potentials;

	/* Startowa wartosc potencjalu czynnosciowego */
	double initialPotential;

	/* Minimalny potencjal czynnosciowy */
	double minimalPotential;

	/* Index neuronu, ktory 'wygral' podczas ostatniej prezentacji wektora wejsciowego */
	int winnerIndex;

public:

	/* Ustawia niezbedne poczatkowe parametry. Po utworzeniu obiektu nalezy wywolac setInput, initializeWeights i train.*/
	SOM(double initialPotential, double r0, double rMax, int kMax, double eta);

	/* Ustaw wektor wejsciowy */
	virtual void setInput(Vector inputVector);

	/* Zainicjuj wagi wartosciami z przedzialu [min; max] */
	virtual void initializeWeights(int howMuchWeights, double min, double max);

	virtual void initializeWeights(int howMuchWeights, int min, int max);

	/* Zwraca aktualne wagi */
	virtual SetOfVectors getWeights();

	/* Ustaw  promien sasiedztwa */
	virtual void setRMin(double r);
	virtual void setR0(double r);

	/* Ustaw szybkosc uczenia */
	virtual void setEta(double eta);

	void setKMax(int kmax);

	/*  Train znaczy tutaj "trenuj", nie "pociąg" :).Tu prawdopodobnie bedzie tez implementacja w tej klasie, ale teraz nie mam na to czasu. */
	virtual void train()=0;

	/* Znajduje zwyciezce. Implementacja jest w klasach pochodnych, bo tak będzie troszeczke szybciej to dzialac.*/
	virtual int getWinner()=0;

	virtual int getPriorityOfNeuron(int i) = 0;

	
public:

	/* Normalizuje wartosci wektora wejsciowego. Ta metoda jest wywolywana zawsze po ustawieniu wektora wejsciowego (jest wywolana w setterze). */
	virtual void normalizeInput();



	/* Aktualizuje wagi */
	virtual void updateWeights();

	/* Funkcja sasiedztwa, zalezy od rodzaju SOMy */
	virtual double G(int i)=0;

};

