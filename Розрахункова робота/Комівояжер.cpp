#include <iostream>

using namespace std;

const int n = 9;
const int inf = 20000;
bool check(int key, int* mas, int kol);

int main() 
{
	int arr[n][n] = {
		{0,  0,  0, 0,  0,  0,  0,  0,  0},
		{0, inf, 1, 1,	1,	1,	1,	3,	1},
		{0, 1,	inf, 5,	1,	2,	1,	3,	3},
		{0, 1,	5, inf,	2,	5,	4,	1,	5},
		{0, 1,	1,	2, inf,	5,	5,	6,	1},
		{0, 1,	2,	5,	5, inf,	1,	5,	1},
		{0, 1,	1,	4,	5,	1, inf,	5,	6},
		{0, 3,	3,	1,	6,	5,	5, inf,	1},
		{0, 1,	3,  5,	1,	1,	6,	1, inf},
	};
	
	int vertex[n - 1];
	int start;
	char c;
	do {
		//system("cls");
		for (int i = 1; i < n; i++)
			vertex[i] = inf;
		do
		{
			cout << "Enter the start vertex: ";
			cin >> start;
		} while (start < 1 || start > n - 1);

		vertex[0] = start;
		int current = start;
		int path = 0;
		cout << "Path:" << endl;
		for (int i = 2; i < n; i++) 
		{
			int min = inf;
			int min_t;
			for (int j = 1; j < n; j++) 
			{
				if (check(j, vertex, n) && arr[current][j] < min && arr[current][j] > 0)
				{
					min = arr[current][j];
					min_t = j;
				}
			}

			path += min;
			vertex[i] = min_t;
			cout << current << " -> " << vertex[i] << " = " << min  << endl;
			current = vertex[i];
		}
		path += arr[start][current];
		cout << current << " -> " << start << " = " << arr[start][current] << endl;
		cout << "Total path: " << path << endl;

		cout << endl << "Press 'n' to stop: ";
		cin >> c;

	} while (c != 'n');

	system("pause");
	return 0;
}

bool check(int l, int* arr, int num) {
	for (int j = 0; j < num; j++)
	{
		if (arr[j] == l)
		{
			return false;
		}
	}
	return true;
}