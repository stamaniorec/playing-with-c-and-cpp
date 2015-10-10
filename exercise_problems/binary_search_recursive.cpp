#include <iostream>

using namespace std;

int binary_search(int array[], int search_value, int low, int high)
{
	int mid = (low + high) / 2;	
	if(array[mid] == search_value)
		return mid;
	if(low > high)
		return -1;
	if(array[mid] > search_value)
	{
		binary_search(array, search_value, low, mid-1);
	}
	else
	{
		binary_search(array, search_value, mid+1, high);
	}
}

int main(int argc, char const *argv[])
{
	int array[] = {1, 3, 5, 10, 100};
	int length = sizeof(array) / sizeof(int);
	cout << binary_search(array, 6, 0, length);
	return 0;
}