#include <iostream>

using namespace std;

bool if_elements_are_different(int array[], int length)
{
	int value = array[length];
	
	if ( length == 0 )
		return false;

	if ( value != array[length-1])
		return true;
	
	return if_elements_are_different(array, length-1);
}

int main()
{
	int array[] = {3, 3, 3};
	int length = sizeof(array) / sizeof(int);
	
	cout << if_elements_are_different(array, length - 1) << endl;
}
