#include <iostream>
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


int main()
{
	setlocale(LC_ALL, "Russian");
	Sterling sterling_1, sterling_2(1.56), sterling_3(1 , 2, 3);
	Sterling sterlingResult;

	sterlingResult = sterling_1 + sterling_2;
	sterlingResult.DisplaySterling();

	sterlingResult = sterlingResult * 3.0;
	cout << sterlingResult.GetDecimalPounds();
	sterlingResult.DisplaySterling();
}
