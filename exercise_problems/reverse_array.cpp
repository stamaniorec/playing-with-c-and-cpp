#include <iostream>

using namespace std;

int main (int argc, char const* argv[])
{
	int array[5] = { 1, 2, 3, 4, 5 };
	int size = sizeof(array) / sizeof(int);
	int h = size / 2;
	for ( int i = 0; i < h; i++ )
	{
		int temp = array[i];
		array[i] = array[size-i-1];
		array[size-i-1] = temp;
	}
	for ( int j = 0; j < size; j++ )
	{
		cout << array[j] << " ";
	}
	return 0;
}

