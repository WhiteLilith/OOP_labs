#include <iostream>

using namespace std;

class fraction
{
private:
	int chisl;
	int znam;
public:
	fraction(int a, int b)
	{
		chisl = a;
		znam = b;
	}
	fraction()
	{
		chisl = 1;
		znam = 1;
	}
void sokrat()
{
	int a = this->chisl;
	int b = this->znam;
	int c;
	while ((a != 0) && (b != 0))
	{
		if (a > b)
		{
			a %= b;
		}
		else
		{
			b %= a;
		}
	}
	c = a + b;
	this->chisl /= c;
	this->znam /= c;
}

void fadd(fraction a, fraction b)
{
	chisl = (a.chisl * b.znam + b.chisl * a.znam);
	znam = (b.znam * a.znam);
}

void fsub(fraction a, fraction b)
{
	chisl = (a.chisl * b.znam - b.chisl * a.znam);
	znam = (b.znam * a.znam);
}

void fmul(fraction a, fraction b)
{
	chisl = (a.chisl * b.chisl);
	znam = (a.znam * b.znam);
}

void fdiv(fraction a, fraction b)
{
	chisl = a.chisl * b.znam;
	znam = b.chisl * a.znam;
}

void print_rez()
{
	cout << "Rezult: " << chisl << '/' << znam;
}
};

int main()
{	
	setlocale(LC_ALL, "Russian");

	bool cont = 1;

	do {
		cont = 0;

		char dummy_char;
		int z, x;
		cout << "Введите первую дробь: ";
		cin >> z >> dummy_char >> x;
		fraction a(z, x);

		cout << "Введите вторую дробь: ";
		cin >> z >> dummy_char >> x;
		fraction b(z, x);

		char oper;
		float mult;
		fraction rez;
		cout << "Введите опреатор: ";
		{
			cin >> oper;
		}

		switch (oper)
		{
		case '+':
			rez.fadd(a, b);
			break;
		case '-':
			rez.fsub(a, b);
			break;
		case '*':
			rez.fmul(a, b);
			break;
		case '/':
			rez.fdiv(a, b);
		}

		rez.print_rez();

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
