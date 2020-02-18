#include <iostream>

using namespace std;

struct time
{
	int hours;
	int minutes;
	int seconds;
};

void swap(time& a, time& b)
{
	time bus;
	bus.hours = a.hours;
	bus.minutes = a.minutes;
	bus.seconds = a.seconds;
	a.hours = b.hours;
	a.minutes = b.minutes;
	a.seconds = b.seconds;
	b.hours = bus.hours;
	b.minutes = bus.minutes;
	b.seconds = bus.seconds;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	time a, b;
	cout << "Vvedite dva vremeni(a и b): ";
	cin >> a.hours >>  a.minutes >> a.seconds;
	cin >> b.hours >> b.minutes >> b.seconds;
	swap(a, b);
	cout << "a: " << a.hours << " hours, " << a.minutes << " minutes, " << a.seconds << " seconds" << endl;
	cout << "a: " << b.hours << " hours, " << b.minutes << " minutes, " << b.seconds << " seconds" << endl;
}
