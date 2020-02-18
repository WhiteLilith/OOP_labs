#include <iostream>

using namespace std;

float circarea(float r)
{
	float pi = 3.14159;
	return r * r * pi;
}

int main()
{
	setlocale(LC_ALL, "Russian");

    cout << "Введите радиус круга: ";
	float r, s;
	cin >> r;

	s = circarea(r);

	cout << "Площадь круга равна " << s;
	return 0;
}
