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
////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

struct Distance

{

	int feet;

	float inches;

};

int main()

{
	Distance d1, d3;
	Distance d2 = { 11, 6.25 }; 

	cout << "\nEnter feet: "; cin >> d1.feet;
	cout << "Enter inches: "; cin >> d1.inches;

	d3.inches = d1.inches + d2.inches;
	d3.feet = 0; 

	if (d3.inches >= 12.0)
	{ 
		d3.inches -= 12.0;
		d3.feet++; 
	}

	d3.feet += d1.feet + d2.feet;
	cout << d1.feet << "\'-" << d1.inches << "\" + ";
	cout << d2.feet << "\'-" << d2.inches << "\" = ";
	cout << d3.feet << "\'-" << d3.inches << "\"\n";

	return 0;

}
#4
#include <iostream>

using namespace std;

struct employee
{
	int id;

	float salary;
};

int main()
{
	setlocale(LC_ALL, "Russian");

	employee p1, p2, p3;

	cout << "Введите инфу о сотруднике(ид и салари) №1\n";
	cin >> p1.id >> p1.salary;

	cout << "Введите инфу о сотруднике(ид и салари) №2\n";
	cin >> p2.id >> p2.salary;
	
	cout << "Введите инфу о сотруднике(ид и салари) №3\n";
	cin >> p3.id >> p3.salary;

	cout << "Ид сотрудника №1: " << p1.id
		<< "\nЗарплата сотрудника №1: " << p1.salary;

	cout << "\nИд сотрудника №2: " << p2.id
		<< "\nЗарплата сотрудника №2: " << p2.salary;

	cout << "\nИд сотрудника №3: " << p3.id
		<< "\nЗарплата сотрудника №3: " << p3.salary;

	return 0;
}
#5
#include <iostream>

using namespace std;

struct date
{
	int day;
	int month;
	int year;
};

int main()
{
	setlocale(LC_ALL, "Russian");

	date p;

	cout << "Введите инфу о своём дне рождении в виде ДД/ММ/ГГГГ ";
	cin >> p.day >> p.month >> p.year;

	cout << "Ваша дата рождения: " << p.day << "/" << p.month << "/" << p.year;

	return 0;
}
#6
#include <iostream>

using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main()
{
	setlocale(LC_ALL, "Russian");

	etype p;
	char c;

	cout << "Введите первую букву должности: ";
	cin >> c;

	switch (c)
	{
		{
	case 'l':
		p = laborer;
		break;
	case 's':
		p = secretary;
		break;
	case 'm':
		p = manager;
		break;
	case 'a':
		p = accountant;
		break;
	case 'e':
		p = executive;
		break;
	case 'r':
		p = researcher;
		}
	}

	string str;

	switch (p)
	{
	case laborer:
		str = "laborer";
		break;
	case secretary:
		str = "secretary";
		break;
	case manager:
		str = "manager";
		break;
	case accountant:
		str = "accountant";
		break;
	case executive:
		str = "executive";
		break;
	case researcher:
		str = "researcher";
		break;
	}

	cout << "ОНО: " << str;

	return 0;
}
#7
#include <iostream>

using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

struct date
{
	int day;
	int month;
	int year;
};

struct employee
{
	int id;

	float salary;
};

int main()
{
	setlocale(LC_ALL, "Russian");

	etype p_1;
	char c1;

	cout << "Введите первую букву должности: ";
	cin >> c1;

	switch (c1)
	{
		{
	case 'l':
		p_1 = laborer;
		break;
	case 's':
		p_1 = secretary;
		break;
	case 'm':
		p_1 = manager;
		break;
	case 'a':
		p_1 = accountant;
		break;
	case 'e':
		p_1 = executive;
		break;
	case 'r':
		p_1 = researcher;
		}
	}

	string str;

	switch (p_1)
	{
	case laborer:
		str = "laborer";
		break;
	case secretary:
		str = "secretary";
		break;
	case manager:
		str = "manager";
		break;
	case accountant:
		str = "accountant";
		break;
	case executive:
		str = "executive";
		break;
	case researcher:
		str = "researcher";
		break;
	}

	employee p1;

	cout << "Введите инфу о сотруднике(ид и салари) №1\n";
	cin >> p1.id >> p1.salary;

	date f1;

	cout << "Введите инфу о дне приёма на рaботу в виде ДД/ММ/ГГГГ сотрудника №1";
	cin >> f1.day >> f1.month >> f1.year;

	etype p_2;
	char c2;

	cout << "Введите первую букву должности: ";
	cin >> c2;

	switch(c2)
	{
		{
	case 'l':
		p_2 = laborer;
		break;
	case 's':
		p_2 = secretary;
		break;
	case 'm':
		p_2 = manager;
		break;
	case 'a':
		p_2 = accountant;
		break;
	case 'e':
		p_2 = executive;
		break;
	case 'r':
		p_2 = researcher;
		}
	}

	string str2;

	switch (p_2)
	{
	case laborer:
		str2 = "laborer";
		break;
	case secretary:
		str2 = "secretary";
		break;
	case manager:
		str2 = "manager";
		break;
	case accountant:
		str2 = "accountant";
		break;
	case executive:
		str2 = "executive";
		break;
	case researcher:
		str2 = "researcher";
		break;
	}

	employee p2;

	cout << "Введите инфу о сотруднике(ид и салари) №2\n";
	cin >> p2.id >> p2.salary;

	date f2;

	cout << "Введите инфу о дне приёма на рaботу в виде ДД/ММ/ГГГГ сотрудника №2";
	cin >> f2.day >> f2.month >> f2.year;

	etype p_3;
	char c3;

	cout << "Введите первую букву должности: ";
	cin >> c3;

	switch (c3)
	{
		{
	case 'l':
		p_3 = laborer;
		break;
	case 's':
		p_3 = secretary;
		break;
	case 'm':
		p_3 = manager;
		break;
	case 'a':
		p_3 = accountant;
		break;
	case 'e':
		p_3 = executive;
		break;
	case 'r':
		p_3 = researcher;
		}
	}

	string str3;

	switch (p_3)
	{
	case laborer:
		str3 = "laborer";
		break;
	case secretary:
		str3 = "secretary";
		break;
	case manager:
		str3 = "manager";
		break;
	case accountant:
		str3 = "accountant";
		break;
	case executive:
		str3 = "executive";
		break;
	case researcher:
		str3 = "researcher";
		break;
	}

	employee p3;

	cout << "Введите инфу о сотруднике(ид и салари) №3\n";
	cin >> p3.id >> p3.salary;

	date f3;

	cout << "Введите инфу о дне приёма на рaботу в виде ДД/ММ/ГГГГ сотрудника №3";
	cin >> f3.day >> f3.month >> f3.year;

	cout << "Дата приёма на работу работника №1: " << f1.day << "/" << f1.month << "/" << f1.year;
	cout << "ОНО: " << str;
	cout << "Его зпрплата: " << p1.salary << endl;
	cout << "Его ИД: " << p1.id;

	cout << "Дата приёма на работу работника №2: " << f2.day << "/" << f2.month << "/" << f2.year;
	cout << "ОНО: " << str2;
	cout << "Его зпрплата: " << p2.salary << endl;
	cout << "Его ИД: " << p2.id;

	cout << "Дата приёма на работу работника №1: " << f3.day << "/" << f3.month << "/" << f3.year;
	cout << "ОНО: " << str3;
	cout << "Его зпрплата: " << p3.salary << endl;
	cout << "Его ИД: " << p3.id;

	return 0;
}
#9
#include <iostream>

using namespace std;

struct time
{
	int hours;
	int minutes;
	int seconds;
};

int main()
{
	time t1;
	cout << "Введите часы: ";
	cin >> t1.hours;
	cout << "Введите минуты: ";
	cin >> t1.minutes;
	cout << "Введите секунды: ";
	cin >> t1.seconds;

	int total_seconds;
	total_seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
	cout << "Количество секунд: " << total_seconds;

	return 0;
}
#10
#include <iostream>

using namespace std;

struct Sterling
{
	int pounds;
	int shillings;
	int penny;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	
	Sterling sterling;
	double newPounds;
	double penny_1, penny_2, temp_1, temp_2;

	cout << "Введите сумму в новых фунтах: ";
	cin >> newPounds;

	penny_1 = newPounds * 240;
	sterling.pounds = static_cast<int>(newPounds);
	penny_2 = sterling.pounds * 240;
	temp_1 = penny_1 - penny_2;
	temp_1 = static_cast<int>(temp_1);
	sterling.shillings = temp_1 / 12;
	sterling.shillings = static_cast<int>(sterling.shillings);
	temp_2 = sterling.shillings * 12;
	sterling.penny = temp_1 - temp_2;

	cout << "Фунтов в старой системе: " << sterling.pounds << "." << sterling.shillings << "." << sterling.penny << endl;
}
#11
#include <iostream>

using namespace std;

struct time
{
	int hours;
	int minutes;
	int seconds;
};

int main()
{
	time t1;
	cout << "Введите часы 1: ";
	cin >> t1.hours;
	cout << "Введите минуты 1: ";
	cin >> t1.minutes;
	cout << "Введите секунды 1: ";
	cin >> t1.seconds;

	time t2;
	cout << "Введите часы 2: ";
	cin >> t2.hours;
	cout << "Введите минуты 2: ";
	cin >> t2.minutes;
	cout << "Введите секунды 2: ";
	cin >> t2.seconds;

	int total_seconds[2];
	total_seconds[0] = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
	total_seconds[1] = t2.hours * 3600 + t2.minutes * 60 + t2.seconds; 
	total_seconds[0] += total_seconds[1];
	cout << "Количество секунд: " << total_seconds[0];

	return 0;
}
#12
#include <iostream>

using namespace std;

struct drob
{
	int shisl;
	int znam;
};

int main()
{
	setlocale(LC_ALL, "Russian");

	bool cont = 1;
	drob a, b;
	int result_chisl, result_znam;


	do {
		cont = 0;

		char dummy_char;

		cout << "Введите первую дробь: ";
		cin >> a.shisl >> dummy_char >> a.znam;

		cout << "Введите вторую дробь: ";
		cin >> b.shisl >> dummy_char >> b.znam;

		char oper;
		float mult;
		cout << "Введите опреатор: ";
		{
			cin >> oper;
		}

		switch (oper)
		{
		case '+':
			result_chisl = (a.shisl * b.znam + b.shisl * a.znam);
			result_znam = (b.znam * a.znam);
			break;
		case '-':
			result_chisl = (a.shisl * b.znam - b.shisl * a.znam);
			result_znam = (b.znam * a.znam);
			break;
		case '*':
			result_chisl = (a.shisl * b.shisl);
			result_znam = (a.znam * b.znam);
			break;
		case '/':
			result_chisl = a.shisl * b.znam;
			result_znam = b.shisl * a.znam;
		}

		cout << "Результат: " << result_chisl << '/' << result_znam;

		cout << endl << "Продолжить (y/n) ";
		char c;
		cin >> c;

		if (c == 'y')
		{
			cont = 1;
		}

	} while (cont);

	return 0;
}
