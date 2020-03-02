#include <iostream>
#include <string>

using namespace std;

class angle
{
private:
	int grad;
	float min;
	char direction;
public:
	angle(int a, float b, char c)
	{
		this->grad = a;
		this->min = b;
		this->direction = c;
	}
	void getangle()
	{
		cout << "Input graduses: ";
		cin >> grad;
		cout << "Input minutes: ";
		cin >> min;
		cout << "Input direction: ";
		cin >> direction;
	}
	angle();
	void showangle()
	{
		cout << grad << '\xF8' << min << "\'" << direction;
	}
};

void mainQ()
{
	bool cont = 1;
	do
	{
		cont = 0;
		int grad;
		float min;
		char direction;
		cout << "Input graduses: ";
		cin >> grad;
		cout << "Input minutes: ";
		cin >> min;
		cout << "Input direction: ";
		cin >> direction;
		angle ang(grad, min, direction);
		ang.showangle();
		cout << endl << "Do you want to continue(y/n)? ";
		char c;
		cin >> c;
		if (c == 'y')
		{
			cont = 1;
		}
	} while (cont);
}


int main()
{
	mainQ();
	
	return 0;
}
