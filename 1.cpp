// #1
#include <iostream>

using namespace std;

int main()

{

	float gallons, cufeet;

	cout << "\nEnter quantity in gallons: ";

	cin >> gallons;

	cufeet = gallons / 7.481;

	cout << "Equivalent in cublic feet is " << cufeet << endl;

	return 0;

}

//#2
#include <iostream>
#include <iomanip>

using namespace std;

int main()

{

	cout << 1990 << setw(8) << 135 << endl
		<< 1991 << setw(8) << 7290 << endl
		<< 1992 << setw(8) << 11300 << endl
		<< 1993 << setw(8) << 16200 << endl;
	return 0;
}

//#3
#include <iostream>
#include <iomanip>

using namespace std;

int main()

{
	const int var = 10;
	int var1;
	var1 = 20;
	cout << var << endl;
	cout << var1 << endl;
	cout << --var1 << endl;
}
//#4
#include<iostream>

using namespace std;

int main()
{
	cout << "Через час отсюда в чистый переулок\n";
	cout << "вытечет по человеку ваш обрюзгший жир,\n";
	cout << "а я вам открыл столько стихов шкатулок,\n";
	cout << "я — бесценных слов мот и транжир.";
	
	return 0;
}
//#5
#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	cout << "VVedite bukvu\n";
	char c;
	cin >> c;

	cout << islower(c) << endl;
	
	return 0;
}
//#6
#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	float dollars;

	cout << "Vvedite kolvo dollarov\n";
	cin >> dollars;

	cout << " Eto " << dollars / 1.487 << " funtov.\n";
	cout << " Eto " << dollars /  0.172 << " frankov.\n";
	cout << " Eto " << dollars / 0.584 << " marok.\n";
	cout << " Eto " << dollars / 0.00955 << " ien.\n";
	
	return 0;
}
//#7
#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	float temp;

	cout << "VVedite temperaturu v celcius\n";
	cin >> temp;
	cout << "Eto " << temp * 9 / 5 + 32 << " gradusov po farengeitu";
	
	return 0;
}
//#8
#include <iostream>
#include <iomanip>

using namespace std;

int main()

{

	cout << 1990 << setfill('.') << setw(8) << 135 << endl
		<< 1991 << setw(8) << 7290 << endl
		<< 1992 << setw(8) << 11300 << endl
		<< 1993 << setw(8) << 16200 << endl;
	return 0;
}
//#9
#include <iostream>
#include <iomanip>

using namespace std;

int main()

{
	setlocale(LC_ALL, "Russian");
	char z;
	int a, b, c, d, rez_ch, rez_znam;
	cout << "Введите первую дробь: ";
	cin >> a >> z >> b;

	cout << endl << "Введите вторую дробь: ";
	cin >> c >> z >> d;

	rez_ch = a * d + b * c;
	rez_znam = b * d;

	cout << endl << "Сумма равна " << rez_ch << "/" << rez_znam;

	return 0;
}
#10
#include <iostream>

using namespace std;

int main()

{
	setlocale(LC_ALL, "Russian");
	
	float funt, shil, pens, des_funt;
	cout << "Введите количество фунтов: ";
	cin >> funt;

	cout << endl << "Введите количество шиллингов: ";
	cin >> shil;

	cout << endl << "Введите количество пенсов: ";
	cin >> pens;

	des_funt = funt + shil / 20 + pens / 240;

	char c = (char)156;

	cout << endl << "Десятичных фунтов: " << des_funt << c;

	return 0;
}
//#11
