#include <iostream>

using namespace std;

int CompStr(char* first_string, char* second_string)
{
	if (strlen(first_string) > strlen(second_string))
	{
		return 1;
	}
	else if (strlen(first_string) > strlen(second_string))
	{
		return -1;
	}

	int *len = new int(strlen(first_string));
	int* i = new int(0);

	int* first_counter = new int(0);
	int* second_counter = new int(0);

	for (*i = 0; *i < *len; *i++)
	{
		if ((int)*(first_string + *first_counter) > (int)*(second_string + *second_counter))
		{
			return -1;
		}
		else if ((int)*(first_string + *first_counter) < (int)*(second_string + *second_counter))
		{
			return 1;
		}

		*first_counter += 1;
		*second_counter += 1;

	}

	return 0;
}


int main()
{
	char string_1[] = "Hello";
	char string_2[] = "Hello";
	char string_3[] = "Hjllo";

	cout << CompStr(string_1, string_2) << endl;
	cout << CompStr(string_2, string_3) << endl;
	cout << CompStr(string_3, string_2) << endl;
}
