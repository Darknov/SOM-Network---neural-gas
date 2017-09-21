#pragma once
class KohonenSOM
{

private:

	SetOfVectors input; // contains vectors which will be classified
	Vector output; // it has to be the same size what input. Every i-th element is class of i-th element in input.
		
	SetOfVectors neurons;
	SetOfClusters clusters;

	unsigned int NumberOfDimensions = 2;
	unsigned int NumberOfNeurons = 2;
	unsigned int MaxNumberOfEpochs = 100; // max times when network will look into a parameter to classify it 
	int MaxInputElementValue = 1;
	double learningRate = 0.01; // how much displacement between two epochs
	double neighbourhoodRadius = 0.1; // delta

public:

	void setInput(SetOfVectors input);
	Vector getOutput();
	void organize();
	void setParameters
	(
		unsigned int NumberOfDimensions,
		unsigned int NumberOfNeurons,
		unsigned int MaxNumberOfEpochs,
		unsigned int MaxInputElementValue,
		double learningRate,
		double neighbourhoodRadius
	);

private:

	void randomizeNeurons();
	int findNearestNeuronIndex(int inputIndex);
	Vector neighbourhoodFunction(double u, double v, double s);
	Vector alpha(int i);
	void mixInputs();
	void normalizeInput();
};

