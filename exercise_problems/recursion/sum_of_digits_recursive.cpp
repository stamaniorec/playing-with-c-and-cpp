#include <iostream>

using namespace std;

int sum_of_digits(int n)
{
	if ( n == 0 )
	{
		return 0;
	}

	int digit = n % 10;
	
	return digit + sum_of_digits(n/10);
}

int main()
{
	int n;

	cout << "Enter n: ";
	cin >> n;

	cout << sum_of_digits(n) << endl;

	return 0;
}
