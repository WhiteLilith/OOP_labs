#include <iostream>

using namespace std;

struct time
{
	int hours;
	int minutes;
	int seconds;
};

int convert(time a)
{
	return a.hours * 3600 + a.minutes * 60 + a.seconds;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	bool cont = 1;
	time a;
	int b;

	do
	{
		cout << "Введите время (Ч, М, С): ";
		cin >> a.hours >> a.minutes >> a.seconds;
		b = convert(a);
		cont = 0;
		cout << "Eto " << b << " secund" << endl;
		cout << "Продолжить (y/n) ";
		char c;
		cin >> c;
		if (c == 'y')
		{
			cont = 1;
		}
	} while (cont);

	return 0;
}
