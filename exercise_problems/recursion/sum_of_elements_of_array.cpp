#include <iostream>

using namespace std;

int sum_of_elements(int array[], int length)
{
	int sum = 0;
	
	if ( length < 0 )
		return 0;

	sum += array[length];

	return sum + sum_of_elements(array, length - 1);
}

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	int length = sizeof(array) / sizeof(int);

	cout << sum_of_elements(array, length - 1) << endl;

	return 0;
}
