#include <iostream>

using namespace std;

float power(float n, int p = 2)
{
	if (p == 1)
	{
		return n;
	}
	else
	{
		n = n * power(n, p - 1);
	}
	return n;
}

double power(double n, int p = 2)
{
	if (p == 1)
	{
		return n;
	}
	else
	{
		n = n * power(n, p - 1);
	}
	return n;
}

int power(int n, int p = 2)
{
	if (p == 1)
	{
		return n;
	}
	else
	{
		n = n * power(n, p - 1);
	}
	return n;
}

char power(char n, int p = 2)
{
	if (p == 1)
	{
		return n;
	}
	else
	{
		n = n * power(n, p - 1);
	}
	return n;
}

long power(long n, int p = 2)
{
	if (p == 1)
	{
		return n;
	}
	else
	{
		n = n * power(n, p - 1);
	}
	return n;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double number, answer;
	int pow;
	char userResponse;
	cout << "\nведите число:";
	cin >> number;
	cout << "Будете вводить степень (y/n)?";
	cin >> userResponse;
	if (userResponse == 'y ')
	{
		cout << "Введите степень:";
		cin >> pow;
		answer = power(number, pow);
		cout << "ответ " << answer << endl;

		answer = power((int)number, pow);
		cout << "\nответ " << answer << endl;

		answer = power((long)number, pow);
		cout << "\nответ " << answer << endl;

		answer = power((char)((int)number), pow);
		cout << "\nответ " << answer << endl;
	}
	else
	{
		answer = power(number);
		cout << "ответ " << answer << endl;

		answer = power((int)number);
		cout << "\nответ " << answer << endl;

		answer = power((long)number);
		cout << "\nответ " << answer << endl;

		answer = power((char)number);
		cout << "\nответ " << answer << endl;
	}
	return 0;
}
