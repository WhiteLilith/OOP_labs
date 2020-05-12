#1
#include <iostream>
#include <cstring>
using namespace std;

void reversit(char a[])
{
	int len = strlen(a);
	for (int i = 0; i < len / 2; i++)
	{
		char bus = a[i];
		a[i] = a[len - i - 1];
		a[len - i - 1] = bus;
	}
}

int main()
{
    const int MAX = 80;
	char str[MAX];
	cout << "Input stroku: ";
	cin.get(str, MAX);
	reversit(str);
	cout << "Reversed stroka: " << str;
	return 0;
}








#2
#include <iostream>
#include <string>

using namespace std;

class employee 
{
private:
	string name;
	long number;
public:
	void getdata()
	{
		cout << "Input name: ";
		cin >> this->name;
		cout << "Input number: ";
		cin >> this->number;
	}
	void putdata()
	{
		cout << "Employee #" << this->number << ", name: " << this->name << endl;
	}
};

int main()
{
	employee arr[100];
	bool cont = 1;
	int i = 0;
	do
	{
		cont = 0;
		cout << "Input data of the next employee\n";
		arr[i].getdata();
		cout << "Want to continue(y/n)? ";
		char c;
		cin >> c;
		if (c == 'y')
		{
			cont = 1;
			i++;
		}
	} while (cont && i < 100);
	for (int j = 0; j <= i; j++)
	{
		arr[j].putdata();
	}
	return 0;
}





#3
#include <iostream>

using namespace std;

class Distance
{
private:
	int feet;
	float inches;
public:
	Distance()
	{
		this->feet = 0;
		this->inches = 0;
	}
	Distance(int ft, float in)
	{
		this->feet = ft;
		this->inches = in;
	}
	void add_dist(Distance d1, Distance d2)
	{
		this->inches = d1.inches + d2.inches;
		this->feet = 0;
		if (this->inches >= 12)
		{
			this->inches -= 12;
			this->feet++;
		}
		this->feet += d1.feet + d2.feet;
	}
	void div_dist(Distance d, int divisor)
	{
		float fltfeet = d.feet + d.inches / 12.0;
		fltfeet /= divisor;
		this->feet = (int)fltfeet;
		this->inches = (fltfeet - this->feet) * 12.0;
	}
	void getdist()
	{
		cout << "Input feet: ";
		cin >> this->feet;
		cout << "Input inches: ";
		cin >> this->inches;
	}
	void showdist()
	{
		cout << this->feet << " feet and " << this->inches << "inches" << endl;
	}
};


int main()
{
	Distance distarr[100];
	Distance total(0, 0.0), average;
	int count = 0;
	char c;
	do {
		cout << "Input distance: ";
		distarr[count++].getdist();
		cout << "Continue (y/n)? ";
		cin >> c;
	} while (c != 'n');
	for (int i = 0; i < count; i++)
	{
		total.add_dist(total, distarr[i]);
	}
	average.div_dist(total, count);
	cout << "Srednee: ";
	average.showdist();
}


#4
#include <iostream>
#include <limits.h>

using namespace std;

int maxint(int a[], int count)
{
	int max = INT_MIN;
	int max_num;
	for (int i = 0; i < count; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			max_num = i;
		}
	}
	return max_num;
}



int main()
{
	cout << "Input count of elements: ";
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int a = maxint(arr, n);
	cout << "The biggest element is " << arr[a]
		<< " and it's number is " << a;
	return 0;
}

#5
#include <iostream>

using namespace std;

class fraction
{
public:
	int chisl;
	int znam;

	fraction(int a, int b)
	{
		chisl = a;
		znam = b;
	}
	fraction()
	{
		chisl = 1;
		znam = 1;
	}
	void Input_Data(int a, int b)
	{
		this->chisl = a;
		this->znam = b;
	}
	void print_rez()
	{
		cout << "Rezult: " << chisl << '/' << znam;
	}
};

int main()
{
	cout << "Input size of array: ";
	int size;
	char dummy_char;
	cin >> size;
	fraction *arr = new fraction[size];
	cout << "Input array: ";
	int biggest_znam = 1;
	int sum_of_chisl = 0;
	for (int i = 0; i < size; i++)
	{
		int a, b;
		cin >> a >> dummy_char >> b;
		arr[i].Input_Data(a, b);
		biggest_znam *= b;
	}
	for (int i = 0; i < size; i++)
	{
		sum_of_chisl = sum_of_chisl + arr[i].chisl * (biggest_znam/arr[i].znam);
	}
	sum_of_chisl;
	biggest_znam *= size;
	fraction result(sum_of_chisl, biggest_znam);
	cout << "The middle value is: ";
	result.print_rez();
}
*/

// №6 
#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;

enum Suit { clubs, diamonds, hearts, spades };

const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;
const int ACE = 14;

class Card
{
private:
	int number;
	Suit suit;

public:
	Card()
	{
		number = 0;
		suit = clubs;
	}

	void Set(int n, Suit s)
	{
		suit = s;
		number = n;
	}

	void Display()
	{
		if (number >= 2 && number <= 10)
		{
			cout << number;
		}
		else 
		{
			switch (number)
			{
			case JACK: cout << "Jack";
				break;
			case QUEEN: cout << "Queen";
				break;
			case KING: cout << "King";
				break;
			case ACE: cout << "Ace";
				break;
			}
		}

		switch (suit)
		{
			case clubs: cout << " clubs,"; 
				break;
			case diamonds: cout << " diamonds,"; 
				break;
			case hearts: cout << " hearts,"; 
				break;
			case spades: cout << " spades,"; 
				break;
		}
	}
};


int main()
{
	Card deck[52];

	for (int i = 0; i < 52; i++)
	{
		int n = (i % 13) + 2;
		Suit s = Suit(i / 13);
		deck[i].Set(n, s);
	}

	cout << "Begin deck: " << endl;

	for (int i = 0; i < 52; i++)
	{
		deck[i].Display();
		cout << " ";
		if (!((i + 1) % 13))
		{
			cout << endl;
		}
	}

	srand(time(NULL));
	for (int i = 0; i < 52; i++)
	{
		int k = rand() % 52;
		Card temp = deck[i];
		deck[i] = deck[k];
		deck[k] = temp;
	}

	cout << "Mixed deck: " << endl;
	for (int i = 0; i < 52; i++)
	{
		deck[i].Display();
		cout << " ";
		if (!((i + 1) % 13))
		{
			cout << endl;
		}
	}

	return 0;
}


//#7
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Money
{
private:
	const char dollar = '$';
	long double value;
	string money;
	string digits = "0123456789";
public:

	bool Find(char c, string s)
	{
		bool result = false;
		for (int i = 0; i < s.length(); i++)
		{
			if (c == s[i])
			{
				result = true;
			}
		}
		return result;
	}

	 void mstold(string s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			char c = s[i];
			if (Find(c, digits))
			{
				money.push_back(c);
			}
		}

		char* numbersCh = new char[money.length() + 1];
		strncpy(numbersCh, money.c_str(), money.length());

		this->value = atof(numbersCh);
		this->value /= 100;
	}

	 void print()
	 {
		 cout << dollar << " " << value;
	 }
};

int main()
{
	Money mon;
	cout << "Input neede value: ";
	string s;
	cin >> s;
	mon.mstold(s);
	mon.print();
}
