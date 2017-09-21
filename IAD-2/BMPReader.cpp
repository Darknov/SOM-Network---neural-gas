#include "stdafx.h"
#include "BMPManager.h"

	void BMPManager::setFile(string fileName)
	{
		this->fileName = fileName;

		ifstream stream(fileName, ios::binary);

		stream.read(header.data(), header.size());

		dataOffset = *reinterpret_cast<int *>(&header[10]);
		width = *reinterpret_cast<int *>(&header[18]);
		height = *reinterpret_cast<int *>(&header[22]);

		stream.close();

	}

Vector BMPManager::readData()
{
	ifstream stream(this->fileName, ios::binary);

	stream.read(header.data(), header.size());

	vector<char> img(dataOffset - HEADER_SIZE);
	stream.read(img.data(), img.size());

	int dataSize = ((width * 3 + 3) & (~3)) * height;

	img.resize(dataSize);
	stream.read(img.data(), img.size());

	Vector output;
	int i = 0;
	for each (auto a in img)
	{
		unsigned char unsignedA = (unsigned char)a;
		output.push_back((double)unsignedA);

	}
	stream.close();

	return output;
}

void BMPManager::writeData(Vector data, string fileName)
{
	ofstream stream(fileName, ios::binary | ios::out);

	for each (auto var in header)
	{
		stream << var;
	}

	for each (auto var in data)
	{
		stream << (char)var;
	}

	stream.close();
}

int BMPManager::getHeight()
{
	return height;
}

int BMPManager::getWidth()
{
	return width;
}