#include <iostream>

using namespace std;

void zeroSmaller(int &a, int &b)
{
	if (a < b)
	{
		a = 0;
	}
	else
	{
		b = 0;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

    cout << "Введите числа(a и b): ";
	int a, b;
	cin >> a >> b;

	zeroSmaller(a, b);

	cout << "a = " << a << ", b = " << b;
	return 0;
}
