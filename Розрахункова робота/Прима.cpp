#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

const int MAX = 2000;

int main()
{
	char s;
	do
	{
		system("cls");
		setlocale(LC_ALL, "Ukr");
		const int n = 11;


		int graph[11][11] =
		{	
			{0, 1, 2, 3, 0, 0, 0, 0, 0, 0, 0},
			{1, 0, 0, 0, 4, 0, 2, 0, 0, 0, 0},
			{2, 0, 0, 0, 7, 5, 0, 0, 0, 0, 0},
			{3, 0, 0, 0, 0, 2, 3, 0, 0, 0, 0},
			{0, 4, 7, 0, 0, 0, 0, 4, 6, 0, 0},
			{0, 0, 5, 2, 0, 0, 0, 7, 0, 3, 0},
			{0, 2, 0, 3, 0, 0, 0, 0, 5, 7, 0},
			{0, 0, 0, 0, 4, 7, 0, 0, 0, 0, 4},
			{0, 0, 0, 0, 6, 0, 5, 0, 0, 0, 1},
			{0, 0, 0, 0, 0, 3, 7, 0, 0, 0, 4},
			{0, 0, 0, 0, 0, 0, 0, 4, 1, 4, 0},
		};

		cout << "Adjacency matrix : " << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << graph[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		int start;
		do {
			cout << "Enter the start vertex: \n";
			cin >> start;
		} while (start < 1 || start > 11);
		cout << "\nMinimum spanning tree: " << endl;
		bool *visited = new bool[n];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (graph[i][j] == 0)
					graph[i][j] = MAX;
			}
			visited[i] = false;
		}
		int v1, v2;
		int min, weight = 0;
		visited[start - 1] = true;
		cout << "E = { ";
		for (int tek = 1; tek < n; tek++)
		{
			min = MAX;
			for (int i = 0; i < n; i++)
			{
				if (visited[i] == true)
				{
					for (int d = 0; d < n; d++)
					{
						if (min > graph[i][d] && !visited[d])
						{
							v1 = i;
							min = graph[i][d];
							v2 = d;
						}
					}
				}
			}
			weight += min;
			visited[v2] = true;
			if (tek != n - 1)
			{
				cout << "(" << v1 + 1 << ',' << v2 + 1 << "),";
			}
			else if (tek == n - 1)
			{
				cout << "(" << v1 + 1 << ',' << v2 + 1 << ") }";
			}
		}
		cout << "\n\nMinimal weight of tree: " << weight << endl;
		cout << "One more? (y/n)" << endl;
		s = _getch();
	} while (s != 'n');

	return 0;
}