#include<iostream>
#include <cstdlib>
#include <string>

using namespace std;

const int LEN = 80; //maximum length of names

class Employee //employee class

{
private:
	char Name[LEN]; //employee name
	unsigned long Number; //employee number
	double Compensation;
	enum Period {hourly, weekly, monthly};
	Period Jojo;

public:
	void GetData()
	{
		cout << "\nEnter last name: "; cin >> Name;
		cout << "\nEnter number: "; cin >> Number;
		cout << "\nHow much do you pay to this person? "; cin >> Compensation;
		cout << "For what period of time do you pay to this human? (h/w/m): ";
		char Dio;
		cin >> Dio;
		if (Dio == 'h')
		{
			Jojo = hourly;
		}
		else if (Dio == 'w')
		{
			Jojo = weekly;
		}
		else
		{
			Jojo = monthly;
		}

	}

	void PutData() const
	{
		cout << "\n Name: " << Name;
		cout << "\n Number: " << Number;
		string Dario;
		if (Jojo == hourly)
		{
			Dario = "per hour";
		}
		else if (Jojo == weekly)
		{
			Dario = "per week";
		}
		else
		{
			Dario = "Per month";
		}
		cout << "\n Payment " << Dario << ": " << Compensation << endl;
	}
};

int main()
{
	Employee person;

	person.GetData();
	person.PutData();

	return 0;
}
