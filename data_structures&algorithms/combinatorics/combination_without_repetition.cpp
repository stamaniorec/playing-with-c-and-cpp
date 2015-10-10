#include <iostream>

class CombinationWithoutRepetition
{
	std::string *set;
	int k;
	int set_length;

	std::string *combination;

	void print_current_combination()
	{
		for(int i = 0; i < k; ++i)
			std::cout << combination[i] << " ";
		std::cout << std::endl;
	}

	void combination_without_repetition(int cur_index, int start_set_index)
	{
		if(cur_index >= k)
		{
			print_current_combination();
		}
		else
		{
			for(int i = start_set_index; i < set_length; ++i)
			{
				combination[cur_index] = set[i];
				combination_without_repetition(cur_index + 1, i + 1);
			}
		}
	}
public:
	CombinationWithoutRepetition(std::string set[], int k, int set_length) 
		: set(set), k(k), set_length(set_length), combination(new std::string[k]) {};

	void print_combination_without_repetition()
	{
		combination_without_repetition(0, 0);
	}

	~CombinationWithoutRepetition()
	{
		delete[] combination;
	}
};

int main(int argc, char const *argv[])
{
	std::string set[] = { "a", "b", "c", "d", "e" };
	int set_length = sizeof(set) / sizeof(std::string);

	CombinationWithoutRepetition v(set, 3, set_length);
	
	v.print_combination_without_repetition();

	return 0;
}