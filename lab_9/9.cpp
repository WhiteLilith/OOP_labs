#include <iostream>
#include <cstdlib>

using namespace std;

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
			(arrays[i]) = new int[SIZE];
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

void randomizeArray(int* a)
{
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand();
	}
}

int main()
{
	int a1[10], a2[10], a3[10], a4[10], a5[10], a6[10], a7[10], a8[10], a9[10], a10[10];

	randomizeArray(a1);
	randomizeArray(a2);
	randomizeArray(a3);
	randomizeArray(a4);
	randomizeArray(a5);
	randomizeArray(a6);
	randomizeArray(a7);
	randomizeArray(a8);
	randomizeArray(a9);
	randomizeArray(a10);

	brokenMemoryArray test(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
	test.printBrokenMemoryArray();

	return 0;
}
