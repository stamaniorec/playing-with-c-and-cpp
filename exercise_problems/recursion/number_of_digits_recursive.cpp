#include <iostream>

using namespace std;

int num_of_digits(int n)
{
	if ( n == 0 )
	{
		return 0;
	}
	
	int counter = 0;
	counter++;

	return counter + num_of_digits(n/10);
}

int main()
{
	int n;

	cout << "Enter n: ";
	cin >> n;

	cout << num_of_digits(n) << endl;
	
	return 0;
}
