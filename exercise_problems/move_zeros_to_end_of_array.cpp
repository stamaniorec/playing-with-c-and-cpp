#include <iostream>

int main(int argc, char const *argv[])
{
	int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
	int size = sizeof(arr) / sizeof(int);

	// Find the first vacant spot in the array
	int first_zero_position;
	while(arr[++first_zero_position] != 0);

	// From there iterate till the end of the array
	for(int i = first_zero_position + 1; i < size; ++i)
	{
		// And if you see a filled spot
		if(arr[i] != 0)
		{
			// Move it to the known vacant spot
			arr[first_zero_position++] = arr[i];
			arr[i] = 0;
		}
	}

	// Finally, print the array
	for(int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	return 0;
}