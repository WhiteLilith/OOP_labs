#include<iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Publication
{
protected:
	string Name;
	float Price;

public:
	void GetData()
	{
		cout << "Input name of the book: ";
		cin >> Name;

		cout << "Input price of the book: ";
		cin >> Price;
	}

	void PutData()
	{
		cout << "Name: " << Name << endl;
		cout << "Price: " << Price << endl;
	}
};

class Sales
{
protected:
	const static int Months = 3;
	float SalesArray[Months];

public:
	void GetData();
	void PutData();
};

void Sales::GetData()
{
	cout << " Enter sales for 3 months\n";
	for (int j = 0; j < Months; j++)
	{
		cout << " Month " << j + 1 << ": ";
		cin >> SalesArray[j];
	}

}

void Sales::PutData()
{
	for (int j = 0; j < Months; j++)
	{
		cout << "\n Sales for month " << j + 1 << ": ";
		cout << SalesArray[j];
	}
}



class Book : public Publication, public Sales
{
private:
	int Pages;

public:
	void GetData()
	{
		Publication::GetData();
		cout << "Input amount of pages of the paper book: ";
		cin >> Pages;
		Sales::GetData();
	}

	void PutData()
	{
		Publication::PutData();
		cout << "Pages: " << Pages;
		Sales::PutData();
		cout << endl;
	}
};


class Type : public Publication, public Sales
{
private:
	float Length;

public:
	void GetData()
	{
		Publication::GetData();
		cout << "Input length of the audiobook: ";
		cin >> Length;
		Sales::GetData();
	}

	void PutData()
	{
		Publication::PutData();
		cout<< "Length: " << Length;
		Sales::PutData();
		cout << endl;
	}
};


int main()
{
	Type AudioBook;
	Book PaperBook;

	AudioBook.GetData();
	cout << endl;
	PaperBook.GetData();
	cout << endl;
	AudioBook.PutData();
	cout << endl;
	PaperBook.PutData();

	return 0;
}
