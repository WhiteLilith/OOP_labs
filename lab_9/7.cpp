#include <iostream>
#include <string> //for string class
#include <stdio.h>
#include <iomanip>

using namespace std;

////////////////////////////////////////////////////////////////

class Person //class of persons
{
protected:
	string name; //person's name
	float salary;

public:
	void setData() //set data
	{
		cout << endl << "Enter name: ";
		cin >> name;

		cout << "Enter salary: ";
		cin >> salary;
	}

	void printData() //display data
	{
		cout << endl << "Name: " << name << endl;
		cout << "Salary: " << salary << endl;
	}

	string GetName() //return the name
	{
		return name;
	}

	float GetSalary() //return the salary
	{
		return salary;
	}

};

void quickSort(Person *personArray[], int beg, int end)
{
	if (beg < end)
	{
		int l = beg;
		int r = end;
		float baza = personArray[(l + r) / 2].GetSalary();
		Person bus;

		do
		{
			while (personArray[l].GetSalary() < baza)
			{
				l++;
			}

			while (personArray[r].GetSalary() > baza)
			{
				r--;
			}

			if (l <= r)
			{
				bus = personArray[l];
				personArray[l] = personArray[r];
				personArray[r] = bus;
				l++;
				r--;
			}

		} while (l <= r);

		quickSort(personArray, beg, r);
		quickSort(personArray, l, end);

	}
}


void order(person** pp1, person** pp2) //orders two pointers

{ //if 1st larger than 2nd,

	if ((*pp1)->getName() > (*pp2)->getName())

	{

		person* tempptr = *pp1; //swap the pointers

		*pp1 = *pp2;

		*pp2 = tempptr;

	}

}

////////////////////////////////////////////////////////////////

int main()

{
	Person* persPtr[100]; //array of pointers to persons
	int n = 0; //number of persons in array
	char choice; //input char

	do { //put persons in array

		persPtr[n] = new Person; //make new object

		persPtr[n]->setData(); //set person's data

		n++; //count new person

		cout << "Enter another (y/n)? "; //enter another

		cin >> choice; // person?

	} while (choice == 'y'); //quit on 'n'

	cout << "\nUnsorted list:";

	for (int j = 0; j < n; j++) //print unsorted list

	{
		persPtr[j]->printData();
	}

	quickSort(persPtr, 0, n);

	cout << "\nSorted list:";

	for (int j = 0; j < n; j++) //print sorted list

	{
		persPtr[j]->printData();
	}

	cout << endl;

	return 0;

}

//#include <iostream>
//
//#include <string> //for string class
//
//using namespace std;
//
//////////////////////////////////////////////////////////////////
//
//class person //class of persons
//
//{
//
//protected:
//
//	string name; //person's name
//
//public:
//
//	void setName() //set the name
//
//	{
//		cout << "Enter name: "; cin >> name;
//	}
//
//	void printName() //display the name
//
//	{
//		cout << endl << name;
//	}
//
//	string getName() //return the name
//
//	{
//		return name;
//	}
//
//};
//
//////////////////////////////////////////////////////////////////
//
//int main()
//
//{
//
//	void bsort(person**, int); //prototype
//
//	person* persPtr[100]; //array of pointers to persons
//
//	int n = 0; //number of persons in array
//
//	char choice; //input char
//
//	do { //put persons in array
//
//		persPtr[n] = new person; //make new object
//
//		persPtr[n]->setName(); //set person's name
//
//		n++; //count new person
//
//		cout << "Enter another (y/n)? "; //enter another
//
//		cin >> choice; // person?
//
//	}
//
//	while (choice == 'y'); //quit on 'n'
//
//	cout << "\nUnsorted list:";
//
//	for (int j = 0; j < n; j++) //print unsorted list
//
//	{
//		persPtr[j]->printName();
//	}
//
//	bsort(persPtr, n); //sort pointers
//
//	cout << "\nSorted list:";
//
//	for (j = 0; j < n; j++) //print sorted list
//
//	{
//		persPtr[j]->printName();
//	}
//
//	cout << endl;
//
//	return 0;
//
//} //end main()
//
////--------------------------------------------------------------
//
//void bsort(person** pp, int n) //sort pointers to persons
//
//{
//
//	void order(person**, person**); //prototype
//
//	int j, k; //indexes to array
//
//	for (j = 0; j < n - 1; j++) //outer loop
//
//		for (k = j + 1; k < n; k++) //inner loop starts at outer
//
//			order(pp + j, pp + k); //order the pointer contents
//
//}
//
////--------------------------------------------------------------
//
//void order(person** pp1, person** pp2) //orders two pointers
//
//{ //if 1st larger than 2nd,
//
//	if ((*pp1)->getName() > (*pp2)->getName())
//
//	{
//
//		person* tempptr = *pp1; //swap the pointers
//
//		*pp1 = *pp2;
//
//		*pp2 = tempptr;
//
//	}
//
//}
