#include <iostream>

using namespace std;

struct Sterling
{
	int pounds;
	int shillings;
	int penny;
};

Sterling gett()
{
	Sterling a;
	cout << "VVedite summu v funtah(F, S, P) ";
	cin >> a.pounds >> a.shillings >> a.penny;
	return a;
}

Sterling sum(Sterling a, Sterling b)
{
	Sterling c;

	c.penny = 0;
	c.shillings = 0;
	c.pounds = 0;

	c.penny = a.penny + b.penny;
	if (c.penny > 11)
	{
		c.shillings++;
		c.penny -= 12;
	}

	c.shillings = c.shillings + a.shillings + b.shillings;
	if (c.shillings > 19)
	{
		c.pounds++;
		c.shillings -= 20;
	}

	c.pounds = c.pounds + a.pounds + b.pounds;

	return c;
}

void print(Sterling a)
{
	cout << a.pounds << " funtov, " << a.shillings << " shillingov, " << a.penny << " pensov" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Sterling a, b, rez;
	a = gett();
	b = gett();
	rez = sum(a, b);
	cout << "Rezultat slogenia: ";
	print(rez);
	return 0;
}
