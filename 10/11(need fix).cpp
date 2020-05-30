#include <iostream>
#include <string>
#include <cstring>                   //for strlen(), etc
#include <stdlib.h>

using namespace std;

const int LEN = 80;    //length of expressions, in characters

const int MAX = 40;    //size of stack

////////////////////////////////////////////////////////////////

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
    Token** Values;
    int Size;
    int Top;

public:
    TokenStack() : Size(70)
    {
        Top = -1;
        Values = new Token* [Size];
    }

    TokenStack(int s) : Size(s)
    {
        Top = -1;
        Values = new Token* [Size];
    }

    void Push(Token* element)
    {
        Top++;
        Values[Top] = element;
    }

    int GetTop()
    {
        return Top;
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

////////////////////////////////////////////////////////////////

class express                        //expression class
{
protected:
    TokenStack s;                       //stack for analysis

    string pStr;                    //pointer to input string

    int len;                       //length of input string

    int* ochered;

    char* operatorsArray;

public:
    express(char* ptr)             //constructor
    {
        pStr = ptr;                 //set pointer to string
        len = pStr.length();         //set length
    }

    void parse();                  //parse the input string

    float solve();                   //evaluate the stack

};

//--------------------------------------------------------------

void express::parse()                //add items to stack
{
    string ch;                          //char from input string

    string lastval;                     //last value

    string lastop;                      //last operator

    int amountOfOperators = 0;
    char c;

    for (int i = 0; i < len; i++)
    {
        c = pStr[i];
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            amountOfOperators++;
        }
    }
    float* flarr = new float[amountOfOperators + 1];
    operatorsArray = new char[amountOfOperators];
    int k = 0;
    for (int i = 0; i < len; i++)
    {
        c = pStr[i];
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            operatorsArray[k] = c;
            k++;
        }
    }

    string copyOfPstr;
    for (int i = 0; i < amountOfOperators + 1; i++)
    {
        c = copyOfPstr[i];
        int j = 0;

        while (c != '+' || c != '-' || c != '/' || c != '*')
        {
            j++;
        }

        s.Push(new Number(stof(copyOfPstr.substr(0, j + 1))));
        flarr[i] = stof(copyOfPstr.substr(0, j + 1));
        if (i != amountOfOperators)
        {
            s.Push(new Operator(copyOfPstr[j + 1]));
        }

        copyOfPstr = copyOfPstr.substr(j + 2);
    }

    operatorsArray = new char[amountOfOperators];
    ochered = new int[amountOfOperators];

    for (int i = 0; i < amountOfOperators; i++)
    {
        ochered[i] = i;
    }

    for (int i = 0; i < amountOfOperators; i++)
    {
        for (int j = i; j < amountOfOperators; j++)
        {
            if ((operatorsArray[j] == '+' || operatorsArray[j] == '-') && (operatorsArray[i] == '*' || operatorsArray[i] == '/'))
            {
                int bus = ochered[i];
                ochered[i] = ochered[j];
                ochered[j] = bus;

                float fbus = flarr[i];
                flarr[i] = flarr[j];
                float fbus2 = flarr[i + 1];
                flarr[i + 1] = flarr[j + 1];
                flarr[j + 1] = fbus2;
                flarr[j] = fbus;
            }
        }
    }

    TokenStack a;

    for (int i = 0; i < s.GetTop(); i++)
    {
        if (i % 2 == 0)
        {
            a.Push(new Number(flarr[i]));
        }
        else
        {
            a.Push(new Operator(operatorsArray[i - 1]));
        }
    }

    s = a;

    //for (int j = 0; j < len; j++)          //for each input character
    //{
    //    ch = pStr[j];                  //get next character
    //    if ((ch >= "0" && ch <= "9") || ch == ".")         //if it's a digit,
    //    {
    //        s.Push(new Number(_atoflt());             //save numerical value
    //    }
    //     //if it's operator
    //    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    //    {
    //        if (s.GetTop() == 1)           //if it's first operator
    //        {
    //            s.Push(new Operator(ch));              //put on stack
    //        }
    //        else                        //not first operator
    //        {
    //            lastval = s.Pop()->GetNumber();       //get previous digit
    //            lastop = s.Pop()->GetOperator();        //get previous operator

    //            //if this is * or / AND last operator was + or -

    //            if ((ch == '*' || ch == '/') && (lastop == '+' || lastop == '-'))
    //            {
    //                s.Push(new Operator(lastop));       //restore last two pops
    //                s.Push(new Number(lastval));
    //            }
    //            else                     //in all other cases
    //            {
    //                switch (lastop)        //do last operation
    //                {                  //push result on stack
    //                case '+': s.Push(new Number(s.Pop()->GetNumber() + lastval)); 
    //                          break;
    //                case '-': s.Push(new Number(s.Pop()->GetNumber() - lastval)); 
    //                          break;
    //                case '*': s.Push(new Number(s.Pop()->GetNumber() * lastval)); 
    //                          break;
    //                case '/': s.Push(new Number(s.Pop()->GetNumber() / lastval));
    //                          break;
    //                default:  cout << "\nUnknown oper";
    //                          exit(1);
    //                }  //end switch

    //            }  //end else, in all other cases

    //            s.Push(new Operator(ch));              //put current op on stack

    //        }  //end else, not first operator

    //    }  //end else if, it's an operator

    //    else                           //not a known character

    //    {
    //        cout << "\nUnknown input character"; exit(1);
    //    }

    //}  //end for

}  //end parse()

//--------------------------------------------------------------

float express::solve()                 //remove items from stack
{
    float lastval;                     //previous value

    while (s.GetTop() > 0)
    {
        lastval = s.Pop()->GetNumber();             //get previous value
        switch (s.Pop()->GetOperator())              //get previous operator
        {                           //do operation, push answer
            case '+': s.Push(new Number(s.Pop()->GetNumber() + lastval)); 
                      break;
            case '-': s.Push(new Number(s.Pop()->GetNumber() - lastval)); 
                      break;
            case '*': s.Push(new Number(s.Pop()->GetNumber() * lastval)); 
                      break;
            case '/': s.Push(new Number(s.Pop()->GetNumber() / lastval)); 
                      break;
            default:  cout << "\nUnknown operator";
                      exit(1);
        }  //end switch

    }  //end while

    return float(s.Pop()->GetNumber());            //last item on stack is ans

}  //end solve()

////////////////////////////////////////////////////////////////

int main()
{
    char ans;                         //'y' or 'n'
    char string[LEN];                 //input string from user

    cout << "\nEnter an arithmetic expression"
            "\nof the form 2+3*4/3-2."
            "\nDon't use any spaces or parentheses.";
     
    do 
    {
        cout << "\nEnter expresssion: ";
        cin >> string;                        //input from user

        express* eptr = new express(string);  //make expression

        eptr->parse();                        //parse it

        cout << "\nThe numerical value is: " << eptr->solve();                //solve it

        delete eptr;                          //delete expression

        cout << "\nDo another (Enter y or n)? ";
        cin >> ans;

    } while (ans == 'y');

    return 0;
}
