#include <iostream>
#include <stack>

#define GRAPH_SIZE 6

void dfs_topological(int graph[][GRAPH_SIZE], int vertex, bool *visited, std::stack<int> &result)
{
	visited[vertex] = true;
	for(int i = 0; i < GRAPH_SIZE; ++i)
	{
		if(graph[vertex][i] && !visited[i])
		{
			dfs_topological(graph, i, visited, result);
		}
	}
	result.push(vertex);
}

void print_topological_sorting(int graph[][GRAPH_SIZE])
{
	bool visited[GRAPH_SIZE] = { false };
	std::stack<int> result;

	for(int i = 0; i < GRAPH_SIZE; ++i)
		if(!visited[i])
			dfs_topological(graph, i, visited, result);

	while(!result.empty())
	{
		std::cout << result.top() << " ";
		result.pop();
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	int graph[][GRAPH_SIZE] = {
		{0,0,0,0,0,0},
    	{0,0,0,0,0,0},
    	{0,0,0,1,0,0},
    	{0,1,0,0,0,0},
    	{1,1,0,0,0,0},
    	{1,0,1,0,0,0}
	};

	print_topological_sorting(graph);

	// Expect: 5 4 2 3 1 0 

	return 0;
}