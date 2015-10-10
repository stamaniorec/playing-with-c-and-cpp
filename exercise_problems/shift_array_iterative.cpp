#include <iostream>

using namespace std;

void shift_array(int array[], int size)
{
	int static count = -1;
	count++;
	for(int i = size - 1; i >= 0; i--)
	{
		if(array[i])
		{
			array[i+1] = array[i];
		}
	}
	array[count] = 0;
}

void print_array(int array[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int array[] = {1, 2, 3, 0, 0};
	int size = sizeof(array) / sizeof(int);
	shift_array(array, size);
	print_array(array, size);
	shift_array(array, size);
	print_array(array, size);
	return 0;
}