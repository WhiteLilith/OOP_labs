#1
#include <iostream>

using namespace std;

struct phone
{
	int area;
	int exchange;
	int number;
};

int main()
{
	setlocale(LC_ALL, "Russian");

	phone ph1 = { 212, 767, 8900 };
	phone ph2;

	cout << "\nEnter your area code, exchange, and number";
	cout << "\n(Don't use leading zeros): ";

	cin >> ph2.area >> ph2.exchange >> ph2.number;

	cout << "\nMy number is "
		<< '(' << ph1.area << ") "
		<< ph1.exchange << '-' << ph1.number << endl;

	cout << "\nYour number is "
		<< '(' << ph2.area << ") "
		<< ph2.exchange << '-' << ph2.number;

	return 0;
}
#2
#include <iostream>

using namespace std;

struct point
{
	int x;
	int y;
	char dummy_char;
};

int main()
{
	setlocale(LC_ALL, "Russian");

	point p1, p2, p3;

	cout << "Введите координаты точки p1: ";
	cin >> p1.x >> p2.dummy_char >> p2.y;

	cout << "Введите координаты точки р2: ";
	cin >> p2.x >> p2.dummy_char >> p2.y;

	p3.x = p1.x + p2.x;
	p3.y = p1.y + p2.y;

	cout << "Координаты точки p1+p2 равны " << p3.x << ";" << p3.y;

	return 0;
}
#3
#include <iostream>

using namespace std;

struct Distance
{
	int feet;
  #
	float inches;
};

struct Volume
{
	Distance length;
	Distance width;
	Distance height;
};

int main()
{
	setlocale(LC_ALL, "Russian");

	float l, w, h;

	Volume room1 = { { 16, 3.5 }, { 12, 6.25 }, { 8, 1.75 } };
	l = room1.length.feet + room1.length.inches / 12.0;
	w = room1.width.feet + room1.width.inches / 12.0;
	h = room1.height.feet + room1.height.inches / 12.0;
	cout << "Volume = " << l * w * h << " cubic feet\n";

	return 0;
  }
  #4
  
