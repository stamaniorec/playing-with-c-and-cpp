#include <iostream>
#include <math.h>

using namespace std;

bool isPrime ( long long a )
{
    bool flag = true;

    for ( int i = 2; i <= sqrt(a); i++ )
    {
        if ( a % i == 0 )
        {
            flag = false;
            break;
        }
        flag = true;
    }

    if ( flag == true )
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    long long number = 600851475143;
    long long max_prime_number = 0;

	// the number is odd so we skip all even numbers
	// used to take forever to calculate
	// problem was in "i < number" -> way too many iterations for the computer to handle properly
    for ( long long i = 3; i <= sqrt(number); i += 2 ) 
    {
        if ( number % i == 0 )
        {
            if (isPrime(i))
            {
                max_prime_number = i;
            }
        }
    }

    cout << max_prime_number << endl;

    return 0;
}
