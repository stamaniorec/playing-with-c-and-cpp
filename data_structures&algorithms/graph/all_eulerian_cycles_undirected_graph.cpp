#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

void ReadInput(vector<vector<int> >& vertexNeighbours, int& edgesLeft, bool& isEulerCandidate)
{
	string line;
    int n;
	cin>>n;
	int vertexCount;
	vector<int> emptyVector;

    for (int i = 0; i < n; i++)
    {
		vertexNeighbours.push_back(emptyVector);
        cin>>line;
        for (int j = 0; j < n; j++)
        {
			if (line[j] == '1') vertexNeighbours[i].push_back(j);
        }
		vertexCount = vertexNeighbours[i].size();
		edgesLeft += vertexCount;
		if (vertexCount % 2 != 0)
        {
            isEulerCandidate = false;
            //return;
        }
    }
}

void PrintRoute(vector<int> route, int eulerCyclesCount)
{
    cout<<"Route "<<eulerCyclesCount<<":";
	for(int i = 0; i < route.size(); i++) cout<<" "<<route[i];
	cout<<endl;
}

void DFS(int startIndex, vector<int>& route, vector<vector<int> >& vertexNeighbours,
    int& edgesLeft, int& eulerCyclesCount, vector<vector<bool> >& visited)
{
    if (edgesLeft == 0)
    {
        PrintRoute(route, ++eulerCyclesCount);
        return;
    }
	int neighbour;
	for(int i = 0; i < vertexNeighbours[startIndex].size(); i++)
	{
		neighbour = vertexNeighbours[startIndex][i];
		if (!visited[startIndex][neighbour])
        {
			route.push_back(neighbour);
            visited[startIndex][neighbour] = true;
            visited[neighbour][startIndex] = true;
            edgesLeft -= 2;
            DFS(neighbour, route, vertexNeighbours, edgesLeft, eulerCyclesCount, visited);
            edgesLeft += 2;
            visited[startIndex][neighbour] = false;
            visited[neighbour][startIndex] = false;
			route.pop_back();
        }
	}
}

void PrintAllEulerCycleInUndirectedGraph(int startIndex)
{
	//Representing the graph with the neighbours(edges) keeped for each vertex
    vector<vector<int> > vertexNeighbours;

    //Getting the input
    int edgesLeft = 0;
    bool isEulerCandidate = true;
    ReadInput(vertexNeighbours, edgesLeft, isEulerCandidate);

    //Euler cycle is only possible when all vertices are of even degree.
    if (!isEulerCandidate)
    {
        cout<<"Number of routes: 0"<<endl;
        return;
    }

	int n = vertexNeighbours.size();
	vector<bool> emptyBool;
    vector<vector<bool> > visited;
	for(int row = 0; row < n; row++)
	{
		visited.push_back(emptyBool);
		for(int col = 0; col < n; col++)
		{
			visited[row].push_back(false);
		}
	}

	int eulerCyclesCount = 0;
    vector<int> route;
	route.push_back(startIndex);

    //Recursive trying for all possible routes:
    DFS(startIndex, route, vertexNeighbours, edgesLeft, eulerCyclesCount, visited);
	cout<<"Number of routes: "<<eulerCyclesCount<<endl;
}

int main()
	{
		PrintAllEulerCycleInUndirectedGraph(0);
		return 0;
	}
