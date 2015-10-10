#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

int gcd ( int a, int b )
{
    int k = 0;
    int factors1[20];
    int h = 0;
    int factors2[20];
    for ( int i = 1; i <= a; i++ )
    {
        if ( a % i == 0 )
        {
            factors1[k] = i;
            k++;
        }
    }
    for ( int j = 1; j <= b; j++ )
    {
        if ( b % j == 0 )
        {
            factors2[h] = j;
            h++;
        }
    }
    k--; h--;
    while ( 1 )
    {
        if ( factors2[h] == factors1[k] )
        {
            break;
        }
        if ( factors2[h] < factors1[k] )
        {
            k--;
            h++;
        }
        h--;
    }
    return factors2[h];
}

int main ( )
{
    int a, b, temp;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    if ( a > b )
    {
        temp = a;
        a = b;
        b = temp;
    }
    cout << "The greatest common divisor is: " << gcd ( a, b ) << endl;
    return 0;
}
