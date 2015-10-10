#include <iostream>

using namespace std;

void print_array(int array[], int index)
{
	cout << array[index];
	
	if ( index < 4 )
	{
		print_array(array, index+1);
	}	
	else return;
}

void print_reverse(int array[], int length)
{
	if ( length < 0 )
	{
		return;
	}
	else
	{
		cout << array[length];
		print_reverse(array, length-1);
	}

}

int main()
{
	const int length = 5;
	int array[length] = { 1, 2, 3, 4, 5 };
	int index = 0;

	print_array(array, index);

	cout << endl;
	
	print_reverse(array, length-1);

	return 0;
}
