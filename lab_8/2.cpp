#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h> 
#include <stdlib.h> 

using namespace std;


class String
{
protected:
	const static int SZ = 9;
	char str[SZ];

public:

	String()
	{
		strncpy(str, "", SZ);
	}

	String(char s[])
	{
		strncpy(str, s, SZ);
	}

	void Display() const
	{
		for (int i = 0; i < SZ; i++)
		{
			cout << str[i];
		}
	}

};

class Pstring : public String
{
public:

	Pstring() : String()
	{}

	Pstring(char s[]) : String(s)
	{
		char new_s[String::SZ - 1];
		new_s[String::SZ - 2] = '\0';
		strncpy(new_s, String::str, strlen(new_s));
		strncpy(String::str, new_s, strlen(new_s));
	}
};


int main()
{
	char str_1[7] = {'A', 'B', 'C', 'D', 'E', 'F', '\0'};
	char str_2[11] = {'G', 'H', 'I', 'G', 'K', 'L', 'M', 'N', 'O', 'P', '\0'};
	Pstring s1(str_1);
	Pstring s2(str_2);

	s1.Display();
	s2.Display();

	cout << endl;

	return 0;
}
