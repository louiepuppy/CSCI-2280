#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <iomanip>
using namespace std;

class fraction
{
private:
    int numerator;
    int denominator;

    friend fraction operator+(const fraction &a, const fraction &b);
    friend fraction operator-(const fraction &a, const fraction &b);
    friend fraction operator*(const fraction &a, const fraction &b);
    friend fraction operator/(const fraction &a, const fraction &b);
    friend ostream &operator<<(ostream &, fraction);
    friend istream &operator>>(istream &, fraction &);

public:
    void simplify();
    void setNumerator(int);
    void setDenominator(int);
    int getNumerator();
    int getDenominator();
    void display();
    fraction();
    fraction(int numerator, int denominator);
};

void fraction::simplify()
{
    int gcd = 1;
    int temp;

    for (int i = 1; i <= abs(numerator); i++)
    {
        if (numerator % i == 0 && denominator % i == 0)
        {
            gcd = i;
        }
    }
    numerator /= gcd;
    denominator /= gcd;
}

void fraction::setNumerator(int num)
{
    numerator = num;
}

void fraction::setDenominator(int den)
{
    denominator = den;
}

int fraction::getNumerator()
{
    return numerator;
}

int fraction::getDenominator()
{
    return denominator;
}

void fraction::display()
{
    cout << numerator << "/" << denominator;
}

fraction::fraction()
{
    numerator = 0;
    denominator = 1;
}

fraction::fraction(int numerator, int denominator)
{
    setNumerator(numerator);
    setDenominator(denominator);
}

fraction operator+(const fraction &a, const fraction &b)
{
    int newNumerator = a.numerator * b.denominator + b.numerator * a.denominator;
    int newDenominator = a.denominator * b.denominator;
    return fraction(newNumerator, newDenominator);
}

fraction operator-(const fraction &a, const fraction &b)
{
    int newNumerator = a.numerator * b.denominator - b.numerator * a.denominator;
    int newDenominator = a.denominator * b.denominator;
    return fraction(newNumerator, newDenominator);
}

fraction operator*(const fraction &a, const fraction &b)
{
    int newNumerator = a.numerator * b.numerator;
    int newDenominator = a.denominator * b.denominator;
    return fraction(newNumerator, newDenominator);
}

fraction operator/(const fraction &a, const fraction &b)
{
    int newNumerator = a.numerator * b.denominator;
    int newDenominator = a.denominator * b.numerator;
    return fraction(newNumerator, newDenominator);
}

ostream &operator<<(ostream &out, fraction f)
{
    f.display();
    return out;
}

istream &operator>>(istream &in, fraction &f)
{
    cout << "Enter numerator and denominator: ";
    try
    {
        in >> f.numerator >> f.denominator;
        if (f.denominator == 0)
        {
            throw runtime_error("Denominator cannot be zero. Setting denominator to 1.");
        }
    }
    catch (const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl;
        in.clear();
        f.setDenominator(1);
    }
    return in;
}

#endif // FRACTION_H