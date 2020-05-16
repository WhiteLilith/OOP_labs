#include <iostream>

using namespace std;

void AddArrays(float* result_array, float* first_summing_array, float* second_summing_srray, int size)
{
	for (int i = 0; i < size; i++)
	{
		result_array[i] = first_summing_array[i] + second_summing_srray[i];
	}
}

int main()
{
	const int SIZE = 8;
	float first_array[SIZE];

	int b = 0;
	for (int i = 0; i < SIZE; i++)
	{
		*(first_array + b++) = i * 2;
	}

	int size = SIZE;
	float* second_array = new float[size];

	for (int i = 0; i < SIZE; i++)
	{
		second_array[i] = i * i;
	}

	float final_array[SIZE];

	AddArrays(final_array, first_array, second_array, SIZE);

	b = 0;
	for (int i = 0; i < SIZE; i++)
	{
		cout << *(final_array + b++) << " ";
	}

	return 0;
}
