#include "Matrix.h"





void Matrix::DebugOutpurMatrix()
{

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}

}

void Matrix::GetRandomMatrix(int M, int N)
{
	srand(time(0));
	this->M = M;
	this->N = N;
	matrix = new int*[M];
	
	for (int i = 0; i < M; i++)
	{
		matrix[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			matrix[i][j] = 1+rand()%100;
		}

	}


	rand();


}

void Matrix::WriteToFile(std::string FilePath)
{
	std::ofstream out;          // ����� ��� ������
	out.open(FilePath); // �������� ���� ��� ������
	if (out.is_open())
	{
		out << N <<" "<< M << std::endl;

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out << matrix[i][j];
				if (j != N - 1) { out << " "; }
			}
			out << std::endl;
		}


	}

}


void Matrix::GetMatrixFromFile(std::string FilePath)
{

	std::string line;

	std::ifstream in(FilePath); // �������� ���� ��� ������
	if (in.is_open())
	{
		
		//get first line with delimeter- M
		std::getline(in, line, ' ');
		M = atoi(line.c_str());
		//get first line - N
		std::getline(in, line);
		N = atoi(line.c_str());


		matrix = new int*[M];
		for (int i = 0; i < M; i++)
		{

			std::getline(in, line);
			std::vector<std::string> tokens = Utils::Split(line, ' ');
			matrix[i] = new int[N];
			for (int j = 0; j < N; j++)
			{
				matrix[i][j] = atoi(tokens[j].c_str());
			}

		}
	}
	in.close();
	DebugOutpurMatrix();
	std::cout << std::endl;
}
