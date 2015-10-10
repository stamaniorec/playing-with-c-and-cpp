#include <iostream>
#include <map>

/*
               Fib 5
             /       \
        Fib 4         Fib 3
       /     \       /     \
  Fib 3    Fib 2  Fib 2     Fib 1
  ... ... ... ... ... ... ... ... ... 
  There are overlapping calls to the fibonacci function.
  The time complexity is O(2^n)
*/

/*
	I could have used an array instead of a hashmap. 
	However, this optimization is important only if working 
	with big numbers, and if this is the case, an array would 
	waste way too much memory.
*/
std::map<int,int> cache;

// Helper function that returns whether the global hashmap contains a given value
bool map_contains_element(int n)
{
	std::map<int,int>::const_iterator itr = cache.find(n);
	return itr != cache.end();
}

int fibonacci(int n)
{
	if(n <= 2)
		return 1;

	if(map_contains_element(n)) // Do not call the function more than needed
		return cache[n];
	else
	{
		cache[n] = fibonacci(n-1) + fibonacci(n-2);
		return cache[n];
	}
}

int main(int argc, char const *argv[])
{
	int n;

	std::cout << "Enter n: ";
	std::cin >> n;

	std::cout << "The " << n << "-th Fibonacci number is " << fibonacci(n) << std::endl;

	return 0;
}