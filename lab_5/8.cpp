#include <iostream>

using namespace std;

class counter
{
private:
	int n;
public:
	static int number;
	counter()
	{
		n = ++number;
	}
	void print()
	{
		cout << "Мой порядковый номер: " << n << endl;
	}
};

int counter::number = 0;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	counter a[3];
	for (int i = 0; i < 3; i++)
	{
		a[i].print();
	}

	return 0;
}
