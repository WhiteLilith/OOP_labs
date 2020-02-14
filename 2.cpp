#1
#include <iostream>

#include <iomanip>

using namespace std;

int main()

{

  unsigned long n;

  cout << "\nEnter a number: ";

  cin >> n; //get number

  for(int j=1; j<=200; j++)

  {

    cout << setw(5) << j*n << " "; 

    if( j%10 == 0 )

    cout << endl;
  
  }

  return 0;

}
#2
#include <iostream>

using namespace std;

int main()

{

  int response;

   double temper;

  cout << "\nType 1 to convert fahrenheit to celsius,"

  << "\n 2 to convert celsius to fahrenheit: ";

  cin >> response;

  if( response == 1 )

  {

    cout << "Enter temperature in fahrenheit: ";

    cin >> temper;

    cout << "In celsius that's " << 5.0/9.0*(temper-32.0);

  }

  else

  {

    cout << "Enter temperature in celsius: ";

    cin >> temper;

    cout << "In fahrenheit that's " << 9.0/5.0*temper + 32.0;

   }

  cout << endl;

  return 0;

}
#3
#include <iostream>

using namespace std;

#include <conio.h>

int main()

{

char ch;

unsigned long total = 0;=

cout << "\nEnter a number: ";

while( (ch=getche()) != '\r' )

total = total*10 + ch-'0';

cout << "\nNumber is: " << total << endl;

return 0;

}
#4
#include <iostream>

using namespace std;

int main()

{

double n1, n2, ans;

char oper, ch;

do {

cout << "\nEnter first number, operator, second number: ";

cin >> n1 >> oper >> n2;

switch(oper)

{

case '+': ans = n1 + n2; break;

case '-': ans = n1 - n2; break;

case '*': ans = n1 * n2; break;

case '/': ans = n1 / n2; break;

default: ans = 0;

}

cout << "Answer = " << ans;

cout << "\nDo another (Enter 'y' or 'n')? ";

cin >> ch;

} while( ch != 'n' );

return 0;

}
#5
#include <iostream>

using namespace std;

int main()
{
	
	for (int i = 20; i >= 0; i--)
	{
		for (int j = i; j >= 0; j--)
		{
			cout << " ";
		}
		for (int j = 0; j < 20 - i; j++)
		{
			cout << "X";
		}
		cout << endl;
	}

	return 0;
}
#6
#include <iostream>

using namespace std;

int main()

{

unsigned int numb;

unsigned long fact=1;

cout << "Enter a number: ";

cin >> numb; 

for(int j=numb; j>0; j--)

fact *= j;

cout << "Factorial is " << fact << endl;

return 0;

}
#7
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	float nach, stav, goda;

	cout << "Vvedite nachalinuyu summu: ";
	cin >> nach;

	cout << endl << "Vvedite stavku: ";
	cin >> stav;
	
	cout << endl << "Vvedite skolko let: ";
	cin >> goda;

	float itog = nach;

	for (int i = 0; i < goda; i++)
	{
		itog = itog + itog * (stav / 100);
	}

	cout << "Cherez " << goda << " vi poluchite " << itog << "rub";

	return 0;
}
#8
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	bool cont = 1;

	do {
		int shil_1, funt_1, pense_1;
		int shil_2, funt_2, pense_2;
		int shil_3 = 0, funt_3 = 0, pense_3 = 0;

		cout << "Введите первую сумму: ";
		cin >> funt_1;
		cout << " ";
		cin >> shil_1;
		cout << " ";
		cin >> pense_1;

		cout << endl;

		cout << "Введите вторую сумму: ";
		cin >> funt_2;
		cout << " ";
		cin >> shil_2;
		cout << " ";
		cin >> pense_2;

		pense_3 = pense_1 + pense_2;
		if (pense_3 > 11)
		{
			shil_3++;
			pense_3 -= 12;
		}

		shil_3 = shil_3 + shil_1 + shil_2;
		if (shil_3 > 19)
		{
			funt_3++;
			shil_3 -= 20;
		}

		funt_3 = funt_3 + funt_1 + funt_2;

		cout << endl << "Всего: " << funt_3 << " фунтов " << shil_3 << " шиллингов " << pense_3 << " пенсов";

		cout << endl << "Продолжить (y/n) ";
		char c;
		cin >> c;
		cont = 0;

		if (c == 'y')
		{
			cont = 1;
		}

	} while (cont);

	return 0;
}
#9
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int humans, places;

	cout << "Введите колво людей ";
	cin >> humans;

	cout << "Введите колво мест ";
	cin >> places;

	int itog = 1;

	for (int i = humans; i > humans - places; i--)
	{
		itog *= i;
	}

	cout << itog << " способов";

	return 0;
}
#10
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	float stav, beg, needed;
	int years = 0;

	cout << "Введите процентную ставку: ";
	cin >> stav;

	cout << "Введите начальную сумму: ";
	cin >> beg;

	cout << "Введите желаемую сумму: ";
	cin >> needed;

	for (int i = beg; i < needed; i += i * (stav/100))
	{
		years++;
	}

	cout << "Потребуется " << years << " лет.";

	return 0;
}
#11
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	bool cont = 1;
	int shil_1, funt_1, pense_1;
	int shil_2, funt_2, pense_2;
	int shil_3 = 0, funt_3 = 0, pense_3 = 0;

	do {
		cont = 0;

		cout << "Введите первую сумму: ";
		cin >> funt_1;
		cout << " ";
		cin >> shil_1;
		cout << " ";
		cin >> pense_1;

		char oper;
		float mult;
		cout << "Введите опреатор: ";
		{
			cin >> oper;
		}

		if ((oper == '+') || (oper == '-'))
		{
			cout << "Введите вторую сумму: ";
			cin >> funt_2;
			cout << " ";
			cin >> shil_2;
			cout << " ";
			cin >> pense_2;
		}
		else
		{
			cout << "Введите множитель: ";
			cin >> mult;
		}


		switch (oper)
		{
		case '+':
			pense_3 = pense_1 + pense_2;
			if (pense_3 > 11)
			{
				shil_3++;
				pense_3 -= 12;
			}

			shil_3 = shil_3 + shil_1 + shil_2;
			if (shil_3 > 19)
			{
				funt_3++;
				shil_3 -= 20;
			}

			funt_3 = funt_3 + funt_1 + funt_2;
			break;

		case '-':
			pense_3 = pense_1 - pense_2;
			if (pense_3 < 0)
			{
				shil_3--;
				pense_3 += 12;
			}

			shil_3 = shil_3 + shil_1 - shil_2;
			if (shil_3 < 0)
			{
				funt_3--;
				shil_3 += 20;
			}

			funt_3 = funt_3 + funt_1 - funt_2;
			break;

		case '*':
			pense_3 = pense_1 * mult;
			
			while (pense_3 > 11)
			{
				shil_3++;
				pense_3 -= 12;
			}

			shil_3 = shil_3 + (shil_1 * mult);
			while (shil_3 > 19)
			{
				funt_3++;
				shil_3 -= 20;
			}

			funt_3 = funt_3 + (funt_1 * mult);
			break;

		}

		cout << endl << "Всего: " << funt_3 << " фунтов " << shil_3 << " шиллингов " << pense_3 << " пенсов";

		cout << endl << "Продолжить (y/n) ";
		char c;
		cin >> c;

		if (c == 'y')
		{
			cont = 1;
		}

	} while (cont);

	

	return 0;
}
#12
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	bool cont = 1;
	int a, b, c, d;
	int result_chisl, result_znam;


	do {
		cont = 0;

		char dummy_char;

		cout << "Введите первую дробь: ";
		cin >> a >> dummy_char >> b;

		cout << "Введите вторую дробь: ";
		cin >> c >> dummy_char >> d;
		
		char oper;
		float mult;
		cout << "Введите опреатор: ";
		{
			cin >> oper;
		}

		switch (oper)
		{
		case '+':
			result_chisl = (a * d + b * c);
			result_znam = (b * d);
			break;
		case '-':
			result_chisl = (a * d - b * c);
			result_znam = (b * d);
			break;
		case '*':
			result_chisl = (a * c);
			result_znam = (b * d);
			break;
		case '/':
			result_chisl = a * d;
			result_znam = b * c;
		}

		cout << "Результат: " << result_chisl << '/' << result_znam;

		cout << endl << "Продолжить (y/n) ";
		char c;
		cin >> c;

		if (c == 'y')
		{
			cont = 1;
		}

	} while (cont);

	return 0;
}
