#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_
#include <iostream>
#include <sys/resource.h>
#include <sys/times.h>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

class Dijkstra
{
	private:
		int n;
		int **adj;
		bool *s;
		int *dist;
	public:
		Dijkstra(int num);
		void fillMat(int i, int j, int num);
		void algo();
		~Dijkstra();
};

#endif
