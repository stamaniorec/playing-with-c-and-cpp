#include <iostream>

using namespace std;

int first_occurance(int array[], int length, int value)
{
	int low = 0; 
	int high = length - 1;
	int mid;
	int result = -1;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(array[mid] == value)
		{
			result = mid;
			high = mid - 1;
		}
		else if(array[mid] < value)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int num_of_elements, search_value, tests;
	cin >> tests;
	for(int t = 0; t < tests; t++)
	{
		cin >> num_of_elements;
		cin >> search_value;
		int *array = new int[num_of_elements];
		for(int i = 0; i < num_of_elements; i++)
		{
			cin >> array[i];
		}
		cout << first_occurance(array, num_of_elements, search_value) << endl;
		delete[] array;
	}
	return 0;
}