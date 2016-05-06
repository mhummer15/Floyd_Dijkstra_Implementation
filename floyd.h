#ifndef FLOYD_H_
#define FLOYD_H_
#define INF 9999
#include <iostream>
#include <sys/resource.h>
#include <sys/times.h>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

class Floyd
{
	private:
		int n;
		int** A;
	public:
		Floyd(int num);
		void fillA(int i, int j, int num);
		void algo();
		~Floyd();
};

#endif
