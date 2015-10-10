#include <iostream>
#include <math.h>

using namespace std;

bool is_prime(int n)
{
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

int nth_prime(int n)
{
	int number_of_prime = 1;
	int number = 1;
	while(number_of_prime <= n)
	{
		number++;
		if(is_prime(number))
		{
			number_of_prime++;
		}
	}
	return number;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter n: ";
	cin >> n;
	cout << nth_prime(n) << endl;
	return 0;
}