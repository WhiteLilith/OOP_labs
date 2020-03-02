#include <iostream>

using namespace std;

class angle
{
private:
	int grad;
	float min;
	char direction;
public:
	angle();
	angle(int a, float b, char c)
	{
		this->grad = a;
		this->min = b;
		this->direction = c;
	}
	void getangle()
	{
		cout << "Input graduses: ";
		cin >> this->grad;
		cout << "Input minutes: ";
		cin >> this->min;
		cout << "Input direction: ";
		cin >> this->direction;
	}
	angle();
	void showangle()
	{
		cout << grad << '\xF8' << min << "\'" << direction << endl;
	}
};

class ship
{
private:
	int n;
	angle ang1;
	angle ang2;
public:
	static int number;
	ship()
	{
		n = ++number;
	}
	
	void getinfo()
	{
		this->ang1.getangle();
		this->ang2.getangle();
	}
	void showinfo()
	{
		cout << "My number: " << n << endl;
		this->ang1.showangle();
		this->ang2.showangle();
	}
};

int ship::number = 0;

void mainQ()
{
	ship a[3];
	for (int i = 0; i < 3; i++)
	{
		a[i].getinfo();
	}
	for (int i = 0; i < 3; i++)
	{
		a[i].showinfo();
	}
}

int main()
{	
	mainQ();
	return 0;
}
