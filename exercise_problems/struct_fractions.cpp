#include <iostream>

using namespace std;

struct Fraction
{
    float numerator;
    float denominator;
};

void multiply(Fraction x, Fraction y)
{
    float a, b;
    a = x.numerator * y.numerator;
    b = x.denominator * y.denominator;
    cout << a / b;
}

int main()
{
    Fraction a, b;
    cout << "Enter numerator 1: ";
    cin >> a.numerator;
    cout << "Enter denominator 1: ";
    cin >> a.denominator;
    cout << "Enter numerator 2: ";
    cin >> b.numerator;
    cout << "Enter denominator 2: ";
    cin >> b.denominator;
    multiply(a, b);
    return 0;
}
