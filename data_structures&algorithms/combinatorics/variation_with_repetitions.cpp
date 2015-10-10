#include <iostream>

class VariationWithRepetition
{
	std::string *set;
	int k;
	int set_length;

	std::string *variation;

	void print_current_variation()
	{
		for(int i = 0; i < k; ++i)
			std::cout << variation[i] << " ";
		std::cout << std::endl;
	}

	void variation_with_repetition(int cur_index)
	{
		if(cur_index >= k)
		{
			print_current_variation();
		}
		else
		{
			for(int i = 0; i < set_length; ++i)
			{
				variation[cur_index] = set[i];
				variation_with_repetition(cur_index + 1);
			}
		}
	}
public:
	VariationWithRepetition(std::string set[], int k, int set_length) 
		: set(set), k(k), set_length(set_length), variation(new std::string[k]) {};

	void print_variation_with_repetition()
	{
		variation_with_repetition(0);
	}

	~VariationWithRepetition()
	{
		delete[] variation;
	}
};

int main(int argc, char const *argv[])
{
	std::string set[] = { "a", "b", "c", "d", "e" };
	int set_length = sizeof(set) / sizeof(std::string);

	VariationWithRepetition v(set, 3, set_length);
	
	v.print_variation_with_repetition();

	return 0;
}