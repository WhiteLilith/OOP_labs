#include <iostream>

using namespace std;

float power(double n, int p = 2)
{
	if (p == 1)
	{
		return n;
	}
	else
	{
		n = n * power(n, p - 1);
	}
	return n;
}

int main()
{
	setlocale(LC_ALL, "Russian");

    cout << "Введите число и степень: ";
	float n, rez;
	int p;
	cin >> n >> p;

	rez = power(n, p);

	cout << "Ответ: " << rez;
	return 0;
}
