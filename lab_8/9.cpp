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


class Publication2 : public Publication
{
protected:
	string Date;

public:
	void GetData1()
	{
	Publication::GetData();
		cout << "Input date of publication: ";
		cin >> Date;
	}

	void PutData()
	{
	Publication::PutData();
		cout << "Date of publication: " << Date << endl;
	}
};

class Book : public Publication2
{
private:
	int Pages;

public:
	void GetData()
	{
		Publication2::GetData1();
		cout << "Input amount of pages of the paper book: ";
		cin >> Pages;
	}

	void PutData()
	{
		Publication2::PutData();
		cout << "Pages: " << Pages;
	}
};


class Type : public Publication2
{
private:
	float Length;

public:
	void GetData()
	{
		Publication2::GetData1();
		cout << "Input length of the audiobook: ";
		cin >> Length;
	}

	void PutData()
	{
		Publication2::PutData();
		cout << "Length: " << Length;
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
