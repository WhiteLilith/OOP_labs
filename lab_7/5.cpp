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
		if (secs >= 60)
		{
			secs -= 60;
			mins++;
		}
		if (mins >= 60)
		{
			mins -= 60;
			hrs++;
		}

		if (secs < 0)
		{
			secs += 60;
			mins--;
		}
		if (mins < 0)
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

};

int main()
{
	Time a(7, 2, 9);

	a++.display();
	cout << endl;
	a.display();
	cout << endl;

	--a;
	a--;
	a.display();

}
