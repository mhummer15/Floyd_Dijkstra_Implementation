#include "adjacency.h"
using namespace std;

int main()
{
	int num = 500;
	ofstream amFile;
	amFile.open ("matrix.txt");
	while (num < 1000)
	{
		AdjacencyMatrix* am = new AdjacencyMatrix(num);
		am->oneFill();
		amFile << num << endl;
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				amFile << am->getNum(i, j) << " ";
			}
			amFile << endl;
		}
		delete am;
		num += 50;
	}
	num = 500;
	while (num < 1000)
	{
		AdjacencyMatrix* am = new AdjacencyMatrix(num);
		am->randFill();
		amFile << num << endl;
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				amFile << am->getNum(i, j) << " ";
			}
			amFile << endl;
		}
		delete am;
		num += 50;
	}
	num = 500;
	while (num < 1000)
	{
		AdjacencyMatrix* am = new AdjacencyMatrix(num);
		am->gradientFill();
		amFile << num << endl;
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				amFile << am->getNum(i, j) << " ";
			}
			amFile << endl;
		}
		delete am;
		num += 50;
	}
	amFile.close();
	return 0;
}
