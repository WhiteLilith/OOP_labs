#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
	int bus;
	bus = a;
	a = b;
	b = bus;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int a, b;
	cout << "Vvedite dva chisla(a и b): ";
	cin >> a >> b;
	swap(a, b);
	cout << "a = " << a << ", b = " << b;
}
