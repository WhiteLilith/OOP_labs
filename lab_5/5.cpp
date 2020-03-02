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
		cout <<"The date is " << day << "/" << month << "/" << year << endl;
	}
};

int main()
{
	string str;
	cout << "Input date: " << endl;
	cin >> str;
	date date1;
	date1.getdate(str);
	date1.showdate();
	return 0;
}
