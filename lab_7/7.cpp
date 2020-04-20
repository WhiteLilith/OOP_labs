#include <iostream>

using namespace std;

class Fraction
{
private:
	int chisl;
	int znam;
	void lowterms()
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

public:
	Fraction(int a, int b)
	{
		chisl = a;
		znam = b;
	}
	Fraction()
	{
		chisl = 1;
		znam = 1;
	}
	
	Fraction operator+(Fraction a)
	{
		Fraction rez((a.chisl * znam + chisl * a.znam), (znam * a.znam));
		rez.lowterms();
		return rez;
	}
	
	Fraction operator-(Fraction a)
	{
		Fraction rez((chisl * a.znam - a.chisl * znam), (znam * a.znam));
		rez.lowterms();
		return rez;
	}
	
	Fraction operator*(Fraction a)
	{
		Fraction rez((a.chisl * chisl), (znam * a.znam));
		rez.lowterms();
		return rez;
	}
	
	Fraction operator/(Fraction a)
	{
		Fraction rez((a.znam * chisl), (znam * a.chisl));
		rez.lowterms();
		return rez;
	}
	
	bool operator==(Fraction a)
	{
		a.lowterms();
		Fraction rez(chisl, znam);
		rez.lowterms();
		if ((rez.chisl == a.chisl) && (rez.znam == a.znam))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(Fraction a)
	{
		a.lowterms();
		Fraction rez(chisl, znam);
		rez.lowterms();
		if ((rez.chisl != a.chisl) || (rez.znam != a.znam))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void print_rez()
	{
		cout << "Rezult: " << chisl << '/' << znam;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	const Fraction ExitInput(0,1);
	Fraction EndFraction;

	do {
		cout << endl << "Чтобы закончить введите 0/1" << endl;

		char dummy_char;
		int z, x;
		cout << "Введите первую дробь: ";
		cin >> z >> dummy_char >> x;
		Fraction a(z, x);
		if (a == ExitInput)
		{
			break;
		}

		cout << "Введите вторую дробь: ";
		cin >> z >> dummy_char >> x;
		Fraction b(z, x);
		if (b == ExitInput)
		{
			break;
		}

		char oper;
		float mult;
		Fraction rez;
		cout << "Введите опреатор: ";
		{
			cin >> oper;
		}

		switch (oper)
		{
		case '+':
			rez = a + b;
			break;
		case '-':
			rez = a - b;
			break;
		case '*':
			rez = a * b;
			break;
		case '/':
			rez = a / b;
		}

		rez.print_rez();

	} while (1 > 0);

	return 0;
}
