#include <iostream>

using namespace std;

struct drob
{
	int shisl;
	int znam;
};

drob fadd(drob a, drob b)
{
	drob rez;
	rez.shisl = (a.shisl * b.znam + b.shisl * a.znam);
	rez.znam = (b.znam * a.znam);
	return rez;
}

drob fsub(drob a, drob b)
{
	drob rez;
	rez.shisl = (a.shisl * b.znam - b.shisl * a.znam);
	rez.znam = (b.znam * a.znam);
	return rez;
}

drob fmul(drob a, drob b)
{
	drob rez;
	rez.shisl = (a.shisl * b.shisl);
	rez.znam = (a.znam * b.znam);
	return rez;
}

drob fdiv(drob a, drob b)
{
	drob rez;
	rez.shisl = a.shisl * b.znam;
	rez.znam = b.shisl * a.znam;
	return rez;
}

void print_rez(drob a)
{
	cout << "Rezult: " << a.shisl << '/' << a.znam;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	bool cont = 1;
	drob a, b;

	do {
		cont = 0;

		char dummy_char;

		cout << "Введите первую дробь: ";
		cin >> a.shisl >> dummy_char >> a.znam;

		cout << "Введите вторую дробь: ";
		cin >> b.shisl >> dummy_char >> b.znam;

		char oper;
		float mult;
		drob rez;
		cout << "Введите опреатор: ";
		{
			cin >> oper;
		}

		switch (oper)
		{
		case '+':
			rez = fadd(a, b);
			break;
		case '-':
			rez = fsub(a, b);
			break;
		case '*':
			rez = fmul(a, b);
			break;
		case '/':
			rez = fdiv(a, b);
		}

		print_rez(rez);

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
