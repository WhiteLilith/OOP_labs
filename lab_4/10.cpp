#include <iostream>

using namespace std;
int counter = 0;

void func()
{
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
