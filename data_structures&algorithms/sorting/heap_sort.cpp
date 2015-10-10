#include <iostream>
#include <algorithm>
#include <vector>

// Sift down = Heapify
void sift_down(int *arr, int length, int start)
{
	int cur = start; // the "node" we heapify from

	// Keep going until you hit the nodes without children - index magic
	// either that or that-1 but this works
	while(cur < length / 2)
	{
		int left = 2*cur + 1;
		int right = 2*cur + 2;

		int greater = left;
		if(left > length)
			break;

		if(right < length && arr[right] > arr[left])
			greater = right;

		if(arr[greater] < arr[cur])
			break;
		else
		{
			std::swap(arr[cur], arr[greater]);
			cur = greater;
		}
	}
}

void build_maxheap(int *arr, int length)
{
	for(int i = length/2; i >= 0; --i)
	{
		sift_down(arr, length, i);
	}
}

void heap_sort(int *arr, int length)
{
	for(int i = length-1; i >= 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        sift_down(arr, i, 0);
    }	

	// std::vector<int> v(arr, arr+length);
	// for(int i )
}

int main(int argc, char const *argv[])
{
	// int arr[] = {1, 2, 3, 4, 5};
	// int arr[] = {5, 4, 3, 2, 1};
	int arr[] = {6, 5, 4, 3, 2, 1};

	int length = sizeof(arr) / sizeof(int);

	build_maxheap(arr, length);
	// std::vector<int> bar(arr, arr+length);
	// if(std::is_heap(bar.begin(),bar.end()))
	// 	std::cout << "successful" << std::endl;
	// else
	// 	std::cout << "unsuccessful" << std::endl;
	heap_sort(arr, length);

	// std::vector<int> foo(arr, arr+length);
	// if(std::is_heap(foo.begin(),foo.end()))
	// 	std::cout << "successful" << std::endl;
	// else
	// 	std::cout << "unsuccessful" << std::endl;

	for(int i = 0; i < length; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}