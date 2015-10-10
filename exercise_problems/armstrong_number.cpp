#include <iostream>

using namespace std;

/*
 * An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
 * Examples: 153, 370, 371, 407
*/

int power(int base, int exponent)
{
	if ( exponent == 0 )
		return 1;
	return base * power(base, exponent-1);
}

bool is_armstrong(int n)
{
	int number_of_digits = 0;
	int temp = n;
	int sum = 0;
	
	while ( temp != 0 )
	{
		number_of_digits++;
		temp /= 10;
	}

	temp = n;

	while ( temp != 0 )
	{
		sum += power(temp%10, 3);
		temp /= 10;
	}

	if ( sum == n )
		return true;
	else
		return false;
}

int main()
{
	int number;
	
	cout << "Enter number: ";
	cin >> number;

	cout << is_armstrong(number) << endl;

	return 0;
}
