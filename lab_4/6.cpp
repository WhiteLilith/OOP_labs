#include <iostream>

using namespace std;

struct time
{
	int hours;
	int minutes;
	int seconds;
};

int convert_to_secs(time a)
{
	return a.hours * 3600 + a.minutes * 60 + a.seconds;
}

time convert_to_time(int a)
{
	time b;
	b.hours = a / 3600;
	b.minutes = (a - b.hours * 3600) / 60;
	b.seconds = a - b.hours * 3600 - b.minutes * 60;
	return b;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	time a;
	int b;

	cout << "Введите время (Ч, М, С): ";
	cin >> a.hours >> a.minutes >> a.seconds;
	b = convert_to_secs(a);
	cout << "Eto " << b << " secund" << endl;
	
	cout << "Введите колво секунд: ";
	int k;
	cin >> k;

	time rez;
	rez = convert_to_time(k);

	cout << "Eto " << rez.hours << " chasov, "
		 << rez.minutes << " minut, " << rez.seconds << " secund";

	return 0;
}
