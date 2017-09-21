#pragma once
#include "SOM.h"
#include "Gas.h"
#include "BMPManager.h"
class Compressor
{
public:

	void setSOM(SOM* som);

	/* Compresses file from 'source' path and saves SOM weights in 'destination' path */
	void compress(string source, string destination);
	
	/* Gets weights from 'source' path and decompresses them with SOM, then saves image it in 'destination' */
	void decompress(string source, string destination);

	vector<int> getLastWeightIndexes();

	void saveElements(string path);

	void saveWeights(string path);

	~Compressor();

private:

	vector<int> winners;

	SOM* som;

	int width;
	int height;

	BMPManager manager;

	void chunkToVector(const VectorRGB& chunk, Vector& vector);

	
};

