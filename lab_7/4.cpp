#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Int
{
private:
	int i;

public:
	Int()
	{
		i = 0;
	}

	Int(int ii)
	{
		i = ii;
	}
	
	Int operator + (Int i1)
	{
		int a;
		a = i + i1.i;
		return a;
	}

	void display()
	{
		cout << i;
	}
};

int main()
{
	Int a(3);
	Int b(-10);
	Int c = a + b;
	c.display();
}
