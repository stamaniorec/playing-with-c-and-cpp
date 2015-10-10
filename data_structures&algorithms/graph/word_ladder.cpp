#include <iostream>
#include <set>
#include <algorithm>
#include <climits>

// This is the classical word ladder problem. 
// The player is given a start word and an end word. 
// In order to win the game, the player must change the start word into the end word progressively, 
// creating an existing word at each step. 
// Each step consists of a single letter substitution.
// e.g. COLD → CORD → CARD → WARD → WARM

// Note about the solution:
// Uses a DFS, while a BFS would be more appropriate
// Maybe exactly for this reason the program doesn't work with big datasets
// It works correctly for smaller datasets though

bool set_contains(std::set<std::string> &dictionary, std::string word)
{
	return std::find(dictionary.begin(), dictionary.end(), word) != dictionary.end();
}

// Returns the length of the shortest transformation sequence from start to end
// Returns INT_MAX if the transformation isn't possible
int word_ladder(std::string cur_word, std::string target_word, 
	std::set<std::string> &dictionary_of_valid_words, 
	std::set<std::string> &visited, 
	int transformations)
{
	// Base case for the recursion
	if(cur_word == target_word)
		return transformations;

	visited.insert(cur_word);

	// Holds the length of the shortest transformation sequence
	int min = INT_MAX;

	// Generate every possible "adjacent" word (i.e. different by only one letter)
	for(int i = 0; i < cur_word.length(); ++i)
	{
		for(char letter = 'a'; letter <= 'z'; ++letter)
		{
			// Create a new string instead of modifying the current one 
			// so that you don't mess up the letter changing
			std::string new_word(cur_word);
			new_word[i] = letter;

			// If the generated sequence of letters is an actual word and it hasn't been processed before 
			if(set_contains(dictionary_of_valid_words, new_word) && !set_contains(visited, new_word))
			{
				// Check to see if you can reach the end word from it by considering whether the returned value 
				// is smaller than INT_MAX (see the base case)
				min = std::min(min, 
					word_ladder(new_word, target_word, dictionary_of_valid_words, visited, transformations + 1)
				);
			}
		}
	}

	visited.erase(cur_word);

	return min;
}

int main(int argc, char const *argv[])
{
	// Read the start word
	std::string start_word;
	getline(std::cin, start_word);

	// Read the end word
	std::string end_word;
	getline(std::cin, end_word);

	// Read the dictionary of words
	std::set<std::string> dictionary_of_valid_words;
	std::string cur_word;
	while(getline(std::cin, cur_word))
	{
		// The end of output is signified by a blank line
		if(cur_word.empty())
			break;

		dictionary_of_valid_words.insert(cur_word);
	}

	std::set<std::string> visited;

	std::cout << "fewest number of transformations: " 
				<< word_ladder(start_word, end_word, dictionary_of_valid_words, visited, 0) 
				<< std::endl;

	return 0;
}

// As mentioned previously, doesn't work with big datasets, so here are some smaller ones
// loving
// hating
// dromon
// uncork
// abides
// loving
// ptisan
// hating
// obtain
// halted
// jazzer
// laving
// having
// gelant
// pterin
// droned
// uncurb
// 
// Expect: 3

// cat
// but
// any
// ate
// cut
// kas
// but
// cat
// sat
// kit
// sit
// rec
// kaf
// kat
// pub
// pud
// 
// Expect: 2

// vikings
// program
// program
// abasers
// zyzzyva
// aerated
// observe
// vikings
// mobster
// mochila
// mockers
// stewbum
// stewing
// zoysias
// 
// Expect: INT_MAX

// hit
// cog
// hot
// dot
// dog
// lot
// log
// cog
// 
// Expect: 4
