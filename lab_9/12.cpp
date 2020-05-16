#include <iostream>
#include <cstdlib>

using namespace std;

static float fmemory[1024];
static int pmemory[1024];
static int fmem_top = 0;
static int pmem_top = 0;

class Float
{
protected:
	int addr;

public:
	Float(float _input)
	{
		*(fmemory + fmem_top) = _input;
		addr = fmem_top;
		fmem_top += 1;
	}

	Float operator=(float change)
	{
		fmemory[addr] = change;
	}

	int operator&()
	{
		return addr;
	}
};

class ptrFloat
{
protected:
	int pmemory_index;

public:
	ptrFloat(int float_addr)
	{
		pmemory_index = pmem_top;
		*(pmemory + pmem_top) = float_addr;
		pmem_top += 1;
	}

	float& operator*()
	{
		return fmemory[pmemory[pmemory_index]];
	}

};

int main()
{
	Float varl = 1.234; // определяем и инициализируем

	Float var2 = 5.678; // две вещественные переменные

	ptrFloat ptrl = &varl; // определяем и инициализируем

	ptrFloat ptr2 = &var2; // два указателя

	cout << "*ptrl = " << *ptrl;

	cout << " *ptr2 = " << *ptr2 << endl << endl; // и выводим на экран

	*ptrl = 7.123; // присваиваем новые значения

	*ptr2 = 8.456; // переменным, адресованным через указатели

	cout << " *ptrl = " << * ptrl; // снова получаем значения

	cout << " *ptr2 = " << * ptr2; // и выводим на экран

	return 0;
}
