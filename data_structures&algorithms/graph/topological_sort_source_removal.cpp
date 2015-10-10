#include <iostream>

#define GRAPH_SIZE 4

int main(int argc, char const *argv[])
{
	int graph[][GRAPH_SIZE] = {
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1},
		{0,0,0,0}
	};
	// Size: 4
	// Expect: 0 1 2 3 

	// int graph[][GRAPH_SIZE] = { 
	// 	{0,1,0,1,0,0},
	// 	{0,0,1,0,0,0},
	// 	{0,0,0,1,1,0},
	// 	{0,0,0,0,1,0},
	// 	{0,0,0,0,0,0},
	// 	{0,0,0,0,0,0}
	// };
	// Size: 6
	// Expect: 0 1 2 3 4 5

	// int graph[][GRAPH_SIZE] = {
	// 	{0,0,0,0,0,0},
 //    	{0,0,0,0,0,0},
 //    	{0,0,0,1,0,0},
 //    	{0,1,0,0,0,0},
 //    	{1,1,0,0,0,0},
 //    	{1,0,1,0,0,0}
	// };
	// Size: 6
	// Expect: 4 5 0 2 3 1 

	// Step 1: Identify all vertices with no incoming edges. 

	// Create an indegree array to keep track of that and initialize it to 0
	int indegree[GRAPH_SIZE];
	for(int i = 0; i < GRAPH_SIZE; ++i) indegree[i] = 0;

	// Initialize it accordingly by traversing the graph
	for(int col = 0; col < GRAPH_SIZE; ++col)
	{
		for(int row = 0; row < GRAPH_SIZE; ++row)
		{
			if(graph[row][col])
				++indegree[col];
		}
	}

	// For a topological sort, we need a DAG - Directed Acyclic Graph
	// If the indegree array has no member with indegree 0, then the graph is cyclic.
	bool has_indegree_0 = false;
	for(int i = 0; i < GRAPH_SIZE; ++i)
	{
		if(!indegree[i])
		{
			has_indegree_0 = true;
			break;
		}
	}
	if(!has_indegree_0)
	{
		std::cout << "The graph is cyclic, topological sort isn't possible." << std::endl;
		return 0;
	}

	// A topological sort includes all vertices, hence the loop condition
	for(int i = 0; i < GRAPH_SIZE; ++i)
	{
		// Find a vertex with no incoming edges (indegree 0)
		for(int j = 0; j < GRAPH_SIZE; ++j)
		{
			if(indegree[j] == 0)
			{
				// Process it, in this case print it to the screen
				std::cout << j << " ";

				// Instead of keeping a visited array, mark it in this way
				indegree[j] = -1;

				// Update the indegree array - "remove" all edges from the current vertex
				for(int k = 0; k < GRAPH_SIZE; ++k)
				{
					if(graph[j][k])
					{
						--indegree[k];
					}
				}
			}	
		}
	}

	std::cout << std::endl;

	return 0;
}