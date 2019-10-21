#include <iostream>

using namespace std;

void Output(int **A, int *B, int *C, int p, int q)
{
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < q; j++)
		{
			A[i][j] = 0;
		}
	}
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < q; j++)
		{
			if ((B[i] + C[j] + 1) > 3)
			{
				A[i][j] = 1;
			}
			else
			{
				A[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < q; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

int Symetria(int **A, int p, int q)
{
	int a = 1;
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < q; j++)
		{
			if (A[i][j] == A[j][i])
				a *= 1;
			else
				a *= 0;
		}
	}
	if (a == 1)
	{
		cout << "Matrix is symmetric." << endl;
	}
	if (a == 0)
	{
		cout << "Matrix is asymmetric." << endl;
	}
	return a;
}

int Reflexive(int **A, int p, int q)
{
	int a = 0;
	for (int i = 0; i < p; i++)
	{
		if (A[i][i] == 0)
		{
			cout << "Matrix isn't reflexive." << endl;
			a = 1;
			break;
		}
	}
	if (a == 0)
	{
		cout << "Matrix is reflexive." << endl;
	}
	return a;
}

int Antireflexive(int **A, int p, int q)
{
	int a = 1;
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < q; j++)
		{
			if ((A[i][j] != 0) && (i == j))
			{
				a *= 0;
			}
		}
	}
	if (a == 1)
	{
		cout << "Matrix is antireflexive." << endl;
	}
	else
	{
		cout << "Matrix isn't antireflexive." << endl;
	}
	return a;
}

int Transitive(int **A, int p, int q)
{
	int a = 0;
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < q; j++)
		{
			for (int h = 0; h < q; h++)
			{
				if (A[i][j] == 1 && A[j][h] == 1)
				{
					if (A[i][h] != 1)
					{
						a = 1;
						break;
					}
				}
			}
		}
	}
	if (a == 0)
	{
		cout << "Matrix is transitive." << endl;
	}
	else if(a == 1)
	{
		cout << "Matrix isn't transitive." << endl;
	}
	return a;
}

int Antitransitive(int **A, int p, int q)
{
	int a = 0;
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < q; j++)
		{
			for (int h = 0; h < q; h++)
			{
				if (A[i][j] == 1 && A[j][h] == 1)
				{
					if (A[i][h] != 0)
					{
						a = 1;
						break;
					}
				}
			}
		}
	}
	if (a == 0)
	{
		cout << "Matrix is antitransitive." << endl;
	}
	else if (a == 1)
	{
		cout << "Matrix isn't antitransitive." << endl;
	}
	return a;
}
