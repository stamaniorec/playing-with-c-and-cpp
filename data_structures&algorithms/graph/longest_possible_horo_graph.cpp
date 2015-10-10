#include <iostream>
#include <map>
#include <set>

// Problem Statement: 
// You have a group of people and want to start a horo so you wonder what the longest possible horo could be.
// However, people are picky and are only willing to hold hands with their friends.
// If person A is a friend of person B, this means person B is a friend of person A.
// For convenience, people are given with just numbers, not names or anything else.
// You are given the number of friendships, the person leading the horo and a list of friendships.
// So, what's the longest possible horo?

std::set<int> visited;

// Returns whether a given set includes a number 
bool contains(std::set<int> set, int number)
{
	return set.find(number) != set.end();
}

// Returns the longest possible horo from the given graph
// Pretty much a standard DFS
int longest_horo(std::map< int, std::set<int> > graph, int person)
{
	int longest = 0;

	visited.insert(person);
	
	// Get an iterator pointing to the given person in the graph
	std::map< int, std::set<int> >::const_iterator vertex = graph.find(person);

	// For each of the unvisited adjacent vertices
	for(std::set<int>::const_iterator itr = vertex->second.begin(); itr != vertex->second.end(); ++itr)
	{
		if(!contains(visited, *itr))
		{
			// Try forming a horo and save the longest of all attempts
			int res = longest_horo(graph, *itr);
			if(res > longest) 
				longest = res; 
		}
	}

	visited.erase(person); // Not really needed 

	return 1 + longest;
}

// Test cases: 
// 8
// 1
// 1 2
// 1 3
// 4 5
// 7 8
// 1 7
// 7 9
// 8 11
// 4 1
// Expect: 4

// 10
// 1
// 6 5
// 7 4
// 4 1
// 5 8
// 5 3
// 9 8
// 3 5
// 7 4
// 2 3
// 9 5
// Expect: 3

// 16
// 2
// 3 3
// 2 1
// 9 2
// 3 6
// 6 1
// 8 2
// 9 8
// 9 5
// 1 6
// 8 7
// 5 7
// 9 2
// 1 2
// 4 7
// 6 9
// 9 5
// Expect: 7

int main(int argc, char const *argv[])
{
	// Read in the number of friendships
	int graph_size;
	std::cin >> graph_size;

	// Read in the person leading the horo
	int starting;
	std::cin >> starting;

	// The graph is represented with an adjacency list
	std::map< int, std::set<int> > graph;

	// For every friendship
	for(int i = 0; i < graph_size; ++i) 
	{
		// Read it
		int first, second;
		std::cin >> first >> second;

		// Add it both ways since it's an undirected graph 
		graph[first].insert(second);
		graph[second].insert(first);
	}

	std::cout << "longest possible horo " << longest_horo(graph, starting) << std::endl;

	return 0;
}