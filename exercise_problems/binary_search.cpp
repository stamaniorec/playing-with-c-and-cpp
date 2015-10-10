#include <iostream>

using namespace std;

void bubble_sort(int array[], int length)
{
	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < length - i; j++)
		{
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

int binary_seach(int array[], int length, int search_value)
{
	int low = 0;
	int high = length;
	int mid;

	while(low <= high)
	{
		mid = (low + high) / 2;
		if(array[mid] == search_value)
		{
			return mid;
		}
		else if(array[mid] < search_value)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int array[] = {1, 341, 23, 94, 1823};
	int length = sizeof(array) / sizeof(int);
	
	bubble_sort(array, length);

	for (int i = 0; i < 5; ++i)
	{
		cout << array[i] << " ";
	}

	cout << endl << binary_seach(array, length, 1823) << endl;

	return 0;
}