#include <iostream>

#define GRAPH_SIZE 8

bool visited[GRAPH_SIZE] = {false};

// Standard DFS on a graph that marks every visited vertex
void mark_with_dfs(int graph[][GRAPH_SIZE], int vertex)
{
	visited[vertex] = true;
	for(int i = 0; i < GRAPH_SIZE; ++i)
	{
		if(graph[vertex][i] == 1 && !visited[i])
			mark_with_dfs(graph, i);
	}
}

// Given a graph, returns the number of connected components it has
int connected_components(int graph[][GRAPH_SIZE])
{
	int count = 0;

	// For every unvisited vertex in the graph 
	for(int i = 0; i < GRAPH_SIZE; ++i)
	{
		// Start a DFS that exhausts the current connected component
		if(!visited[i])
		{
			mark_with_dfs(graph, i);
			++count;
		}
	}

	return count;
}

int main(int argc, char const *argv[])
{
	// The following undirected graph has 3 connected components
	// 0   2   6   7
	// |\ /    |
	// | 4     |
	// |/      |
	// 1---3   5
	int graph[][GRAPH_SIZE] = {
		{0,1,0,0,1,0,0,0},
		{1,0,0,1,1,0,0,0},
		{0,0,0,0,1,0,0,0},
		{0,1,0,0,0,0,0,0},
		{1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,1,0},
		{0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,0}
	};

	std::cout << "The graph has " << connected_components(graph) 
				<< " connected components" << std::endl;

	return 0;
}