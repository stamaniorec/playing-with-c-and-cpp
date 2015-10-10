#include <iostream>
#include <algorithm>

void print_arr(int *arr, int length)
{
	for(int i = 0; i < length; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int partition_array(int *arr, int start, int end)
{
	// srand(time(NULL));
	// int rand_index = (rand() % (end-start)) + start;
	int compare_value = arr[end-1];
	int pivot_index = start;
	
	for(int i = start; i < end-1; ++i)
	{
		if(arr[i] < compare_value)
		{
			std::swap(arr[i], arr[pivot_index++]);
		}
	}

	std::swap(arr[pivot_index], arr[end-1]);
	return pivot_index;
}

void quick_sort(int *arr, int start, int end)
{
	if(start >= end-1)
		return; 

	int pivot = partition_array(arr, start, end);
	quick_sort(arr, start, pivot);
	quick_sort(arr, pivot+1, end);
}

int main(int argc, char const *argv[])
{
	int arr[] = {5, 4, 3, 2, 1};
	int length = sizeof(arr) / sizeof(int);

	int arr2[] = {100,85,293,12,44,-50};
	int length2 = sizeof(arr2) / sizeof(int);

	int arr3[] = {7, 2, 1, 6, 8, 5, 3, 4};
	int length3 = sizeof(arr3) / sizeof(int);

	partition_array(arr, 0, length);
	print_arr(arr, length);
	quick_sort(arr, 0, length);
	print_arr(arr, length);
	std::cout << "--- --- ---" << std::endl;

	partition_array(arr2, 0, length2);
	print_arr(arr2, length2);
	quick_sort(arr2, 0, length2);
	print_arr(arr2, length2);
	std::cout << "--- --- ---" << std::endl;

	partition_array(arr3, 0, length3);
	print_arr(arr3, length3);
	quick_sort(arr3, 0, length3);
	print_arr(arr3, length3);
	std::cout << "--- --- ---" << std::endl;

	return 0;
}