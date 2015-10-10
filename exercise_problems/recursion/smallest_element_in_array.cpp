#include <iostream>

using namespace std;

int smallest_element(int array[], int length)
{
	static int smallest = array[length];

	if ( length < 0 )
		return 0;

	if ( array[length] < smallest )
		smallest = array[length];

	return smallest + smallest_element(array, length-1);
}

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	int length = sizeof(array) / sizeof(int);
	cout << "Smallest element: " << smallest_element(array, length - 1) << endl;

	return 0;
}
