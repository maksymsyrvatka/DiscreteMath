#include <iostream>

const int n = 12;

using namespace std;

int min, path[12];

int main()
{
	int i, j;
	int a, b, u, v;
	int l = 1;
	cout << "The cost adjacency matrix: " << endl;
	int graph[12][12] = {
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 2, 3, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 0, 0, 0, 4, 0, 2, 0, 0, 0, 0},
{0, 2, 0, 0, 0, 7, 5, 0, 0, 0, 0, 0},
{0, 3, 0, 0, 0, 0, 2, 3, 0, 0, 0, 0},
{0, 0, 4, 7, 0, 0, 0, 0, 4, 6, 0, 0},
{0, 0, 0, 5, 2, 0, 0, 0, 7, 0, 3, 0},
{0, 0, 2, 0, 3, 0, 0, 0, 0, 5, 7, 0},
{0, 0, 0, 0, 0, 4, 7, 0, 0, 0, 0, 4},
{0, 0, 0, 0, 0, 6, 0, 5, 0, 0, 0, 1},
{0, 0, 0, 0, 0, 0, 3, 7, 0, 0, 0, 4},
{0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 4, 0},
	};
	for (i = 1; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			cout << graph[i][j] << " ";
			if (graph[i][j] == 0)
				graph[i][j] = 999;
		}
		cout << endl;
	}
	cout << "The verteces of the minimal tree are: " << endl;
	while (1)
	{
		for (i = 1, min = 999;i < n;i++)
		{
			for (j = 1;j < n;j++)
			{
				if (graph[i][j] < min)
				{
					min = graph[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}
		while (path[u])
			u = path[u];
		while (path[v])
			v = path[v];
		bool uni = false;
		if (u != v)
		{
			path[v] = u;
			uni = true;
		}
		if (uni)
		{
			cout << l++ <<  " edge (" << a << ", " << b << ") = " << min << endl;
		}
		graph[a][b] = graph[b][a] = 999;
	}
	return 0;
}