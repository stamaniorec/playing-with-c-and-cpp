#include <iostream>
#include <stack>
#include <algorithm>
#include <climits>

int main(int argc, char const *argv[])
{
	// int arr[] = {-3, 10, 15, -4, 1000, -1};
	// int size = sizeof(arr) / sizeof(int);
	// Answer: 1021

	// int arr[] = {-3, 10, 15, -5000, 1000, -1};
	// int size = sizeof(arr) / sizeof(int);
	// Answer: 1000

	// int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	// int size = sizeof(arr) / sizeof(int);
	// Answer: 7

	// int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
	// int size = sizeof(arr) / sizeof(int);
	// Answer: 7

	int arr[] = {-2, -5, -3, -6};
	int size = sizeof(arr) / sizeof(int);
	// Answer: -2
	
	int best[size+1];
	for(int i = 1; i <= size; ++i) best[i] = 0;
	best[0] = -INT_MIN/2;
	// INT_MIN doesn't work because the array may contain negative
	// numbers and thus overflow and give a wrong result

	int pred[size]; // predecessor array
	for(int i = 0; i < size; ++i) pred[i] = -1;

	// For every element in the array
	for(int i = 0; i < size; ++i)
	{
		// If you're better off with the stuff before,
		// mark the current element's predecessor as the previous element
		if(arr[i] < best[i]+arr[i] && i > 0)
			pred[i] = i-1;

		// Am I better off with the current value alone
		// or with the things before + the current element?
		best[i+1] = std::max(arr[i], best[i]+arr[i]);
	}

	// Find the solution and its index
	int cur_best = -10000, index = -1;
	for(int i = 1; i <= size; ++i) 
	{
		if(best[i] > cur_best)
		{
			cur_best = best[i];
			index = i-1;
		}
	}
	
	// Backtrack to find what subarray gives the answer
	std::stack<int>	s;
	while(true)
	{
		if(pred[index] == -1)
		{
			s.push(arr[index]);
			break;
		}
		
		s.push(arr[index]);
		index = pred[index];
	}
	
	while(!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << std::endl;

	std::cout << "Max cont sum: " << cur_best << std::endl;

	return 0;
}