#include<iostream>
#include <cstdlib>
#include <string>

using namespace std;
const int LIMIT = 100; //array size

class SafeArray
{
protected:
	int Array[LIMIT];

public:
	int& operator [](int n) //note: return by reference
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "\nIndex out of bounds"; exit(1);
		}
		return Array[n];
	}
};

class DeterminedSafeArray : SafeArray
{
public:
	int LowerIndex;
	int UpperIndex;

	int& operator [](int n)
	{
		if (n < LowerIndex || n > UpperIndex)
		{
			cout << "\nIndex out of bounds"; exit(1);
		}
		return Array[n % 100];
	}

	DeterminedSafeArray(int a, int b);
};

DeterminedSafeArray::DeterminedSafeArray(int a, int b)
{
	if (b - a >= LIMIT)
	{
		cout << "ERROR"; exit(1);
	}

	LowerIndex = a;
	UpperIndex = b;
}

int main()
{
	DeterminedSafeArray ExampleArray(245, 303);

	for (int i = 245; i <= 303; i++)
	{
		ExampleArray[i] = i * 10;
		cout << "Number " << i << " element is " << ExampleArray[i] << endl;
	}

	return 0;
}
