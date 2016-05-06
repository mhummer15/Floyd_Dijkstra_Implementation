#include "dijkstra.h"

Dijkstra::Dijkstra(int num)
{
	n = num;
	s = new bool [n];
	dist = new int [n];
	adj = new int* [n];
	for (int i = 0; i < n; i++)
	{
		adj[i] = new int [n];
		s[i] = false;
	}
};

void Dijkstra::fillMat(int i, int j, int num)
{
	adj[i][j] = num;
};

void Dijkstra::algo()
{
	ofstream doutFile;
	doutFile.open ("dijkstraOutput.txt");
	int v = 0;
	int start_s=clock();
	while(v < n)
	{
		for (int i = 0; i < n; i++)
			dist[i] = adj[v][i];
		s[v] = true;
		for (int i = 0; i < n; i++)
		{
			if (i != v)
			{
				int small = dist[v+1];
				for (int c = 0; c < n; c++)
				{
					if ((dist[c] < small) && (s[c] == false))
						small = dist[c];
				}
				int u;
				for(int c = 0; c < n; c++)
				{
					if ((small == dist[c]) && (s[c] == false)) 
					{	
						u = c;
						s[u] = true;
					}
				}
				for(int w = 0; w < n; w++)
				{
					if (s[w] == false)
					{
						if (dist[w] > (dist[u] + adj[u][w]))
						{
							dist[w] =  dist[u] + adj[u][w];
						}
					}
				}
			}
			
		}
		for (int a = 0; a < n; a++)
			doutFile << dist[a] << " ";
		doutFile << endl;
		for (int k = 0; k < 0; k++)
			s[k] = false;
		v++;
	}
	doutFile << endl;
	int stop_s = clock();
	cout << "dijkstra time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}

Dijkstra::~Dijkstra()
{
	delete [] s;
	delete [] dist;
	for (int i = 0; i < n; i++)
		delete [] adj[i];
	delete [] adj;
}
