#include <iostream>

using namespace std;

class fraction
{
private:
	int chisl;
	int znam;
public:
	fraction();
	fraction(int a, int b)
	{
		this->chisl = a;
		this->znam = b;
	}
	void getfraction()
	{
		char dummy_char;
		cout << "Input fraction: ";
		cin >> this->chisl >> dummy_char >> this->znam;
	}
	void sum(fraction a, fraction b)
	{
		 this->chisl = a.chisl * b.znam + b.chisl * a.znam;
		 this->znam = a.znam * b.znam;
	}
	void print()
	{
		cout << this->chisl << '/' << this->znam;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	bool cont = 1;
	do
	{
		fraction a1(0, 0), a2(0, 0), rez(0, 0);
		a1.getfraction();
		a2.getfraction();
		rez.sum(a1, a2);
		cout << "Their sum: ";
		rez.print();
		char c;
		cont = 0;
		cout << endl << "Do you want to continue(y/n)? ";
		cin >> c;
		if (c == 'y')
		{
			cont = 1;
		}
	} while (cont);
	
	return 0;
}
