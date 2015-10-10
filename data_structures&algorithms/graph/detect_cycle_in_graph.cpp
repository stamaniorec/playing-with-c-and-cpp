#include <iostream>

#define NUM_VERTICES 3

bool visited[NUM_VERTICES] = { false };

// Returns whether a given UNDIRECTED graph, represented with an 
// adjacency matrix contains a cycle or not.
// This was my initial naive solution, works with a standard DFS.
bool has_cycle(int graph[][NUM_VERTICES], int start_vertex)
{
	// Mark the current vertex as visited
	visited[start_vertex] = true;

	// Go through every vertex adjacent to the current one
	for(int i = 0; i < NUM_VERTICES; ++i)
	{
		if(graph[start_vertex][i])
		{
			// The moment you encounter a visited node in an UNDIRECTED graph
			// you know you have a cycle!
			if(visited[i])
				return true;
			// Recursively check for the adjacent vertices (DFS)
			else
				// If either of them has a cycle, the graph has a cycle
				if(has_cycle(graph, i)) 
					return true;
		}
	}

	// If no cycle has been found after the DFS, no cycle exists
	return false;
}

// This case proves that my initial solution does not work for directed graphs.
// It's a bit of a trick case, but it's there.
// Consider the following case: 
//     0 -----> 2
//    /         |
//   V          |
//   1 <--------|
    
//      0 1 2
//    --------
//   0|(0 1 1)
//   1|(0 0 0)
//   2|(0 1 0)

// With an added edge from 1 to 2 -> now there is a cycle
//      0 1 2
//    --------
//   0|(0 1 1)
//   1|(0 0 1)
//   2|(0 1 0)

// With an added edge from 2 to 0 -> again, there is a cycle
//      0 1 2
//    --------
//   0|(0 1 1)
//   1|(0 0 0)
//   2|(1 1 0)

// This graph has two connected components - the lonely 0 and the connected couple 1-2
//      0 1 2
//    --------
//   0|(0 0 0)
//   1|(0 0 1)
//   2|(0 1 0)

// This graph also has two connected components but there is no cycle
//      0 1 2
//    --------
//   0|(0 0 0)
//   1|(0 0 1)
//   2|(0 0 0)

// A directed graph has a cycle if and only if there is a back edge present in the graph.
// A back edge is an edge from a vertex to either itself,
// or to one of its ancestors in the the recursion tree produced by the DFS.

// For example, if you start a DFS from vertex 0 and get to 5
// the edge 5->0 is a back edge because it directs you to a vertex not simply visited before,
// as this does not guarantee a cycle in a directed graph, but to a vertex visited before in the recursion tree.
// 0 -> 1 -> 2 -> 3 -> 4 -> 5
//  \                      /
//   <--<--<--<--<--<--<--

bool has_cycle2_util(int graph[][NUM_VERTICES], int cur, bool *visited, bool *rec_stack)
{
	// If you encounter a vertex already present in the recursion tree, 
	// you have a back edge => there is a cycle by definition.
	if(rec_stack[cur])
		return true;

	visited[cur] = true;
	rec_stack[cur] = true;

	// For every vertex adjacent to the current one
	for(int i = 0; i < NUM_VERTICES; ++i)
	{
		if(graph[cur][i])
		{
			// Check if this modified DFS will detect a cycle, and if it does, then there is a cycle
			if(has_cycle2_util(graph, i, visited, rec_stack))
				return true;
		}	
	}

	// visited[cur] = false; // do not unmark the vertex because of the optimization for visited nodes below
	rec_stack[cur] = false; // Very important - unmark the vertex as visited in the recursion tree.

	// If no cycle has been found in this graph (or more accurately, connected component) return false
	return false;
}

// Given a graph represented with an adjacency matrix, returns whether it is cyclic or not
bool has_cycle2(int graph[][NUM_VERTICES])
{
	// Create two bool arrays - one for visited nodes in general, and one for visited nodes in the recursion tree.
	bool visited[NUM_VERTICES];
	bool recursion_stack[NUM_VERTICES];

	// Initialize both to false
	for(int i = 0; i < NUM_VERTICES; ++i)
	{
		visited[i] = false;
		recursion_stack[i] = false;
	}

	// For every vertex in the graph
	for(int i = 0; i < NUM_VERTICES; ++i)
	{
		// This is a small optimization - do not start the DFS from every node, only from unvisited ones
		// This is why you need the visited array and pass it to the DFS - otherwise the recursion_stack array suffices
		// Remember, the point if this array is not to get in cycles - and our task is to detect them!
		if(!visited[i])
		{
			// If there is a cycle
			if(has_cycle2_util(graph, i, visited, recursion_stack))
				return true;
		}
	}

	// If no cycle has been found, there is none.
	return false;
}

// There is yet another way to check if a graph is cyclic or not - by doing a topological sort
// using the Source Removal algorithm
// If the graph doesn't contain a node with indegree 0, it's cyclic.
// When done with the topological sort, if the graph still contains nodes, i.e. if the indegree array
// is not all filled with -1's or whatever, it is cyclic.

int main(int argc, char const *argv[])
{
	// Read an adjacency matrix from stdin
	int adj_matrix[NUM_VERTICES][NUM_VERTICES];
	for(int i = 0; i < NUM_VERTICES; ++i)
	{
		for(int j = 0; j < NUM_VERTICES; ++j)
		{
			std::cin >> adj_matrix[i][j];
		}
	}

	std::cout << has_cycle(adj_matrix, 0) << std::endl;
	std::cout << has_cycle2(adj_matrix) << std::endl;

	return 0;
}
