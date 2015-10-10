#include <iostream>

bool contains(int arr[], int num, int cur_index, int length)
{
	if(cur_index >= length)
		return false;
	return (arr[cur_index] == num) || contains(arr, num, cur_index+1, length);
}

int main(int argc, char const *argv[])
{
	int arr[] = {1, 2, 3, 4, 5};
	int num = 6;
	int length = sizeof(arr) / sizeof(int);
	std::cout << num << "? -> " << contains(arr, num, 0, length) << std::endl; 
	return 0;
}