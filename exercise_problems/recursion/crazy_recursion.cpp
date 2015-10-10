//F = n! / (1^n+2^n+3^n+...+n^n)
#include <iostream>

using namespace std;

int factorial(int n)
{
	if ( n == 1 )
		return 1;
	return n * factorial(n-1);
}

int a_to_power_n(int a, int n)
{
	if ( n == 1 )
		return a;
	return a * a_to_power_n(a, n-1);
}

int weird_function(int a, int b)
{
	if ( a == 1 )
		return 1;
	return a_to_power_n(a, b) + weird_function(a-1, b);
}

double my_function(int n)
{
	return (float)factorial(n) / weird_function(n, n);
}

int main()
{
	cout << my_function(3) << endl;
	return 0;
}
