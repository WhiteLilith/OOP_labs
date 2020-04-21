#include<iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Publication
{
private:
	string Name;
	float Price;
	
public:
	void GetData()
	{
		cout << "Input name of the book: ";
		getline(cin, Name);

		cout << "Input price of the book: ";
		cin >> Price;
	}

	void PutData()
	{
		cout << "Name: " << Name << endl;
		cout << "Price: " << Price << endl;
	}
};


class Book : public Publication
{
private:
	int Pages;

public:
	void GetData()
	{
		Publication::GetData();
		cout << "Input amount of pages of the paper book: ";
		cin >> Pages;
	}

	void PutData()
	{
		Publication::PutData();
		cout << "Pages: " << Pages;
	}
};


class Type : public Publication
{
private:
	float Length;

public:
	void GetData()
	{
		Publication::GetData();
		cout << "Input length of the audiobook: ";
		cin >> Length;
	}

	void PutData()
	{
		Publication::PutData();
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
