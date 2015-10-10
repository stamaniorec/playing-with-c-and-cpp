#include <iostream>
#include <string>

using namespace std;

int PrimeFactorsSum ( int, int );
int If_Sum_Is_Prime ( int );

int main ()
{
    int a;
    for ( int i = 1; i <= 100; i++ )
    {
        a = 0;
        for ( int j = 1; j <= i; j++ )
        {
            a += PrimeFactorsSum ( i, j );
        }
        // cout << a << endl;
        if ( If_Sum_Is_Prime ( a ) == 1 )
        {
            cout << i << endl;
        }
        /*cout << i << endl;
        cout << If_Sum_Is_Prime ( a ) << endl;*/
    }
    return 0;
}

int PrimeFactorsSum ( int i, int j )
{
    int prime = 0;
    bool stuff = false;
    int sum = 0;
    if ( i % j == 0 )
    {
        prime = j;
        stuff = true;
    }
    if ( stuff == true )
    {
        sum += prime;
    }
    return sum;
}

int If_Sum_Is_Prime ( int a )
{
    int mah_bool = 1;
    int k = 0;
    for ( int i = 2; i <= a/2; i++ )
    {
        k = a % i;
        if ( k == 0 )
        {
            mah_bool = 0;
            break;
        }
    }
    if ( mah_bool == 0 )
    {
        return false;
    }
    else
    {
        return true;
    }
}
