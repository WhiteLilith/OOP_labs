#include <iostream>
#include <cstdlib>

using namespace std;

void randomizeArray(int* a)
{
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand();
	}
}

class brokenMemoryArray
{
protected:
	static const int SIZE = 10;
	int* arrays[SIZE];

public:
	brokenMemoryArray()
	{
		for (int i = 0; i < SIZE; i++)
		{
			arrays[i] = new int[SIZE];
			randomizeArray(arrays[i]);
		}
	}

	brokenMemoryArray(int* a1, int* a2, int* a3, int* a4, int* a5, int* a6, int* a7, int* a8, int* a9, int* a10)
	{
		for (int i = 0; i < SIZE; i++)
		{
			(arrays[0]) = a1;
			(arrays[1]) = a2;
			(arrays[2]) = a3;
			(arrays[3]) = a4;
			(arrays[4]) = a5;
			(arrays[5]) = a6;
			(arrays[6]) = a7;
			(arrays[7]) = a8;
			(arrays[8]) = a9;
			(arrays[9]) = a10;
		}
	}

	void changeBrokenMemoryArrayElement(int number, int i, int j)
	{
		arrays[i][j] = number;
	}

	int getBrokenMemoryArrayElement(int i, int j)
	{
		return arrays[i][j];
	}

	void printBrokenMemoryArray()
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				cout << (arrays[i][j]) << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	brokenMemoryArray test;
	test.printBrokenMemoryArray();

	return 0;
}
