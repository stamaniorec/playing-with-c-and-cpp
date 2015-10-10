#include <iostream>

using namespace std;

int factorial(int n)
{
	int factorial = 1;
	while ( n > 1 )
	{
		factorial *= n;
		n--;
	}
	return factorial;
}

int power(int a, int b)
{
	int i = 0;
	int result = 1;
	while ( i < b )
	{
		result *= a;
		i++;
	}
	return result;
}

int weird_function(int n)
{
	int result = 0;
	for ( int i = 1; i <= n; i++ )
	{
		result += (power(i, n));
	}
	return result;
}

float function(int n)
{
	return (float)factorial(n) / weird_function(3);
}

int main()
{
	cout << function(4);
	
	return 0;
}
