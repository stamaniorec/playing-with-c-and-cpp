#include <iostream>

int recursive(int *arr, int size, int key, int low, int high)
{
	if(low > high)
		return 0;

	int mid = (low + high) / 2;
	
	if(arr[mid] > key)
		return recursive(arr, size, key, low, mid-1);
	else if(arr[mid] < key)
		return recursive(arr, size, key, mid+1, high);
	else
		return 1 + recursive(arr, size, key, low, mid-1) + recursive(arr, size, key, mid+1, high);
}

// Standard binary search
int iterative_binary_search(int *arr, int size, int key)
{
	int low = 0;
	int high = size;
	while(low <= high)
	{
		int mid = (low + high) / 2;
		if(arr[mid] == key)
			return mid;
		else if(arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int iterative(int *arr, int size, int key)
{
	int binary_search_index = iterative_binary_search(arr, size, key);
	
	int count = (binary_search_index != -1);

	int left = binary_search_index - 1;
	while(arr[left--] == key) ++count;
	
	int right = binary_search_index + 1;
	while(arr[right++] == key) ++count;
	
	return count;
}

int main(int argc, char const *argv[])
{
	int arr[] = {4, 4, 8, 8, 8, 15, 16, 23, 23, 42};
	int size = sizeof(arr) / sizeof(int);

	std::cout << "num of occurrences of 8 is " << recursive(arr, size, 8, 0, size) << std::endl; // 3
	std::cout << "num of occurrences of 4 is " << recursive(arr, size, 4, 0, size) << std::endl; // 2
	std::cout << "num of occurrences of 15 is " << recursive(arr, size, 15, 0, size) << std::endl; // 1
	std::cout << "num of occurrences of 16 is " << recursive(arr, size, 16, 0, size) << std::endl; // 1
	std::cout << "num of occurrences of 23 is " << recursive(arr, size, 23, 0, size) << std::endl; // 2
	std::cout << "num of occurrences of 42 is " << recursive(arr, size, 42, 0, size) << std::endl; // 1
	std::cout << "num of occurrences of 142 is " << recursive(arr, size, 142, 0, size) << std::endl; // 0

	std::cout << "num of occurrences of 8 is " << iterative(arr, size, 8) << std::endl; // 3
	std::cout << "num of occurrences of 4 is " << iterative(arr, size, 4) << std::endl; // 2
	std::cout << "num of occurrences of 15 is " << iterative(arr, size, 15) << std::endl; // 1
	std::cout << "num of occurrences of 16 is " << iterative(arr, size, 16) << std::endl; // 1
	std::cout << "num of occurrences of 23 is " << iterative(arr, size, 23) << std::endl; // 2
	std::cout << "num of occurrences of 42 is " << iterative(arr, size, 42) << std::endl; // 1
	std::cout << "num of occurrences of 142 is " << iterative(arr, size, 142) << std::endl; // 0

	return 0;
}