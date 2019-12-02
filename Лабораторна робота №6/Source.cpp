#include <iostream>
#include <math.h>

using namespace std;

int factorial(int a)
{
	if (a == 1)
	{
		return a;
	}
	else if (a == 0)
	{
		return 1;
	}
	return a * factorial(a - 1);
}

long long int koef(int n, int d) 
{
	return factorial(d) / (factorial(n) * factorial(d - n));
}


int main()
{
	int a[50];

	int r;
	cout << "Enter r: " << endl;
	cin >> r;
	int n;
	cout << "Enter n: " << endl;
	cin >> n;
	for (int i = 0; i < r; ++i)
	{
		a[i] = 0;
	}

	bool finish = false;
	int key = 0;

	while (!finish) 
	{
		for (int i = r - 1; i >= 0; --i) 
		{
			if (a[i] < n) 
			{
				a[i]++;
				for (int j = i + 1; j <= r; ++j) 
				{
					a[j] = 1;
				}
				break;
			}
			if (i == 0)
				finish = true;
		}

		for (int i = 0; i < r; ++i)
		{
			if (a[i] == 0)
			{
				break;
			}
			else
			{
				///if ((key / r) < (pow(n, r)))
					cout << a[i] << " ";
				///key++;
			}
		}
		cout << endl;
	}


	long long int x, y;
	cout << endl << "Enter x:";
	cin >> x;
	cout << "Enter y:";
	cin >> y;
	if (x == y) {
		cout << "(x - y)^12 = 0";
		return 0;
	}
	long long int binom = 0;
	for (int i = 0; i <= 12; ++i) 
	{
		binom += koef(i, 12) *pow(x, i) * pow(-y, 12 - i);
	}
	cout << "(x - y)^12 = ";
	for (int i = 0; i < 12; ++i) 
	{
		if (i % 2)
		{
			cout << " - "; 
		}
		else
		{ 
			cout << " + "; 
		}
		cout << koef(i, 12) << " * (x^" << i << ") * (y^" << 12 - i << ")";
	}
	cout << " = " << binom << "\n";
	return 0;
}