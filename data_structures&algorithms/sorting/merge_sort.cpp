#include <iostream>

void print_arr(int *arr, int length)
{
	for(int i = 0; i < length; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void merge(int *array, int length, int *first, int first_length, int *second, int second_length)
{
	int head_first = 0;
	int head_second = 0;
	for(int i = 0; i < length; ++i)
	{
		if(head_second < second_length)
		{
			if(head_first < first_length)
			{
				if(first[head_first] < second[head_second])
				{
					array[i] = first[head_first++];
				}
				else
				{
					array[i] = second[head_second++];
				}
			}
			else
			{
				array[i] = second[head_second++];
			}
		}
		else
		{
			array[i] = first[head_first++];
		}
	}
}

void merge_sort(int *arr, int length)
{
	if(length <= 1)
		return; 

	int mid = length / 2;
	int *left = new int[mid];
	int *right = new int[length-mid];
	for(int i = 0; i < mid; ++i)
	{
		left[i] = arr[i];
	}
	for(int i = mid; i < length; ++i)
	{
		right[i-mid] = arr[i];
	}
	
	merge_sort(left, mid);
	merge_sort(right, length-mid);
	merge(arr, length, left, mid, right, length-mid);
}

int main(int argc, char const *argv[])
{
	int arr[] = {9, 8, 8, 7, 6, 5, 5, 4, 3, 2, 1};
	int length = sizeof(arr) / sizeof(int);

	merge_sort(arr, length);

	print_arr(arr, length);

	return 0;
}