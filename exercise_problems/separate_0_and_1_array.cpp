#include <iostream>

int main(int argc, char const *argv[])
{
	int arr[] = {0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1};
	int size = sizeof(arr) / sizeof(int);

	int left = 0;
	int right = size - 1;

	// Keep moving from left to right
	while(++left < right)
	{
		// And if you see a 1
		if(arr[left] == 1)
		{
			// Make it a 0
			arr[left] = 0;
			
			// And find the first vacant spot from the end of the array
			while(arr[right] != 0) right--;
			
			// So that you "move" the 1 there
			arr[right] = 1;
		}
	}

	// Finally, print the array
	for(int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	return 0;
}