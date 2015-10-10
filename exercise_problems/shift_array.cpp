#include <iostream>

using namespace std;

void shift_array(int array[], int size, int index)
{
	int first_element = array[index];
	if(array[index] == 0)
	{
		return;
	}
	shift_array(array, size, index+1);
	array[index+1] = array[index];
	if(!index)  
		array[index] = 0;
	if(array[index] == first_element)
		array[index] = 0;
}

// 1 2 3 0 0
// 0 1 2 3 0 
// 0 0 1 2 3  
int main(int argc, char const *argv[])
{
	int array[] = {1, 2, 3, 0, 0};
	int size = sizeof(array) / sizeof(int);
	int index = 0;
	shift_array(array, size, index);
	index++;
	shift_array(array, size, index);
	for(int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}