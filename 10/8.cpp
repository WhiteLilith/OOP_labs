#include <stdlib.h>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Token {

public:

    virtual float GetNumber() = 0;

    virtual char GetOperator() = 0;

};

class Operator : public Token {

private:

    char oper;

public:

    Operator(char);

    char GetOperator() override;

    float GetNumber() override;

};

Operator::Operator(char c)
{
    oper = c;
}

char Operator::GetOperator()
{
    return oper;
}

float Operator::GetNumber()
{
    return NULL;
}

class Number : public Token {
private:
    float fnum;

public:

    Number(float);

    float GetNumber() override;

    char GetOperator() override;

};

Number::Number(float value)
{
    fnum = value;
}

float Number::GetNumber()
{
    return fnum;
}

char Number::GetOperator()
{
    return NULL;
}

class TokenStack
{
protected:
    Token **Values;
    int Size;
    int Top;

public:
    TokenStack() : Size(70)
    {
        Top = -1;
        Values = new Token*[Size];
    }

    TokenStack(int s) : Size(s)
    {
        Top = -1;
        Values = new Token*[Size];
    }

    void Push(Token* number)
    {
        Top++;
        Values[Top] = number;
    }

    Token* TopTop()
    {
        return Values[Top];
    }

    Token* Pop()
    {
        return Values[Top--];
    }

    bool IsEmpty()
    {
        if (Top == -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    TokenStack s;

    s.Push(new Number(90));
    s.Push(new Operator('/'));
    s.Push(new Number(17.34));

    while (!s.IsEmpty())
    {
        if (s.TopTop()->GetOperator() == NULL)
        {
            cout << s.TopTop()->GetNumber() << " ";
        }
        else
        {
            cout << s.TopTop()->GetOperator() << " ";
        }
        s.Pop();
    }
    cout << endl;

    return 0;
}
