#include <iostream>

class VariationWithoutRepetition
{
	std::string *set;
	int k;
	int set_length;

	std::string *variation;
	bool *used;

	void print_current_variation()
	{
		for(int i = 0; i < k; ++i)
			std::cout << variation[i] << " ";
		std::cout << std::endl;
	}

	void variation_without_repetition(int cur_index)
	{
		if(cur_index >= k)	
		{
			print_current_variation();
		}
		else
		{
			for(int i = 0; i < set_length; ++i)
			{
				if(!used[i])
				{
					variation[cur_index] = set[i];
					used[i] = true;
					variation_without_repetition(cur_index + 1);
					used[i] = false;
				}
			}
		}
	}
public:
	VariationWithoutRepetition(std::string set[], int k, int set_length) 
		: set(set), k(k), set_length(set_length), variation(new std::string[k]), used(new bool[k]) {};

	void print_variation_without_repetition()
	{
		variation_without_repetition(0);
	}

	~VariationWithoutRepetition()
	{
		delete[] variation;
		delete[] used;
	}
};

int main(int argc, char const *argv[])
{
	std::string set[] = { "a", "b", "c", "d", "e" };
	int set_length = sizeof(set) / sizeof(std::string);

	VariationWithoutRepetition v(set, 3, set_length);
	
	v.print_variation_without_repetition();

	return 0;
}