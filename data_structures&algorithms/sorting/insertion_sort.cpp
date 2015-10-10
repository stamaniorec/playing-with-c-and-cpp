#include <iostream>

using namespace std;

void print_array(int array[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void sort(int array[], int size)
{
	// 5 4 3 2 1 
	int hole, value;
	for(int i = 0; i < size; i++)
	{
		value = array[i];
		hole = i;
		while(hole > 0 && array[hole-1] > value)
		{
			array[hole] = array[hole-1];
			hole--;
		}
		array[hole] = value;
	}
}

int main(int argc, char const *argv[])
{
	int array[] = {5, 4, 3, 2, 1};
	int size = sizeof(array) / sizeof(int);
	sort(array, size);
	print_array(array, size);
	return 0;
}