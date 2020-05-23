#pragma once
#include "Utils.h"
#include <ctime>

class Matrix
{
public:
	int** matrix = nullptr;
	int M, N;
	void GetMatrixFromFile(std::string FilePath);
	void DebugOutpurMatrix();
	void GetRandomMatrix(int,int);
	void WriteToFile(std::string);
};