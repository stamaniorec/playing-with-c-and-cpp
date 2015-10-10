#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

void all_primes ( )
{
    cout << "Enter n: ";
    int n;
    cin >> n;
    bool boolean = true;
    for ( int i = 2; i <= n; i++ )
    {
        for ( int j = 2; j < i; j++ )
        {
            if ( i % j == 0 )
                boolean = false;
        }
        if ( boolean == true )
            cout << i << " ";
        boolean = true;
    }
    cout << endl;
}

void nth_prime ()
{
    cout << "Enter n: ";
    int n;
    cin >> n;
    bool boolean = true;
    int k = 0;
    for ( int i = 2; i <= 1000; i++ )
    {
        for ( int j = 2; j < i; j++ )
        {
            if ( i % j == 0 )
                boolean = false;
        }
        if ( boolean == true )
            k++;
        boolean = true;
        if ( k == n )
        {
            cout << i << endl;
            break;
        }
    }
}

int main ( )
{
    int user_choice;
    cout << "1. All prime numbers from 1 to n" << endl;
    cout << "2. n-th prime from 1 to n" << endl;
    while ( 1 )
    {
        cin >> user_choice;
        if ( user_choice == 1 )
        {
            all_primes();
            break;
        }
        else if ( user_choice == 2 )
        {
            nth_prime();
            break;
        }
        else
        {
            cout << "Error, please try again. \n";
        }
    }
    return 0;
}
