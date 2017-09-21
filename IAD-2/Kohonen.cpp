//#include "stdafx.h"
//#include "Kohonen.h"
//#include "Random.h"
//#include "VectorExtender.h"
//
//Kohonen::Kohonen(SetOfVectors inputVectors, double maxLambda, double maxEta)
//{
//	this->inputVectors = inputVectors;
//	this->maxLambda = maxLambda;
//	this->lambda = maxLambda;
//	this->maxEta = maxEta;
//	this->eta = maxEta;
//}
//
//void Kohonen::work()
//{
//	setInputVector(inputVectors[0]);
//	normalizeInputVector();
//	initializeWeights();
//	feedNeurons();
//
//	for (int i = 1; i < inputVectors.size(); i++)
//	{
//		setInputVector(inputVectors[i]);
//		normalizeInputVector();
//		feedNeurons();
//	}
//}
//
//void Kohonen::setInputVector(Vector input)
//{
//	this->inputVector = input;
//}
//
//void Kohonen::normalizeInputVector()
//{
//	for (int i = 0; i < inputVector.size(); i++)
//	{
//		double sum = 0;
//
//		for (int v = 0; v < inputVector.size(); v++)
//		{
//			sum += (inputVector[v] * inputVector[v]);
//		}
//
//		inputVector[i] /= sqrt(sum);
//	}
//}
//
//SetOfVectors Kohonen::getWeights()
//{
//	return weights;
//}
//
//void Kohonen::initializeWeights()
//{
//	Random lotto;
//
//	for (int z = 0; z < size; z++)
//	{
//			Vector randomVector;
//
//			for (int j = 0; j < inputVector.size(); j++)
//			{
//				randomVector.push_back(lotto.nextDoubleIncludingTop(0, 1));
//			}
//
//			weights.push_back(randomVector);
//	}
//}
//
//void Kohonen::setSize(int size)
//{
//	this->size = size;
//}
//
//void Kohonen::setWeights(SetOfVectors weights)
//{
//	this->weights = weights;
//}
//
//void Kohonen::feedNeurons()
//{
//	// Znajdź współrzędne neuronu o największym sygnale na wyjściu.
//
//	int maxOutputIndex = 0;
//
//	double maxOutput = getNeuronOutput(0);
//
//	// i - indeks wektora
//	// j - indeks elementu
//
//	for (int i = 0; i<weights.size(); i++)
//	{
//			double current = getNeuronOutput(i);
//			if (current > maxOutput)
//			{
//				maxOutput = current;
//				maxOutputIndex = i;
//			}
//	}
//
//	// teraz uczymy neuron, który wygrał i jego sąsiadów, tj. poprawiamy im wagi.
//
//	for (int m = 0; m < weights.size(); m++)
//	{
//			for (int i = 0; i < inputVector.size(); i++)
//			{
//				weights[m][i] = weights[m][i] + eta*inputVector[i] * neigh(GNF, maxOutputIndex, m, this->lambda)*(inputVector[i]-weights[m][i]);
//			}
//	}
//}
//
//double Kohonen::neigh(NeighMethod method, int max, int m, double lambda)
//{
//	if (method == GNF)
//	{
//		return gnf(max, m, lambda);
//	}
//}
//
//double Kohonen::gnf(int max, int m, double lambda)
//{
//	double d = VectorExtender::getDistanceBetweenVectors(weights[max], weights[m]);
//	return exp(-(d*d) / (2 * (lambda*lambda)));
//}
//
//double Kohonen::getNeuronOutput(int vectorIndex)
//{
//	Vector neuronWeights = this->weights[vectorIndex]; // neuronNumber to to samo co m
//	
//	double output = 0;
//
//	for (int i = 0; i < neuronWeights.size(); i++) 
//	{
//		output += neuronWeights[i] * inputVector[i];
//	}
//	
//	return output;
//
//}
//
//void Kohonen::setEta(double eta)
//{
//	this->eta = eta;
//}
