#include <iostream>

using namespace std;

class Sterling
{
protected:
	long pounds;
	int shillings;
	float penny;

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

	Sterling(long pounds, int shillings, float penny) : pounds(pounds), shillings(shillings), penny(penny), decimalPounds(0.0)
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
};

class Sterfac : Sterling
{
protected:
	int eights_numerator;
	int eights_denominator;

public:
	Sterfac() : Sterling(), eights_numerator(0), eights_denominator(1)
	{}

	Sterfac(double decimalPounds)
	{
		double pennyTemp, temp1, temp2;

		penny = decimalPounds * 240;
		eights_numerator = (int)((penny - (int)penny) * 1000) / 125;
		eights_denominator = 8;
		pounds = static_cast<long>(decimalPounds);
		pennyTemp = pounds * 240;
		temp1 = penny - pennyTemp;
		temp1 = static_cast<int>(temp1);
		shillings = temp1 / 12;
		shillings = static_cast<int>(shillings);
		temp2 = shillings * 12;
		penny = temp1 - temp2;
	}

	Sterfac(long pounds, int shillings, int penny, int eights_n, int eights_d) : Sterling(pounds, shillings, penny + eights_n / eights_d)
	{
		eights_numerator = eights_n;
		eights_denominator = eights_d;
	}

	void DisplaySterling()
	{
		cout << "\n" << pounds << "." << shillings << "." << penny << "-" << eights_numerator << "/" << eights_denominator << "\n";
	}

	void PutSterlingOld()
	{
		cout << "\nEnter sterling in old system: ";
		char dummychar;
		cin >> pounds >> dummychar >> shillings >> dummychar >> penny 
			>> dummychar >> eights_numerator >> dummychar >> eights_denominator;
	}

	Sterfac operator+ (Sterfac s)
	{
		double newDecimalPounds = decimalPounds + s.decimalPounds;
		return Sterfac(newDecimalPounds);
	}

	Sterfac operator- (Sterfac s)
	{
		double newDecimalPounds = decimalPounds - s.decimalPounds;
		return Sterfac(newDecimalPounds);
	}

	Sterfac operator* (double d)
	{
		double newDecimalPounds = decimalPounds * d;
		return Sterfac(newDecimalPounds);
	}

	Sterfac operator/ (double d)
	{
		double newDecimalPounds = decimalPounds / d;
		return Sterfac(newDecimalPounds);
	}
};

int main()
{
	Sterfac first;
	first.PutSterlingOld();
	
	double _input;
	cout << "Input Decimal sterlings: ";
	cin >> _input;

	Sterfac second(_input);

	Sterfac result = first - second;
	cout << "- : " << endl;
	result.DisplaySterling();

	cout << endl;
	result = first + second;
	cout << "+ : " << endl;
	result.DisplaySterling();

	cout << endl;
	result = first * 2;
	cout << "*2 : " << endl;
	result.DisplaySterling();

	cout << endl;
	result = first / 2;
	cout << "/2 : " << endl;
	result.DisplaySterling();

	return 0;
}
