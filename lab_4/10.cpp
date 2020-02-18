#include <iostream>

using namespace std;

void func(int a)
{
	cout << "функция вызвалась " << counter << " раз\n";
	if (a < 10)
	{
		func(++counter);
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	func(0);
}
