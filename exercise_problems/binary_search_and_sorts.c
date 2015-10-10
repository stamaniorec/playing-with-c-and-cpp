#include <stdio.h>

void bubble_sort(int *array, int length)
{
	int i, j;
	for(i = 0; i < length; ++i)
	{
		for(j = 0; j < length - i -1; ++j)
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

void selection_sort(int *array, int length)
{
	int i, least, j;
	for(i = 0; i < length; ++i)
	{
		least = i;
		for(j = i; j < length; ++j)
		{
			if(array[j] < array[least])
			{
				least = j;
			}
		}
		int temp = array[i];
		array[i] = array[least];
		array[least] = temp;		
			
	}
}

void insertion_sort(int *array, int length)
{
	int i;
	for(i = 0; i <= length; ++i)
	{
		int j = i;
		while(j-- > 1 && array[j] < array[j-1])
		{
			int temp = array[j];
			array[j] = array[j-1];
			array[j-1] = temp;
		}
	}
}

// returns the index of the first occurance of the value that you're looking for 
// returns -1 if no value is found 
int binary_search(int *array, int length, int value)
{
	int low = 0;
	int high = length - 1;
	int last_occurance = -1;
	while(low <= high)
	{
		int middle = (low + high) / 2;
		if(array[middle] == value)
		{
			//return middle;
			last_occurance = middle;
			high = middle - 1;
		}
		else if(array[middle] < value)
		{
			low = middle + 1;
		}
		else
		{
			high = middle - 1;
		}
	}
	return last_occurance;
	//return -1;
}

// plain ol' binary search, this time recursive
int binary_search_recursive(int *array, int low, int high, int value)
{
	int middle = (low + high) / 2;
	if(low > high)
		return -1;
	if(array[middle] == value)
	{
		return middle;
	}
	else if(array[middle] < value)
	{
		return binary_search_recursive(array, middle+1, high, value);
	}
	else
	{
		return binary_search_recursive(array, low, middle-1, value);
	}
}

void print_array(int *array, int length)
{
	int i;
	for(i = 0; i < length; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 5, 3, 2, 4, 1, 4, 3, 2, 6, 2, 7 };
	int length = sizeof(arr) / sizeof(int);
	print_array(arr, length);

	bubble_sort(arr, length);
	//selection_sort(arr, length);
	//insertion_sort(arr, length);
	print_array(arr, length);

	printf("%d\n", binary_search(arr, length, 2));
	printf("%d\n", binary_search_recursive(arr, 0, length, 2));
	return 0;
}
