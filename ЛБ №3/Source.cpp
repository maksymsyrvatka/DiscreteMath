#include <iostream>
#include "BW1.h"

using namespace std;

void Output(int **A, int *B, int *C, int p, int q);
int Symetria(int **A, int p, int q);
int Reflexive(int **A, int p, int q);
int Anrireflexive(int **A, int p, int q);
int Transitive(int **A, int p, int q);
int Antitransitive(int **A, int p, int q);

int main()
{
	int n, m;
	cout << "Input size of A: ";
	cin >> n;
	cout << "Input size of B: ";
	cin >> m;
	if (m != n)
	{
		cout << "The size of A and B must be equal integer figures!" << endl;
	}
	else
	{
		cout << endl;
		int *A = new int[n];
		int *B = new int[m];
		int **Ro = new int *[n];
		for (int i = 0; i < n; i++)
		{
			Ro[i] = new  int[m];
		}
		for (int i = 0; i < n; i++)
		{
			cout << "Input the element number " << i + 1 << " of A: ";
			cin >> A[i];
		}
		for (int j = 0; j < m; j++)
		{
			cout << "Input the element number " << j + 1 << " of B: ";
			cin >> B[j];
		}
		Output(Ro, A, B, n, m);
		Symetria(Ro, n, m);
		Reflexive(Ro, n, m);
		Antireflexive(Ro, n, m);
		Transitive(Ro, n, m);
		Antitransitive(Ro, n, m);
	}
	return 0;
}