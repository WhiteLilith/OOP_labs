#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h> 
#include <stdlib.h> 

using namespace std;

class String
{
protected:
	const static int SZ = 100;
	char str[SZ];
	int EndIndex;

public:

	String()
	{
		strcpy(str, "");
		EndIndex = 0;
	}

	String(char s[])
	{
		strcpy(str, s);
		EndIndex = strlen(s);
	}

	void Display() const
	{
		for (int i = 0; i < EndIndex; i++)
		{
			cout << str[i];
		}
		cout << endl;
	}

	int GetSZ()
	{
		return SZ;
	}

	char* Getstr()
	{
		return str;
	}

	int GetEndIndex()
	{
		return EndIndex;
	}

	char Getistr(int i)
	{
		return str[i];
	}

	void SetEndIndex(int a)
	{
		EndIndex = a;
	}

	void Setstr(char c[])
	{
		strcpy(str, c);
	}

	void Setistr(int i, char c)
	{
		str[i] = c;
	}
};

class Pstring : public String
{
public:

	Pstring() : String()
	{}

	Pstring(char s[])
	{
		int i = 0;
		while ((s[i] != '\0') && (i <= String::GetSZ() - 2))
		{
			String::Setistr(i, s[i]);
			++i;
		}
		s[i] = '\0';
		String::SetEndIndex(i);
	}

	void SetEndIndex(int a) 
	{
		String::SetEndIndex(a);
	}

	void Setistr(int i, char c)
	{
		String::Setistr(i, c);
	}

	void Setstr(char c[])
	{
		String::Setstr(c);
	}

	int GetSZ()
	{
		return String::GetSZ();
	}

	char* Getstr()
	{
		return String::Getstr();
	}

	int GetEndIndex()
	{
		return String::GetEndIndex();
	}

	char Getistr(int i)
	{
		return String::Getistr(i);
	}
};

class Pstring2 : public Pstring
{
public: 
	Pstring2() : Pstring()
	{}

	Pstring2(char s[]) : Pstring(s)
	{}

	Pstring2 Left(int a)
	{
		char NewString[SZ];
		int i;
		for (i = a; i < Pstring::GetSZ() - 1; i++)
		{
			NewString[i - a] = Pstring::Getistr(i);
		}
		NewString[i] = '\0';
		return Pstring2(NewString);
	}

	Pstring2 Right(int a)
	{
		char NewString[SZ];
		int i;
		for (i = 0; i < Pstring::GetEndIndex() - a; i++)
		{
			NewString[i] = Pstring::Getistr(i);
		}
		NewString[i] = '\0';
		return Pstring2(NewString);
	}

	Pstring2 Mid(int a, int b)
	{
		char BeforeString[SZ];
		for (int i = 0; i < b; i++)
		{
			BeforeString[i] = Pstring::Getistr(i);
		}

		int j = 0;
		char AfterString[SZ];
		for (int i = b + a; i < Pstring::GetEndIndex(); i++)
		{
			AfterString[j] = Pstring::Getistr(i);
			j++;
		}

		return Pstring2(strcat(BeforeString, AfterString));
	}

	void Display()
	{
		String::Display();
	}
};

int main()
{
	char str_1[] = { 'A', 'B', 'C', 'D', 'E', 'F', '\0' };
	Pstring2 s(str_1);

	s.Display();

	Pstring2 sl, sr, sm;
	sl = s.Left(1);
	sr = s.Right(1);
	sm = s.Mid(1, 3);
	sl.Display();
	sr.Display();
	sm.Display();


	cout << endl;

	return 0;
}
