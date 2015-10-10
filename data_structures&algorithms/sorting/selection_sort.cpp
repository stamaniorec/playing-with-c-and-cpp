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

// 5 4 3 2 1 
void sort(int array[], int size)
{
	int min;
	int index = 0;
	for(int i = 0; i < size; i++)
	{
		min = i;
		for(int j = i + 1; j < size; j++)
		{
			if(array[j] < array[min])
			{
				min = j;
			}
		}
		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

int main(int argc, char const *argv[])
{
	int array[5] = {5, 4, 3, 2, 1};
	int size = sizeof(array) / sizeof(int);
	sort(array, size);
	print_array(array, size);
	return 0;
}