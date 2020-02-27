#include <iostream>

using namespace std;

class time
{
private:
	int sec;
	int hrs;
	int min;
public:
	time()
	{
		sec = 0;
		hrs = 0;
		min = 0;
	}
	time(int a, int b, int c)
	{
		sec = c;
		min = b;
		hrs = a;
	}
	void display()
	{
		cout << hrs << ":" << min << ":" << sec;
	}
	void add_time(time t1, time t2)
	{

		sec = t1.sec + t2.sec;
		if (sec > 59)
		{
			sec -= 60;
			min++;
		}
		min = min + t1.min + t2.min;
		if (min > 59)
		{
			min -= 60;
			hrs++;
		}
		hrs = hrs + t1.hrs + t2.hrs;
		if (hrs > 11)
		{
			hrs -= 12;
		}
	}
};

int main()
{
	const time time1(5, 59, 59);
	const time time2(4, 30, 30);
	time time3;
	time3.add_time(time1, time2);
	cout << "time3 = "; time3.display();
	cout << endl;
	return 0;
}
