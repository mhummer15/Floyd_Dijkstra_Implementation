#include "adjacency.h"
using namespace std;

AdjacencyMatrix::AdjacencyMatrix(int num)
{
	n = num;
	adj = new int* [num];
	for (int i = 0; i < n; i++)
	{
		adj[i] = new int [num];
		for (int j = 0; j < n; j++)
			adj[i][j] = 0;
	}
};

AdjacencyMatrix::~AdjacencyMatrix()
{
	for (int i = 0; i < n; i++)
		delete [] adj[i];
	delete [] adj;
}

void AdjacencyMatrix::oneFill()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
				adj[i][j] = 1;
		}
	}
};

void AdjacencyMatrix::randFill()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
				adj[i][j] = rand() % 50 + 1;
		}
	}
};

void AdjacencyMatrix::gradientFill()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
				adj[i][j] = i + j;
		}
	}
};
/*void AdjacencyMatrix::createFile()
{
	ofstream amFile;
	amFile.open ("matrix.txt");
	amFile << n << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			amFile << adj[i][j] << " ";
		}
		amFile << endl;
	}
	amFile.close();
}*/

int AdjacencyMatrix::getNum(int k, int l)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i == k) && (j == l))
				return adj[i][j];
		}
	}
};		
