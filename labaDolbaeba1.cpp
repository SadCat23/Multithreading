﻿#include "Matrix.h"

Matrix* Multiply(Matrix, Matrix);

int main()
{
	Matrix firstMatrix, secondMatrix;

	Matrix* resultMatrix;
	



	firstMatrix.GetRandomMatrix(800, 800);
	secondMatrix.GetRandomMatrix(800, 800);

	//firstMatrix.GetMatrixFromFile("D:\\1.txt");
	//secondMatrix.GetMatrixFromFile("D:\\2.txt");
	
	if (resultMatrix = Multiply(firstMatrix, secondMatrix))
	{
		//resultMatrix->DebugOutpurMatrix(); 
		resultMatrix->WriteToFile("D:\\result.txt");
	}
	else
	{
		std::cout << "Failed...";
	}

	
	

	std::cout << "Complete\n time:"<< std::clock()<<std::endl;


	std:getchar();
	return 0;
}

Matrix* Multiply(Matrix firstMatrix, Matrix secondMatrix)
{
	try
	{
		if (firstMatrix.N != secondMatrix.M)  throw "can't multiply n1 not equal m2";
		Matrix* resultMatrix=new Matrix();
		resultMatrix->M = firstMatrix.M;
		resultMatrix->N = secondMatrix.N;
		resultMatrix->matrix = new int*[resultMatrix->M];
		for (int i = 0; i < resultMatrix->M; i++)
		{
			resultMatrix->matrix[i] = new int[resultMatrix->N];
			for (int j = 0; j < resultMatrix->N; j++)
			{
				resultMatrix->matrix[i][j] = 0;
				for (int k = 0; k < firstMatrix.N; k++)
					resultMatrix->matrix[i][j] += firstMatrix.matrix[i][k] * secondMatrix.matrix[k][j];
			}
		}

		return resultMatrix;
	}
	catch (const char* str)
	{
		std::cout << str << std::endl;
		return 0;
	}

}




