#include <iostream>
#include <cstring>
using namespace std;
class String
{
protected:
	enum { SZ = 80 };
	char str[SZ];
public:
	String()
	{
		str[0] = '\0';
	}
	String(const char s[])
	{
		strcpy_s(str, s);
	}
	void Display() const
	{
		cout << str;
	}
	operator char* ()
	{
		return str;
	}
};

class Pstring : public String
{
public:
	Pstring(const char s[])
	{
		if (strlen(s) > SZ - 1)
		{
			int i = 0;
			for (i = 0; i < SZ - 1; i++)
			{
				str[i] = s[i];
			}
			str[i] = '\0';
		}
		else
		{
			strcpy_s(str, s);
		}
	}
};

class Pstring2 : public Pstring
{

public:
	Pstring2(const char s[]) : Pstring(s)
	{ }

	Pstring2 Left(int number)
	{
		Pstring2 substr = "";
		int i;
		for (i = 0; i < number; i++)
		{
			substr[i] = str[i];
		}
		substr[i] = '\0';
		return substr;
	}
	Pstring2 Right(int number)
	{
		Pstring2 substr = "";
		int i;
		int strend = SZ;
		for (i = 0; i < SZ; i++)
		{
			if (str[i] == '\0') strend = i;
		}
		for (i = 0; i < number; i++)
		{
			substr[i] = str[i + strend - number];
		}
		substr[i] = '\0';

		return substr;
	}
	Pstring2 Mid(int position, int number)
	{
		Pstring2 substr = "";
		int i;
		for (i = 0; i < SZ - position && i < number; i++)
			substr[i] = str[i + position];
		substr[i] = '\0';
		return substr;
	}
};

int main()
{
	Pstring2 s1 = "Hello world!";

	cout << "left = "; 
	s1.Left(5).Display();
	cout << endl;

	cout << "right = ";
	s1.Right(6).Display();
	cout << endl;

	cout << "mid = ";
	s1.Mid(3, 5).Display();
	cout << endl;

	return 0;
}
