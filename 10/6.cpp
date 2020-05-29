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
};

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

	long double experement_number = 123.98;

	bMoney experement_money(32421.90);

	cout << "/: " << experement_number / experement_money << endl;
	cout << "*: " << experement_number * experement_money << endl;

    return 0;
}
