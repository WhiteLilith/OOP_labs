#include <iostream>
#include <cstdlib>

using namespace std;

const int SIZE_VALUE = 3;

class LinedArray
{
protected:
	static const int SIZE = SIZE_VALUE;
	int array[SIZE][SIZE];

public:
	LinedArray()
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				*(*(array + i) + j) = 0;
			}
		}
	}

	int& operator[](int index)
	{
		if (index > SIZE * SIZE)
		{
			cout << "ERROR";
			exit(1);
		}

		return *(*(array + index / SIZE) + index % SIZE);
	}
};

int main()
{
	LinedArray testing;

	for (int i = 0; i < SIZE_VALUE * SIZE_VALUE; i++)
	{
		testing[i] = rand();
	}

	for (int i = 0; i < SIZE_VALUE * SIZE_VALUE; i++)
	{
		cout << testing[i] << " ";
	}

	return 0;
}
