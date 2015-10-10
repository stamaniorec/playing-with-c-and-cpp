#include <iostream>
#include <algorithm>

// The solution suggested at GeeksForGeeks, 
// translated from C to C++ 
void print_permutations(std::string str, int index) {
	if(index >= str.length())
	{
		std::cout << str << std::endl;
		return;
	}

	for(int i = index; i < str.length(); ++i) {
		std::swap(str[index], str[i]);
		print_permutations(str, index + 1);
		std::swap(str[index], str[i]);
	}
}

// The standard algorithm for generating permutations without repetitions
void standard(std::string str, int index)
{
	if(index >= str.length())
	{
		std::cout << str << std::endl;
		return;
	}

	standard(str, index + 1);
	for(int i = index+1; i < str.length(); ++i)
	{
		std::swap(str[index], str[i]);
		standard(str, index + 1);
		std::swap(str[index], str[i]);
	}
}

int main(int argc, char const *argv[])
{
	std::string str("ABC");

	print_permutations(str, 0);
	std::cout << "------------------------------" << std::endl;
	standard(str, 0);

	// Expected: ABC, ACB, BAC, BCA, CBA, CAB

	return 0;
}