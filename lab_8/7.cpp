#include<iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Counter
{
protected: //NOTE: not private
	unsigned int count; //count
public:
	Counter() : count(0) //constructor, no args
	{ }
	Counter(int c) : count(c) //constructor, one arg
	{ }
	unsigned int GetCount() const //return count
	{
		return count;
	}
	Counter operator ++ () //incr count (prefix)
	{
		return Counter(++count);
	}
};

class CountDn : public Counter
{
public:
	CountDn() : Counter() //constructor, no args
	{ }

	CountDn(int c) : Counter(c) //constructor, 1 arg
	{ }

	CountDn operator-- () // оператор уменьшения
	{
		return CountDn(--count);
	}
	CountDn operator++ (int) // оператор увеличения
	{
		return CountDn(count++);
	}
	CountDn operator-- (int) // оператор уменьшения
	{
		return CountDn(count--);
	}

	CountDn operator ++ ()
	{
		return Counter::count++;
	}

	unsigned int GetCount()
	{
		return Counter::GetCount();
	}


};

int main()
{
	CountDn a(10);

	++a;
	cout << a.GetCount() << endl;
	a++;
	cout << a.GetCount() << endl;
	a--;
	cout << a.GetCount() << endl;
	--a;
	cout << a.GetCount() << endl;
	return 0;
}
