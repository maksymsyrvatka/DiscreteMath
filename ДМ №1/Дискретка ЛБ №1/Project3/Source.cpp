#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	bool x, y, z; // ���������� ������ x, y, �� z;
	// �������� ����� ����� ������ � ���������;
	cin >> x >> y >> z;
	// ���������� �� ����������� ����� ������ ��������:
	int P1 = y && z; 
	int P2 = x && P1;
	int Q1 = x || y;
	int Q2 = Q1 || z;
	setlocale(LC_ALL, "Ukrainian");

	bool S;

	// ���������� �������� ��������� ��� ����� ������� �����;
	if ((x == 0 || x == 1) && (y == 0 || y == 1) && (z == 0 || z == 1))
	{
		if (!P2 && !Q2) S = true;
		else if (!P2 && Q2) S = true;
		else if (P2 && !Q2) S = false;
		else if (P2 && Q2) S = true;
		cout << "x | y | z | y * z | x * (y * z) | x + y | x + y + z | (x * y * z) -> (x + y + z)" << endl;
		cout << x << " " << "  " << y << "   " << z << "    " << P1 << "      " << P2 << "           " << Q1 << "          " << Q2 << "           " << S << endl;
		system("pause");
		return 0;
	}
	else
	{
		cout << "�������!!!" << endl;
		system("pause");
		return 0;
	}

	system("pause");
	return 0;
}