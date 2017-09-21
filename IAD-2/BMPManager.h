#pragma once
#include <iostream>
#include <fstream>
#include <array>

using namespace std;

#define HEADER_SIZE 54

class BMPManager
{
	array<char, HEADER_SIZE> header;
	string fileName;

	int width;
	int height;
	int dataOffset;


public:

	int getWidth();
	int getHeight();
	void setFile(string fileName);
	Vector readData();
	void writeData(Vector data, string fileName);
};

