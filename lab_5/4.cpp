#include <iostream>

using namespace std;

class employee
{
private:
	int id;
	float salary;
public:
	employee(int a, float b)
	{
		id = a;
		salary = b;
	}
	void print()
	{
		cout << "ID: " << id << ", salary: " << salary << endl;
	}
};

int main()
{
	int a;
	float b;
	cout << "Input ID and salary: " << endl;
	cin >> a >> b;
	employee emp(a, b);
	emp.print();
}
