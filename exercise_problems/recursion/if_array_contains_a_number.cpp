#include <iostream>

// if array contains a number

using namespace std;

bool search_array(int array[], int value, int length)
{
	if ( array[length] == value )
		return true;

	if ( length == 0 )
		return false;
		
	return search_array(array, value, length-1);
}

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	int length = sizeof(array) / sizeof(int);

	cout << search_array(array, 6, length-1) << endl;
	return 0;
}
