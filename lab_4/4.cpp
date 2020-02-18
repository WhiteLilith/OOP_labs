#include <iostream>

using namespace std;

struct Distance
{
	int feet;
	float inches;
};

Distance big(Distance a, Distance b)
{
	if (a.feet * 12 + a.inches > b.feet * 12 + b.inches)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void print(Distance a)
{
	cout << a.feet << " feet and " << a.inches << " inches";
}

int main()
{
	setlocale(LC_ALL, "Russian");

    cout << "Введите длины(a и b): ";
	Distance a, b, rez;
	cin >> a.feet >> a.inches;
	cin >> b.feet >> b.inches;

	rez = big(a, b);

	print(rez);
	return 0;
}
