#include <iostream>

using namespace std;

void print_binary(int number)
{
	if ( number == 0 )
		return;

	print_binary(number/2);

	cout << number % 2;

}

int main()
{
	int number;
	
	cout << "Enter number: ";
	cin >> number;

	print_binary(number);

	return 0;
}
