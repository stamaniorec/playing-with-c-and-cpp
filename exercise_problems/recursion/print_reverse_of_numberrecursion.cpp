#include <iostream>

using namespace std;

void print_reverse(int number)
{
	if ( number == 0 )
		return;

	cout << number % 10;
	
	return print_reverse(number/10);
}

int main()
{
	int number;
	
	cout << "Enter number: ";
	cin >> number;
	
	print_reverse(number);

	return 0;
}
