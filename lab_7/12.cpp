#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>
#include <math.h>

using namespace std;

class Sterling
{
private:
	long pounds;
	int shillings;
	int penny;

	double decimalPounds;

	void ConvertFromDecimalToOldPounds()
	{
		double pennyTemp, temp1, temp2;

		penny = decimalPounds * 240;
		pounds = static_cast<long>(decimalPounds);
		pennyTemp = pounds * 240;
		temp1 = penny - pennyTemp;
		temp1 = static_cast<int>(temp1);
		shillings = temp1 / 12;
		shillings = static_cast<int>(shillings);
		temp2 = shillings * 12;
		penny = temp1 - temp2;
	}

	void ConvertFromOldToDecimalPounds()
	{
		decimalPounds = pounds + (penny / 12 + shillings) / 20;
	}

public:
	Sterling() : pounds(0), shillings(0), penny(0), decimalPounds(0.0)
	{}

	Sterling(double decimalPounds) :pounds(0), shillings(0), penny(0), decimalPounds(decimalPounds)
	{
		ConvertFromDecimalToOldPounds();
	}

	Sterling(long pounds, int shillings, int penny) : pounds(pounds), shillings(shillings), penny(penny), decimalPounds(0.0)
	{
		ConvertFromOldToDecimalPounds();
	}

	void DisplaySterling()
	{
		cout << "\n" << pounds << "." << shillings << "." << penny << "\n";
	}

	double GetDecimalPounds() const
	{
		return decimalPounds;
	}

	void GetSterling()
	{
		cout << "Input the amount of pounds: ";
		cin >> pounds;
		cout << "Input the amount of shillings: ";
		cin >> shillings;
		cout << "Input the amount of penny: ";
		cin >> shillings;
	}

	Sterling operator+(Sterling s)
	{
		double newDecimalPounds = decimalPounds + s.decimalPounds;
		return Sterling(newDecimalPounds);
	}

	Sterling operator-(Sterling s)
	{
		double newDecimalPounds = decimalPounds - s.decimalPounds;
		return Sterling(newDecimalPounds);
	}

	Sterling operator/(Sterling s)
	{
		double newDecimalPounds = decimalPounds / s.decimalPounds;
		return Sterling(newDecimalPounds);
	}

	Sterling operator*(double d)
	{
		double newDecimalPounds = decimalPounds * d;
		return Sterling(newDecimalPounds);
	}

	Sterling operator/(double d)
	{
		double newDecimalPounds = decimalPounds / d;
		return Sterling(newDecimalPounds);
	}

	operator double()
	{
		double Result =  pounds + (penny / 12 + shillings) / 20;
		return Result;
	}

};

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

	void GetMoney()
	{
		cout << "Input the amount of money: ";
		cin >> Value;
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



	operator long double()
	{
		return Value;
	}


	void PutMoney()

	{
		cout << ldtoms();
	}

	void PrintValue()
	{
		cout << Value;
	}

	operator Sterling const()
	{
		return Sterling(Value / 50);
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	bool Cont = true;
	
	do
	{
		Cont = false;

		bMoney AmountToConvert;
		Sterling ConvertedAmount;

		AmountToConvert.GetMoney();
		ConvertedAmount = AmountToConvert;
		ConvertedAmount.DisplaySterling();


		cout << "Do you want to continue? (y/n): ";
		char ContChar;
		cin >> ContChar;
		if (ContChar == 'y')
		{
			Cont = true;
		}

	} while (Cont);


	return 0;
}
