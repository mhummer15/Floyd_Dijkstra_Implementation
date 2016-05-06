#ifndef ADJACENCY_H_
#define ADJACENCY_H_
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class AdjacencyMatrix
{
	private:
		int n;
		int **adj;
	public:
		AdjacencyMatrix(int num);
		~AdjacencyMatrix();
		void randFill();
		void gradientFill();
		void oneFill();
		//void createFile();
		int getNum(int k,int l);
};

#endif
