#include <iostream>

using namespace std;


void func()
{
	static int counter = 0;
	setlocale(LC_ALL, "Russian");
	cout << "функция вызвалась " << counter << " раз\n";
	++counter;

}

int main()
{
	for (int i = 0; i < 11; i++)
	{
		func();
	}
}
