#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	const int a = 100;
	setlocale(LC_ALL, "Ukrainian");
	int A[a] = {0};
	int B[a] = {0};
	int n1, n2;
	int i1 = 0;
	int i2 = 0;
	cout << "Введiть розмiр множини А: ";
	cin >> n1;
	if (n1 <= 0 || n1 >= 10)
	{
		cout << "Розмiрнiсть повинна бути вiд 1 до 10!" << endl;
		return 0;
	}
	else
	{
		cout << "Введiть множину А" << endl;
		for (i1 = 0; i1 < n1; i1++)
		{
			cout << "Введiть " << i1 + 1 << " елемент: ";
			cin >> A[i1];
		}
		cout << "Введiть розмiр множини B: ";
		cin >> n2;
		if (n2 <= 0 || n2 >= 10)
		{
			cout << "Розмiрнiсть повинна бути вiд 1 до 10!" << endl;
			return 0;
		}
		else
		{
			cout << "Введiть множину B" << endl;
			for (i2 = 0; i2 < n2; i2++)
			{
				cout << "Введiть " << i2 + 1 << " елемент: ";
				cin >> B[i2];
			}
			cout << endl;
			int C[2 * a];
			int k = 0;
			for (int i = 0; i < n2; i++)
			{
				for (int j = 0; j < n1; j++)
				{
					if (B[i] == A[j])
					{
						C[k] = A[j];
						k++;
					}
				}
			}
			cout << "Перетин множин А i В: { ";
			for (int i = 0; i < k; i++)
			{
				cout << C[i] << " ";
			}
			cout << "}";
			cout << endl;
			cout << "Потужнiсть новоутвореної множини: " << k << endl;
			const int r = 2 * a;
			int D[r];
			for (int i = 0; i < n1; i++)
			{
				D[i] = A[i];
			}
			int f = n1; int q;
			for (int i = 0; i < n2; i++)
			{
				for (int j = 0; j < n1; j++)
				{
					if (B[i] == A[j])
					{
						q = 1;
						break;
					}
					else
					{
						q = 0;
					}
				}
				if (q == 0)
				{
					D[f] = B[i];
					f++;
				}
			}
			cout << "Об'еднання множин А i В: { ";
			for (int i = 0; i < f; i++)
				cout << D[i] << " ";
			cout << "}" << endl;
			cout << "Потужнiсть новоутвореної множини: " << f << endl;
		}
	}
	return 0;
}