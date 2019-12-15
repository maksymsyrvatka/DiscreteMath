#include <iostream>

using namespace std;

const int n = 13;
const int s = 100;

int k;
int path[s];

void Fleury(int);

int graph[n][n] =
{
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
{0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
{0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0},
{0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0},
{0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0},
{0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
{0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
{0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1},
{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0},
};

int main()
{   
	int s = 0;
	int vertex;
	bool T = true;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			s += graph[i][j];
		}
		if (s % 2) 
			T = false;
	}
	k = -1;

	cout << "Enter the first vertex: ";
	cin >> vertex;
	cout << "The Eulerian circle: ";
	if (T)
	{
		Fleury(vertex);
		for (int j = 0; j < k; j++)
		{
			cout << path[j] << " --> " << path[j+1] << endl;
		}
	}
	else
		cout << "There is no Eulerian circle!!!" << endl;
	return 0;
}

void Fleury(int v)
{
	int i;
	for (i = 0; i < n; i++)
		if (graph[v][i])
		{
			graph[v][i] = graph[i][v] = 0;
			Fleury(i);
		}
	path[++k] = v;
}
