#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////

class Array                     //models a normal C++ array
{
private:
    int* ptr;                 //pointer to Array contents
    int size;                 //size of Array

public:

    Array()
    {
        size = 0;
        ptr = new int[0];
    }
    Array(int s)              //one-argument constructor
    {
        size = s;              //argument is size of Array
        ptr = new int[s];      //make space for Array
    }

    Array(Array& arr)
    {
        this->size = arr.size;
        ptr = new int[this->size];
        for (int i = 0; i < size; i++)
        {
            *(ptr + i) = arr[i];
        }
    }

    ~Array()                  //destructor
    {
        delete[] ptr;
    }

    int& operator [] (int j)  //overloaded subscript operator
    {
        return *(ptr + j);
    }

    Array operator =(Array& arr)
    {
        delete[] ptr;
        ptr = new int[arr.size];
        size = arr.size;
        for (int i = 0; i < arr.size; i++)
        {
            *(ptr + i) = arr[i];
        }
        return *this;
    }

};

////////////////////////////////////////////////////////////////

int main()

{

    const int ASIZE = 4;        //size of array

    Array arr1(ASIZE);            //make an array
    for (int j = 0; j < ASIZE; j++)   //fill it with squares
    {
        arr1[j] = j * j;
    }
    for (int j = 0; j < ASIZE; j++)       //display its contents
    {
        cout << arr1[j] << ' ';
    }
    cout << endl;

    Array arr2 = arr1;
    for (int j = 0; j < ASIZE; j++)       //display its contents
    {
        cout << arr2[j] << ' ';
    }
    cout << endl;

    Array arr3;

    arr3 = arr1;
    for (int j = 0; j < ASIZE; j++)       //display its contents
    {
        cout << arr3[j] << ' ' << endl;
    }

    return 0;
}
