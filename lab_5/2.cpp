#include <iostream>

using namespace std;

#include <conio.h>

const char ESC = 27;//Код клавиши ESC

const double TOLL = 0.5;//пошлина равна 50 центами

///////////////////////////////////////////////////////////

class tollBooth

{

private:

	unsigned int totalCars; //всего машин за день

	double totalCash; //всего денег за день

public: //конструктор

	tollBooth() : totalCars(0), totalCash(0.0)

	{}

	void payingCar() //а car paid

	{
		totalCars++; totalCash += TOLL;
	}

	void nopayCar() //а car didn 't pay

	{
		totalCars++;
	}

	void display()const //display totals

	{
		cout << "\nМашины: " << totalCars

			<< "Деньги: " << totalCash

			<< endl;
	}

};

///////////////////////////////////////////////////////////

int main()

{

	tollBooth booth1; //создает турникет

	char ch;

	cout << "\nНажмите 0 для машины без оплаты,"

		<< "\n 1 для каждой оплачивающей машины,"

		<< "\n Esc для выхода.\n ";

	do {

		ch = _getche(); //получить символ

		if (ch == '0 ') //если это 0, машина не оплачивала

		booth1.nopayCar();

		if (ch == '1')//если 1, машина оплачивала

		booth1.payingCar();

	} while (ch != ESC); //выход из цикла по Esc

	booth1.display(); //вывод отчета

	return 0;

}
