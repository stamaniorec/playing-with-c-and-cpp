#include <iostream>
#include <vector>
#include <set>

#define GRAPH_SIZE 5

struct Edge
{
	int from;
	int to;
	int weight;

	Edge(int from, int to, int weight) : 
		from(from), to(to), weight(weight) {};

	// Compares two edges by their weight
	bool operator<(const Edge &e) const
	{
		return weight < e.weight;
	}

	friend std::ostream& operator<<(std::ostream &out, const Edge &e)
	{
		out << e.from << " " << e.to << " " << e.weight;
		return out;
	}
};

// Given a graph represented with an adjacency matrix and a starting vertex
// Returns a list of edges forming the Minimum Spanning Tree
std::vector<Edge> prims_algorithm(int graph[][GRAPH_SIZE], int start)
{
	// Note: You can start Prim's algorithm from ANY random vertex in the graph

	// A list of edges forming the MST, i.e. the result to be returned
	std::vector<Edge> mst;

	// Loops are not allowed in an MST
	bool visited[GRAPH_SIZE] = { false };
	
	// A priority queue or a sorted set to easily retrieve the smallest element, i.e. the edge with the smallest weight
	std::set<Edge> priority;
	
	// Mark the current vertex as visited
	visited[start] = true;

	// And put all outgoing edges to the priority queue / set
	for(int i = 0; i < GRAPH_SIZE; ++i)
		if(graph[start][i])
			priority.insert(Edge(start, i, graph[start][i]));

	// The size of the MST, by definition, is the number of vertices in the graph
	// The MST in this case is represented with a list of edges, hence the condition in the loop
	while(mst.size() < GRAPH_SIZE-1) // or while(!priority.empty()) 
	{
		// Get the edge with the smallest weight and remove it from the priority queue / set
		Edge smallest_edge = *(priority.begin());
		priority.erase(smallest_edge);

		// If the vertex the edge is pointing to has not been visited
		// Remember, no loops in the MST!
		if(!visited[smallest_edge.to])
		{
			// Mark the vertex as visited
			visited[smallest_edge.to] = true;

			// Insert the current edge into the result MST
			mst.push_back(smallest_edge);

			// And push all outgoing edges from that vertex into the priority queue / set
			for(int j = 0; j < GRAPH_SIZE; ++j)
			{
				if(graph[smallest_edge.to][j])
					priority.insert(Edge(smallest_edge.to, j, graph[smallest_edge.to][j]));
			}
		}
	}

	return mst;
}

// A wrapper function for Prim's algorithm
void minimum_spanning_tree(int graph[][GRAPH_SIZE])
{
	std::vector<Edge> mst = prims_algorithm(graph, 0);

	std::cout << "from\tto\tweight" << std::endl;
	for(int i = 0; i < GRAPH_SIZE-1; ++i)
	{
		std::cout << mst[i].from << "\t" << mst[i].to << "\t" << mst[i].weight << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	int graph[][GRAPH_SIZE] = {
		{0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    minimum_spanning_tree(graph);

	return 0;
}

// Here is some pseudocode I found on StackOverflow and it's great. 
// The MST it produces is an actual graph though, not a list of edges.
//
// class Graph
//   Set<node> nodes;   // The set of nodes in the graph
//   MultiMap<Node, Edge> edges; // Map from Node, to a list of weighted edges connected to the node. 
						// If it weren't weighted, any spanning tree by definition would be a minimum spanning tree.

// Graph Prim(Graph input):
//    Graph MST = new Graph();
//    PriorityQueue<Edge> candidateEdges;
//    Node anyNode = input.pickAnyNodeAtRandom()
//    candidateEdges.putAll(input.edges.get(anyNode));

//    while MST.nodes.size() < input.nodes.size():
//       edge = candidateEdges.takeLowest()  // THIS IS THE IMPORTANT PART         
//       if edge.v1 in MST.nodes and edge.v2 not in MST.nodes:
//          MST.nodes.add(edge.v2)       
//          MST.edges.add(edge)
//          candidateEdges.add(edge.v2.edges)