class Safearray

{

private:
	int arr[LIMIT];

public:

	int begin_index;
	int end_index;

	Safearray() 
	{
		begin_index = 0;
		end_index = 100;
	};

	Safearray(int a, int b)
	{
		if (a - b > 100)
		{
			cout << "ERROR, too big size" << endl;
		}
		else
		{
			a %= 100;
			b %= 100;
			begin_index = a;
			end_index = b;
		}
	}

	int& operator [](int n) //note: return by reference
	{
		if (n < begin_index || n >= end_index + 1)
		{
			cout << "\nIndex out of bounds"; exit(1);
		}
		return arr[n];
	}

};

////////////////////////////////////////////////////////////////

int main()
{
	int left_boundary, right_boundary;
	cout << "Input boundaries of the array: " << endl;
	cin >> left_boundary >> right_boundary;

	Safearray sa1(left_boundary, right_boundary);

	for (int j = sa1.begin_index; j <= sa1.end_index; j++) //insert elements
	{
		sa1[j] = j * 10; //*left* side of equal sign
	}

	for (int j = sa1.begin_index; j <= sa1.end_index; j++) //display elements
	{
		int temp = sa1[j]; //*right* side of equal sign
		cout << "Element " << j << " is " << temp << endl;
	}

	return 0;
}
