#include "stdafx.h"
#include "Compressor.h"
#include "Gas.h"
#include "VectorExtender.h"
#include <algorithm>

void Compressor::setSOM(SOM* som)
{
	this->som = som;
}

Compressor::~Compressor()
{
	delete som;
}

void Compressor::compress(string source, string destination)
{
	// get pixels

	manager.setFile(source);

	Vector primalData = manager.readData();

	// dotąd jest ok na 100%

	VectorRGB data;

	for (int i = 0; i < primalData.size(); i += 3)
	{
		RGB pixelColor;

		double blue = primalData[i];
		double green = primalData[i + 1];
		double red = primalData[i + 2];

		if (red < 0)
		{red = 256 + red;}
		if (green < 0)
		{green = 256 + green;}
		if (blue < 0)
		{blue = 256 + blue;}

		pixelColor.b = blue;
		pixelColor.r = red;
		pixelColor.g = green;

		data.push_back(pixelColor);
	}

	// Divide pixels into chunks

	SetOfChunks chunks;

	width = manager.getWidth();
	height = manager.getHeight();

	chunks.resize(width*height / 16);

	int numberOfChunksHorizontal = width / 4;

	for (int i = 0; i < data.size(); i++)
	{
		int x = i % width;
		int y = i / width;

		int chX = x / 4;
		int chY = y / 4;

		int chNumber = numberOfChunksHorizontal*chY + chX;

		chunks[chNumber].push_back(data[i]);
	}

	// dotąd jest bardzo dobrze


	// Passing chunks to the net

	Vector input;
	chunkToVector(chunks[0], input); // output by reference

	int numberOfIterations = 100;

	som->setInput(input);
	if(!USE_NORMALIZATION) som->initializeWeights(50, 0, 255);
	else som->initializeWeights(50, 0.0, 1.0);

	for (int l = 0; l < numberOfIterations; l++)
	{
		cout << l << endl;
		for (int i = 0; i < chunks.size(); i++)
		{
			//exp(-result);
			chunkToVector(chunks[i], input);
			som->setInput(input);
			som->train();
			som->r = som->r0*pow((som->rMin / som->r0), (l / numberOfIterations));
		}
	}
	SetOfVectors weights = som->getWeights();
	int winner = 0;
	Vector chunk;
	for (int i = 0; i < chunks.size(); i++)
	{
		for (int j = 0; j < weights.size(); j++)
		{
			chunkToVector(chunks[i], chunk);
			if (VectorExtender::getDistanceBetweenVectors(weights[j], chunk) < VectorExtender::getDistanceBetweenVectors(weights[winner], chunk))
			{
				winner = j;
			}
		}
		winners.push_back(winner);
	}

}

void Compressor::saveElements(string path)
{
	ofstream file;
	file.open(path + ".dane", std::ios::app);
	vector<vector<double>> weights = som->weights;

	for (int i = 0; i < winners.size(); i++)
	{
		file << winners[i] << " ";
		if (i % 11 == 10)
			file << "\n";
	}
	file.close();
}

void Compressor::saveWeights(string path)
{
	ofstream file;
	file.open(path + ".dane", std::ios::app);
	vector<vector<double>> weights = som->weights;

	for (int i = 0; i < weights.size(); i++)
	{
		for (int j = 0; j < weights[i].size(); j++)
		{
			file << weights[i][j] << " ";
		}
		file << "\n";
	}
	file.close();
}

void Compressor::chunkToVector(const VectorRGB& chunk, Vector& vector)
{
	vector.clear();
	for each (RGB pixel in chunk)
	{
		vector.push_back(pixel.b);
		vector.push_back(pixel.g);
		vector.push_back(pixel.r);
	}


}


void Compressor::decompress(string source, string destination)
{
	// load indexes from 'source' or just use prev. Not now.
	// width and height will be first two ints?

	Vector imageOutput(width*height * 3);

	SetOfVectors weights = som->getWeights();

	vector<double> pixeles;

	vector<int> usedIndexedDEBUG;
	Vector out;
	

	vector<vector<double>> chunkys1;
	vector<vector<double>> chunkys;

	for (int i = 0; i < width*height / 16; i++)
	{
		chunkys1.push_back(weights[winners[i]]);
	}

	for (int i = 0; i < width*height / 16; i++)
	{
		cout << winners[i] << endl;

		//chunkys1.push_back(weights[i%2]);
	}

	for (int i = 0; i < height / 4; i++)
	{
		for (int l = 0; l < 4; l++)
		{
			for (int j = 0; j < width / 4; j++)
			{

				for (int h = 0; h < 12; h++)
				{

					imageOutput[i*width * 3 * 4 + l*width * 3 + j * 12 + h] = chunkys1[i*(width/4) + j][l*12 + h];
				}
			}
			cout << endl;
		}
	}


	usedIndexedDEBUG;
	saveElements("elements20");
	saveWeights("weights20");
	manager.writeData(imageOutput, destination);
}

vector<int> Compressor::getLastWeightIndexes()
{
	return winners;
}
