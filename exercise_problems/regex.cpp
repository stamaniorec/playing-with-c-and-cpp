#include <iostream>
#include <string>

bool is_letter(char character)
{
	return ((character >= 'a' && character <= 'z') || 
		(character >= 'A' && character <= 'Z'));
}

bool is_match(std::string string, std::string pattern)
{
	int cur_index_s = 0;
	bool match = true;

	for(int i = 0; i < pattern.length(); ++i)
	{
		if(is_letter(pattern[i]))
		{
			if(i+1 < pattern.length())
			{
				if(pattern[i+1] == '*')
				{
					while(string[cur_index_s] == pattern[i])
					{
						++cur_index_s;
					}
				} 
				else 
				{
					if(string[cur_index_s] != pattern[i])
					{
						match = false;
						break;
					}
					else
					{
						++cur_index_s;
					}
				}
			}
			else
			{
				if(string[cur_index_s] != pattern[i] || 
					cur_index_s < string.length()-1)
				{
					match = false;
				}
			}
		}
		else if(pattern[i] == '*')
		{
			continue;
		}
		else if(pattern[i] == '.')
		{
			if(i+1 < pattern.length())
			{
				if(pattern[i+1] == '*')
				{
					break;
				} 
				else 
				{
					++cur_index_s;
				}
			}
		}
	}

	return match;
}

int main(int argc, char const *argv[])
{
	std::string string, pattern;
	std::cin >> string >> pattern; 

	std::cout << is_match(string, pattern) << std::endl;

	return 0;
}