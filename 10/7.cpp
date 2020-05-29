#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

class bMoney
{
private:
	char Dollar = '$';
	long double Value;
	string Ustring;
	string money;
	string digits = "0123456789";
	long double Max = 9999999999999990.00;

public:

	bMoney(long double a)
	{
		if (a <= Max)
		{
			Value = a;
		}
		else
		{
			cout << "ERROR, too big value";
		}
	}

	bMoney()
	{}

	bMoney(char s[])
	{
		mstold(s);
	}

	bMoney(string s)
	{
		mstold(s);
	}

	bool Find(char c, string s)
	{
		bool result = false;
		for (int i = 0; i < s.length(); i++)
		{
			if (c == s[i])
			{
				result = true;
			}
		}
		return result;
	}

	void mstold(string s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			char c = s[i];
			if (Find(c, digits))
			{
				money.push_back(c);
			}
		}

		char* numbersCh = new char[money.length() + 1];
		strncpy(numbersCh, money.c_str(), money.length());

		Value = atof(numbersCh);
		Value /= 100;
	}

	string ldtoms()
	{
		string uresult;
		string result;
		uresult = to_string(Value);
		int len = uresult.length();
		for (int i = len - 1; i >= 0; i--)
		{
			result = uresult[i] + result;
			if (i % 3 == 0 && (i > 2))
			{
				result = " " + result;
			}

		}

		result = Dollar + result;
		Ustring = result;
		return result;
	}

	bMoney operator+(bMoney a)
	{
		bMoney rez(a.Value + Value);
		return rez;
	}

	bMoney operator-(bMoney a)
	{
		bMoney rez(Value - a.Value);
		return rez;
	}

	bMoney operator*(long double a)
	{
		bMoney rez(Value * a);
		return rez;
	}

	bMoney operator/(long double a)
	{
		bMoney rez(Value / a);
		return rez;
	}

	long double operator/(bMoney a)
	{
		long double rez = Value / a.Value;
		return rez;
	}

	friend bMoney operator*(long double, bMoney);

	friend bMoney operator/(long double, bMoney);

	operator long double()
	{
		return Value;
	}

	void getmoney()
	{
		cout << "Input the amount of money: ";
		cin >> Value;
	}

	void putmoney()

	{
		cout << ldtoms();
	}

	void print_value()
	{
		cout << Value;
	}

	bMoney round(bMoney);

};

bMoney bMoney::round(bMoney money)
{
	long double integer_part;
	long double fractional_part;

	fractional_part = modfl(money.Value, &integer_part);

	if (fractional_part >= 0.5)
	{
		Value = integer_part + 1;
		return *this;
	}
	else
	{
		Value = integer_part;
		return *this;
	}
}

bMoney operator*(long double a, bMoney object)
{
	return bMoney(a * object.Value);
}

bMoney operator/(long double a, bMoney object)
{
	return bMoney(a / object.Value);
}

int main()
{
    setlocale(LC_ALL, "Russian");

	bMoney non_integer_up = 1234.78;
	bMoney non_integer_down = 1234.34598;
	bMoney integer_value;

	integer_value = round(non_integer_up);
	cout << "Rounding up: ";
	integer_value.print_value();
	cout << endl;

	integer_value = round(non_integer_down);
	cout << "Rounding down: ";
	integer_value.print_value();
	cout << endl;

    return 0;
}
