#include <iostream>
#include <string>

using namespace std;

class date
{
private:
	int day;
	int month;
	int year;
public:
	void getdate(string str)
	{
		string str1, str2, str3;
		str1 = str.substr(0, 2);
		str2 = str.substr(3, 4);
		str3 = str.substr(6, 7);
		int a = stoi(str1);
		int b = stoi(str2);
		int c = stoi(str3);
		this -> day = a;
		this -> month = b;
		this -> year = c;
	}
	void showdate()
	{
		cout <<"The date of jobgetting: " << day << "/" << month << "/" << year << endl;
	}
};

enum etype { laborer, secretary, manager, accountant, executive, researcher };

class employee
{
private:
	int id;
	float salary;
	date dat;
	etype p;
public:
	void getemployee()
	{
		int a;
		float b;
		string str1;
		char c;

		cout << "Input ID: ";
		cin >> a;
		cout << "Input date: ";
		cin >> str1;
		cout << "Input salary: ";
		cin >> b;

		this -> id = a;
		this -> salary = b;
		this -> dat.getdate(str1);
		cout << "Введите первую букву должности: ";
		cin >> c;

		switch (c)
		{
			{
		case 'l':
			this -> p = laborer;
			break;
		case 's':
			this -> p = secretary;
			break;
		case 'm':
			this -> p = manager;
			break;
		case 'a':
			this -> p = accountant;
			break;
		case 'e':
			this -> p = executive;
			break;
		case 'r':
			this -> p = researcher;
			}
		}
	}
	void putemployee()
	{
		string str;

		switch (p)
		{
		case laborer:
			str = "laborer";
			break;
		case secretary:
			str = "secretary";
			break;
		case manager:
			str = "manager";
			break;
		case accountant:
			str = "accountant";
			break;
		case executive:
			str = "executive";
			break;
		case researcher:
			str = "researcher";
			break;
		}
		cout << "ID: " << id << ", salary: " << salary << endl;
		dat.showdate();
		cout << "Vacancy: " << str;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	employee emp;
	emp.getemployee();
	emp.putemployee();
	
	return 0;
}
