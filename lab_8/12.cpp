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
		double pennyTemp, bus1, bus2;

		penny = decimalPounds * 240;
		pounds = static_cast<long>(decimalPounds);

		pennyTemp = pounds * 240;
		bus1 = penny - pennyTemp;
		bus1 = static_cast<int>(bus1);

		shillings = bus1 / 12;
		shillings = static_cast<int>(shillings);

		bus2 = shillings * 12;
		penny = bus1 - bus2;
	}

	void ConvertFromOldToDecimalPounds()
	{
		decimalPounds = pounds + (penny / 12 + shillings) / 20;
	}

public:
	Sterling() : pounds(0), shillings(0), penny(0), decimalPounds(0)
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


class Sterfac : public Sterling
{
private:
	int eights;

public:
	Sterfac() : Sterling(), eights(0)
	{ }

	Sterfac(double decimalPounds) : Sterling(decimalPounds), eights(0)
	{ }

	Sterfac(long pounds, int shillings, int penny, int eight) : Sterling(pounds, shillings, penny + eights / 8)
	{
		eights = eight;
	}

	void DisplaySterling()
	{
		cout << "\n" << pounds << "." << shillings << "." << penny << "-" 
			 << eights << "/8" << endl;
	}

	void PutSterlingOld()
	{
		cout << "\nEnter sterling in old system: ";
		char dummychar;
		cin >> pounds >> dummychar >> shillings >> dummychar 
			>> penny >> dummychar >> eights >> dummychar >> dummychar;
		ConvertFromOldToDecimalPounds();
	}

	double GetDecimalPounds() const
	{
		return decimalPounds;
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
