#include <iostream>

using namespace std;

void initialize_sieve_to_zeroes (bool sieve[], const long long number);
void set_sieve (bool sieve[], const long long number);
void utilize_sieve (bool sieve[], const long long number, long long *max);

int main()
{
	const long long number = 13195;
	long long max_prime_number = 0;
	
	bool sieve[number];
	// only works with small numbers
	// otherwise it gives a segmentation fault on this array for some reason
	
	initialize_sieve_to_zeroes(sieve, number);
	set_sieve(sieve, number);
	utilize_sieve(sieve, number, &max_prime_number);
	
	cout << max_prime_number << endl;

	return 0;
}

void initialize_sieve_to_zeroes (bool sieve[], const long long number)
{
	for ( long long i = 0; i < number; i++ )
	{
		sieve[i] = true;
	}
}

void set_sieve (bool sieve[], const long long number)
{
	for ( long long i = 2; i < number; i++ )
	{
		if (sieve[i] == true )
		{
			for ( long long j = i + i; j < number; j += i )
			{
				sieve[j] = false;
			}
		}
	}
}

void utilize_sieve (bool sieve[], const long long number, long long *max)
{
	for ( long long k = 2; k < number; k++ )
	{
		if ( sieve[k] == true )
		{
			if ( number % k == 0 )
			{
				*max = k;
			}
		}
	}
}
