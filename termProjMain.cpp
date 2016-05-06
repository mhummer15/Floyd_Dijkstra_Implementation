#include "dijkstra.h"
#include "floyd.h"
using namespace std;

int main()
{
	int n, num;
	for (int i = 0; i < 30; i++)
	{
		cout << i+1 << endl;
		cin >> n;
		cout << n << endl;
		Dijkstra* dij = new Dijkstra(n);
		Floyd* floyd = new Floyd(n);
		for (int k = 0; k < n; k++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> num;
				dij->fillMat(k, j, num);
				floyd->fillA(k, j, num);
			}
		}
		
		
		//dij->fillMat();
		dij->algo();
		//floyd->fillA();
		floyd->algo();
		delete dij;
		delete floyd;
	}
	return 0;
}
