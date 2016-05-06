#include "floyd.h"
using namespace std;

Floyd::Floyd(int num)
{
	n = num;
	A = new int* [n];
	for (int i = 0; i < n; i++)
		A[i] = new int [n];
}

void Floyd::fillA(int i, int j, int num)
{
	A[i][j] = num;
};

void Floyd::algo()
{
	ofstream foutFile;
	foutFile.open ("floydOutput.txt");
	int** dist;
	int** next;
	
	dist = new int* [n];
	next = new int* [n];
	for (int i = 0; i < n; i++)
	{
		dist[i] = new int [n];
		next[i] = new int [n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dist[i][j] = INF;
			next[i][j] = 0;
		}
	}
	for (int u = 0; u < n; u++)
	{
		for (int v = 0; v < n; v++)
		{
			dist[u][v] = A[u][v];
			next[u][v] = v;
		}
	}
	//good stuff
	int start_s = clock();
	for(int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
				for (int j = 0; j < n; j++)
				{
					if (dist[i][k] + dist[k][j] < dist[i][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						next[i][j] = next[i][k];
					}
				}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			foutFile << dist[i][j];
		}
		foutFile << endl;
	}
	foutFile << endl;
	int stop_s = clock();
	cout << "floyd-warshall time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
};

Floyd::~Floyd()
{
	for (int i = 0; i < n; i++)
		delete [] A[i];
	delete [] A;
};
