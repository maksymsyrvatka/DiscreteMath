#include <iostream>

using namespace std;

const int n = 10;

int graph[n][n] =
{	 
{0, 1, 1, 0, 0, 0, 1, 1, 1, 0 },
{1, 0, 1, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 0, 1, 1, 0, 0, 0, 0, 0 },
{0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
{0, 0, 1, 1, 0, 1, 1, 0, 1, 0 },
{0, 1, 0, 0, 1, 0, 0, 0, 0, 0 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
{1, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
{0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
};

int main()
{
	int start;
	cout << "Enter the start vertex: ";
	cin >> start;
	bool visited[n];
	cout << "Adjacency matrix: " << endl;
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		for (int j = 0; j < n; j++)
			cout << " " << graph[i][j];
		cout << endl;
	}

	int vertex = start - 1;
	int count = 0, head = 0;
	int queue[n];
	for (int i = 0; i < n; i++)
	{
		queue[i] = 0;
	}
	queue[count++] = vertex;
	visited[vertex] = true;
	cout << "Bypass of the graph: " << endl;
	while (head < count)
	{
		vertex = queue[head++];
		cout << vertex + 1 << " ";
		for (int i = 0; i < n; i++)
			if (graph[vertex][i] && !visited[i])
			{
				queue[count++] = i;
				visited[i] = true;
			}
	}
	cout << endl;
	system("pause");
	return 0;
}
