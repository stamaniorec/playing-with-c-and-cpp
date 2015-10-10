#include <iostream>

#define MAZE_SIZE 4

// Maze legend: 
//  0 - walkable
// -1 - unwalkable
//  1 - exit
int maze[][MAZE_SIZE] = {
	{ 0, 0, 0,-1},
	{-1,-1, 0, 0},
	{ 0,-1, 0, 0},
	{ 0, 0, 0, 1}
};

// Keeps the current path 
// Makes sure you don't enter an infinite loop 
// (e.g. if the order of visiting was right, left...)
bool visited[][MAZE_SIZE] = {
	{false, false, false, false},
	{false, false, false, false},
	{false, false, false, false},
	{false, false, false, false}
};

// Prints out the visited matrix, which contains the path
void print_solution()
{
	for(int i = 0; i < MAZE_SIZE; ++i)
	{
		for(int j = 0; j < MAZE_SIZE; ++j)
		{
			std::cout << visited[i][j];
		}
		std::cout << std::endl;
	}
}

// Takes the maze, the current cell's row and col
// Returns whether a solution to the maze exists
bool solve(int maze[][MAZE_SIZE], int row, int col)
{
	// Outside the maze
	if(row < 0 || row > 3 || col < 0 || col > 3)
		return false;

	// Unwalkable cell
	if(maze[row][col] == -1)
		return false;

	// Prevent infinite loop
	// If you think it's not needed, consider maze2
	// The "tunnel" ((row: 2, col: 2) and (row: 1, col: 2)) 
	// leads to an infinite loop without this 
	if(visited[row][col])
		return false;

	// Mark the cell as visited before checking for exit
	// so that it's included in the visited path
	visited[row][col] = true;

	// Reached the exit of the maze
	if(maze[row][col] == 1)
	{
		print_solution();
		return true;
	}
	
	if(solve(maze, row, col+1) || solve(maze, row+1, col) || 
		solve(maze, row, col-1) || solve(maze, row-1, col))
		return true;
	
	// Not really needed but if you print_solution() when no solution
	// exists, it will print all 0's
	// Without this line, it will print the unsuccessful path
	visited[row][col] = false;

	return false;
}

// Maze without a solution
int maze2[][MAZE_SIZE] = {
	{ 0, 0, 0,-1},
	{-1,-1, 0,-1},
	{ 0,-1, 0,-1},
	{ 0, 0,-1, 1}
};

int main(int argc, char const *argv[])
{
	if(!solve(maze, 0, 0))
		std::cout << "No solution." << std::endl;

	if(!solve(maze2, 0, 0))
		std::cout << "No solution." << std::endl;

	// You ought to clear the visited matrix after each call to solve
	// I didn't do it because I'm lazy

	return 0;
}