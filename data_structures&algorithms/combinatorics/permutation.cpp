#include <iostream>
#include <algorithm>

class Permutations
{
	std::string *set;
	int set_length;

	void print_current_permutation()
	{
		for(int i = 0; i < set_length; ++i)
			std::cout << set[i] << " ";
		std::cout << std::endl;
	}

	void permutations(int cur_index)
	{
		if(cur_index >= set_length)
		{
			print_current_permutation();
		}
		else
		{
			permutations(cur_index + 1);
			for(int i = cur_index + 1; i < set_length; ++i)
			{
				swap(set[i], set[cur_index]);
				permutations(cur_index + 1);
				swap(set[i], set[cur_index]);
			}
		}
	}
public:
	Permutations(std::string set[], int set_length) 
		: set(set), set_length(set_length) {};

	void print_permutations_without_repetition()
	{
		permutations(0);
	}
};

int main(int argc, char const *argv[])
{
	std::string set[] = { "a", "b", "c", "d", "e" };
	int set_length = sizeof(set) / sizeof(std::string);

	Permutations v(set, set_length);
	
	v.print_permutations_without_repetition();

	return 0;
}