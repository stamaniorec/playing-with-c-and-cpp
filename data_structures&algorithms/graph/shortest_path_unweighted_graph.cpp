#include <iostream>
#include <climits>
#include <queue>

#define GRAPH_SIZE 5

// Given an unweighted graph (either directed or undirected), a source and a destination
// Print the shortest path from source to destination
void print_shortest_path(int graph[][GRAPH_SIZE], int start, int end)
{
	// A map - what node (index) corresponds to what distance (value)
	int distance[GRAPH_SIZE];

	// Mark the distance 
	for(int i = 0; i < GRAPH_SIZE; ++i)
		distance[i] = INT_MAX;
	distance[start] = 0;

	// A map - from where (value) I got where (key)
	int prev[GRAPH_SIZE];
	for(int i = 0; i < GRAPH_SIZE; ++i)
		prev[i] = -1;

	// Avoid loops
	bool visited[GRAPH_SIZE] = { false };

	// Traverse the graph in a breadth-first manner
	std::queue<int> q;
	q.push(start);
	while(!q.empty())
	{
		int vertex = q.front();
		q.pop();

		visited[vertex] = true;

		// For every unvisited adjacent vertex
		for(int i = 0; i < GRAPH_SIZE; ++i)
		{
			if(graph[vertex][i] && !visited[i])
			{
				q.push(i);

				// Mark the adjacent vertex's parent as the current node 
				if(prev[i] == -1)
					prev[i] = vertex;
				
				// Only change the distance if it's shorter
				if(distance[vertex] + 1 < distance[i])
					distance[i] = distance[vertex] + 1;
				// The reason you need the check is because you can double-enqueue a vertex
				// And end up modifying its distance incorrectly
				// Instead of that check, you can check if the queue doesn't include the value
				// Or if distance[end] != INT_MAX

				// Also, to shorten the running time, 
				// you can break out of the whole thing if you reach the destination
				// Since we're doing BFS in an unweighted graph, 
				// we're guaranteed to reach the shortest path to destination first
				// I didn't do it for code clarity
			}
		}
	}

	// Print the result
	if(distance[end] == INT_MAX)
		std::cout << "The vertex " << end << " cannot be reached." << std::endl; 
	else
	{
		std::cout << "The shortest distance to vertex " << end << " is " << distance[end] << std::endl;

		std::cout << "The shortest path from vertex " << start << " to vertex " << end << " is the following: " << std::endl;

		// Prints in reverse order because I go from end to start
		int index = end;
		std::cout << end << " ";
		while(index != -1)
		{
			if(prev[index] != -1)
				std::cout << prev[index] << " ";
			index = prev[index];
		}
		std::cout << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	int graph[][GRAPH_SIZE] = {
		{0,1,0,1,0},
		{1,0,1,0,0},
		{0,1,0,0,1}, 
		{1,0,0,0,1},
		{0,0,1,1,0}
	};

	// 0 - 1 - 2

	// |       |
	
	// 3 ----- 4

	print_shortest_path(graph, 0, 4);
	
	return 0;
}