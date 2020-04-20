#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Time

{

private:

	int hrs, mins, secs;

	void Check()
	{
		while (secs >= 60)
		{
			secs -= 60;
			mins++;
		}
		while (mins >= 60)
		{
			mins -= 60;
			hrs++;
		}

		while (secs < 0)
		{
			secs += 60;
			mins--;
		}
		while (mins < 0)
		{
			mins += 60;
			hrs--;
		}
	}

public:

	Time() : hrs(0), mins(0), secs(0)
	{ } 

	Time(int h, int m, int s)
	{ 
		hrs = h;
		mins = m;
		secs = s;
	}

	void display() 

	{
		cout << hrs << ":" << mins << ":" << secs;
	}

	Time operator -(Time t)
	{
		Time rez(hrs - t.hrs, mins - t.mins, secs - t.secs);
		rez.Check();
		return rez;
	}

	Time& operator++()
	{
		Time rez(hrs, mins, ++secs);
		rez.Check();
		return(rez);
	}
	Time operator++(int)
	{
		Time rez(hrs, mins, secs++);
		rez.Check();
		return rez;
	}

	Time& operator--()
	{
		Time rez(hrs, mins, --secs);
		rez.Check();
		return rez;
	}

	Time operator--(int)
	{
		Time rez(hrs, mins, secs--);
		rez.Check();
		return rez;
	}

	Time operator*(float a)
	{
		Time rez(hrs * a, mins * a, secs * a);
		rez.Check();
		return rez;
	}

};

int main()
{
	Time a(7, 2, 9);
	Time b(5, 1, 4);
	Time result;
	float multiplicator = 2;

	cout << "a = ";
	a.display();
	cout << endl;
	cout << "b = ";
	b.display();
	cout << endl;

	result = a - b;
	cout << "a - b = ";
	result.display();
	cout << endl;

	result = result * multiplicator;
	cout << "(a - b) * 2 = ";
	result.display();
}
