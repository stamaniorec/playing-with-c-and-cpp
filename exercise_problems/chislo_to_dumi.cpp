#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

string PreTen ( int );
string Sub10Pre20 ( int );
string Sub20Pre100 ( int );
void Scope1 ( int );

int thousands ( long user_input )
{
    int i = 0;
    int numz = 0;
    int a = 0;
    long k = user_input;
    int shp = 1;
    while ( k != 0 )
    {
        a = k % 10;
        i++;
        if ( i >= 4 && i <= 6)
        {
            numz += a*shp;
            shp *= 10;
        }
        k /= 10;
    }
    return numz;
}

int hundreds ( int user_input )
{
    int i = 0;
    int numz = 0;
    int a = 0;
    int k = user_input;
    int shp = 1;
    while ( k != 0 )
    {
        a = k % 10;
        i++;
        if ( i >= 1 && i <= 3)
        {
            numz += a*shp;
            shp *= 10;
        }
        k /= 10;
    }
    return numz;
}

int main ()
{
    long user_input;
    cout << "Enter n: ";
    cin >> user_input;
    if ( user_input >= 1 && user_input <= 999 )
    {
        Scope1 ( user_input );
    }
    if ( user_input >= 1000 && user_input <= 999999 )
    {
        Scope1 ( thousands( user_input) ) ;
        cout << " thousand ";
        Scope1 ( hundreds( user_input ) );
    }
    return 0;
}

string PreTen ( int n )
{
    string edinica;
    if ( n == 1 )
        {
            edinica = "one";
        }
        else if ( n == 2 )
        {
            edinica = "two";
        }
        else if ( n == 3 )
        {
            edinica = "three";
        }
        else if ( n == 4)
        {
            edinica = "four";
        }
        else if ( n == 5 )
        {
            edinica = "five";
        }
        else if ( n == 6 )
        {
            edinica = "six";
        }
        else if ( n == 7 )
        {
            edinica = "seven";
        }
        else if ( n == 8)
        {
            edinica = "eight";
        }
        else if ( n == 9 )
        {
            edinica = "nine";
        }
        return edinica;
}

string Sub10Pre20 ( int n )
{
    string teen;
    if ( n == 10 )
    {
            teen = "ten";
    }
    else if ( n == 11 )
    {
            teen = "eleven";
    }
    else if ( n == 12 )
    {
            teen = "twelve";
    }
    else if ( n == 13 )
    {
            teen = "thirteen";
    }
    else if ( n == 14 )
    {
            teen = "fourteen";
    }
    else if ( n == 15 )
    {
            teen = "fifteen";
    }
    else if ( n == 16 )
    {
            teen = "sixteen";
    }
    else if ( n == 17 )
    {
            teen = "seventeen";
    }
    else if ( n == 18 )
    {
            teen = "eighteen";
    }
    else
    {
        teen = "nineteen";
    }
    return teen;
}

string Sub20Pre100 ( int a )
{
    string desetica;
    if ( a == 2 )
    {
        desetica = "twenty";
    }
    if ( a == 3 )
    {
        desetica = "thirty";
    }
    if ( a == 4 )
    {
        desetica = "forty";
    }
    if ( a == 5 )
    {
        desetica = "fifty";
    }
    if ( a == 6 )
    {
        desetica = "sixty";
    }
    if ( a == 7 )
    {
        desetica = "seventy";
    }
    if ( a == 8 )
    {
        desetica = "eighty";
    }
    if ( a == 9 )
    {
        desetica = "ninety";
    }
    return desetica;
}

void Scope1 ( int user_input )
{
    int n;
    n = user_input;
    if ( n < 10 )
    {
        cout << PreTen ( n );
    }
    int h;
    h = n;
    if ( n >= 10 && n < 20 )
    {
        cout << Sub10Pre20 ( n );
    }
    int a;
    if ( n >= 20 && n <= 99 )
    {
        while ( n != 0 )
        {
            a = n % 10;
            n /= 10;
        }
        cout << Sub20Pre100 ( a ) << " ";
        while ( h >= 10 )
        {
            a = h % 10;
            h /= 10;
        }
        cout << PreTen(a);
    }
    if ( n >= 100 && n <= 999)
    {
        h = n;
        while ( n != 0 )
        {
            a = n % 10;
            n /= 10;
        }
        cout << PreTen ( a ) << " hundred ";
        n = h;
        while ( n >= 10 )
        {
            a = n % 10;
            n /= 10;
        }
        n = h;
        if ( a > 1 )
        {
        while ( n >= 10 )
        {
            a = n % 10;
            n /= 10;
        }
        cout << Sub20Pre100 ( a ) << " ";
        n = h;
        while ( h >= 100 )
        {
            a = h % 10;
            h /= 10;
        }
        cout << PreTen(a);
        }
        else {
        int shp = 1;
        int a = 0; int w = 0; int i= 0;
        while ( n != 0 )
        {
            i++;
            if ( i >= 1 && i <= 2)
            {
            a = n % 10;
            w += a*shp;
            shp *= 10;
            }
            n /= 10;
        }
        n = w;
        if ( n < 10 )
        {
            cout << PreTen ( n );
        }
        int h;
        h = n;
        if ( n >= 10 && n < 20 )
        {
            cout << Sub10Pre20 ( n );
        }
        }
    }
}
