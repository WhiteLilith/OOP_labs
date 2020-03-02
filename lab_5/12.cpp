#include <iostream>
#include <cmath>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

    void Lowterms() 
    {
        long tnum, tden, temp, gcd;
        tnum = labs(numerator); 
        tden = labs(denominator); 
        if (tden == 0) 
        { 
            cout << "Недопустимый знаменатель"; 
            exit(1);
        }
        else if (tnum == 0) 
        {
            numerator = 0;
            denominator = 1;
            return;
        }
        while (tnum != 0) 
        {
            if (tnum < tden) 
            { 
                temp = tnum;
                tnum = tden;
                tden = temp;
            }
            tnum = tnum - tden;
        }

        gcd = tden;
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }

public:
    Fraction() : numerator(0), denominator(0)
    {}

    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator)
    {
        Lowterms();
    }

    void SetFration(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    int GetNumerator() const
    {
        return numerator;
    }

    int GetDenominator() const
    {
        return denominator;
    }

    Fraction operator + (Fraction fraction_2) const
    {
        int newNumerator = numerator * fraction_2.denominator + denominator * fraction_2.numerator;
        int newDenominator = denominator * fraction_2.denominator;

        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator - (Fraction fraction_2) const
    {
        int newNumerator = numerator * fraction_2.denominator - denominator * fraction_2.numerator;
        int newDenominator = denominator * fraction_2.denominator;

        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator * (Fraction fraction_2) const
    {
        int newNumerator = numerator * fraction_2.numerator;
        int newDenominator = denominator * fraction_2.denominator;

        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator / (Fraction fraction_2) const
    {
        int newNumerator = numerator * fraction_2.denominator;
        int newDenominator = denominator * fraction_2.numerator;

        return Fraction(newNumerator, newDenominator);
    }
};




int main()
{
    setlocale(LC_ALL, "Russian");

    int numerator, denominator;
    int userDenominator;
    char dummyChar;
    
    cout << "Введите знаменатель: ";
    cin >> userDenominator;

    Fraction f_1, f_2, f_3;

    for (int i = 1; i < userDenominator; i++)
    {
        f_1.SetFration(i, userDenominator);
        cout << f_1.GetNumerator() << "/" << f_1.GetDenominator() << " ";
    }

    cout << "\n";

    for (int i = 1; i < userDenominator; i++)
    {
        f_2.SetFration(i, userDenominator);
        for (int j = 1; j < userDenominator; j++)
        {
            f_1.SetFration(j, userDenominator);
            f_3 = f_1 * f_2;
            cout << f_3.GetNumerator() << "/" << f_3.GetDenominator() << " ";
        }
        cout << "\n";
    }
}
