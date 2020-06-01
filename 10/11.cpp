#include <iostream>
#include <cstdlib>
#include <cstring>                   //for strlen(), etc

using namespace std;

const int LEN = 80;    //length of expressions, in characters

////////////////////////////////////////////////////////////////

class Token 
{
public:
    virtual float GetNumber() = 0;

    virtual char GetOperator() = 0;
};

class Operator : public Token 
{
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
        Top = 0;
        Values = new Token * [Size];
    }

    TokenStack(int s) : Size(s)
    {
        Top = 0;
        Values = new Token * [Size];
    }

    void Push(Token* element)
    {
        Values[++Top] = element;
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
private:
    TokenStack s;                       //stack for analysis

    char* pStr;                    //pointer to input string

    int len;                       //length of input string

public:
    express(char* ptr)             //constructor
    {
        pStr = ptr;                 //set pointer to string

        len = strlen(pStr);         //set length
    }

    void parse();                  //parse the input string

    float solve();                   //evaluate the stack
};

//--------------------------------------------------------------

void express::parse()                //add items to stack
{
    char ch;                          //char from input string

    float lastval;                     //last value

    char lastop;                      //last operator

    for (int j = 0; j < len;)          //for each input character
    {
        ch = pStr[j];                  //get next character

        if (ch >= '0' && ch <= '9')         //if it's a digit,
        {
            char* charNumber = new char[40];
            int i = 1;
            while ((pStr[j] >= '0' && pStr[j] <= '39') || pStr[j] == '.')
            {
                *(charNumber + i - 1) = pStr[j];
                i++;
                j++;
            }//save numerical value

            float currentNumber = atof(charNumber);
            s.Push(new Number(currentNumber));
        }                                        
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')  //if it's operator
        {
            if (s.GetTop() == 1)           //if it's first operator
            {
                s.Push(new Operator(ch));              //put on stack
            }
            else                        //not first operator
            {
                lastval = s.Pop()->GetNumber();       //get previous digit

                lastop = s.Pop()->GetOperator();        //get previous operator
                //if this is * or / AND last operator was + or -

                if ((ch == '*' || ch == '/') && (lastop == '+' || lastop == '-'))
                {
                    s.Push(new Operator(lastop));       //restore last two pops

                    s.Push(new Number(lastval));
                }
                else                     //in all other cases
                {
                    switch (lastop)        //do last operation
                    {                  //push result on stack
                        case '+': s.Push(new Number(s.Pop()->GetNumber() + lastval));
                            break;

                        case '-': s.Push(new Number(s.Pop()->GetNumber() - lastval));
                            break;

                        case '*': s.Push(new Number(s.Pop()->GetNumber() * lastval));
                            break;

                        case '/': s.Push(new Number(s.Pop()->GetNumber() / lastval));
                            break;

                        default:  cout << "\nUnknown oper";
                            exit(1);
                    }  //end switch

                }  //end else, in all other cases

                s.Push(new Operator(ch));              //put current op on stack

            }  //end else, not first operator

            j++;
        }  //end else if, it's an operator

        else                           //not a known character
        {
            cout << "\nUnknown input character";
            exit(1);
        }

    }  //end for

}  //end parse()

//--------------------------------------------------------------

float express::solve()                 //remove items from stack
{
    float lastval;                     //previous value

    while (s.GetTop() > 1)
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

            default:  cout << "\nUnknown operator"; exit(1);
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

        "\nNo number may have more than one digit."

        "\nDon't use any spaces or parentheses.";

    do 
    {
        cout << "\nEnter expresssion: ";

        cin >> string;                        //input from user

        express* eptr = new express(string);  //make expression

        eptr->parse();                        //parse it

        cout << "\nThe numerical value is: "

            << eptr->solve();                //solve it

        delete eptr;                          //delete expression

        cout << "\nDo another (Enter y or n)? ";

        cin >> ans;

    } while (ans == 'y');

    return 0;

}
