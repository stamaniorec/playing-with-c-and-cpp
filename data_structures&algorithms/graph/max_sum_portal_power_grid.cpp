#include <iostream>
#include <algorithm> // std::max

#define WIDTH 6
#define HEIGHT 5

// Problem Statement: 
// You are given a grid with numbers.
// If a cell has a value of k, this means the cell can teleport you k cells up, down, left or right.
// Calculate the maximum amount of teleportation power that can be used in the grid, given a starting cell.
// If k is -1, this means the cell is filled with lava and cannot be used
// Every portal can be used only once.
// A portal cannot teleport you outside of the grid.
// Note that you count a portal's power only if it can successfully take you somewhere 
// (this includes already visited cells!!! [me: this is where I screwed up - wasn't really specified in the problem statement])

bool visited[WIDTH * HEIGHT] = { false };

int max_of_four(int a, int b, int c, int d)
{
	return std::max(std::max(std::max(a,b),c),d);
}

int sum(int grid[HEIGHT][WIDTH], int row, int col, int cur_sum)
{
	// If outside the grid, go back
	if(row < 0 || row > HEIGHT-1 || col < 0 || col > WIDTH-1)
		return 0;

	// If already been here, return the SUM, not 0! 
	// Because it counts as a valid cell, read the end of the problem statement to see more
	if(visited[row*WIDTH + col])
		return cur_sum;

	int teleportation_distance = grid[row][col];

	// If cell is filled with lava, go back
	if(teleportation_distance == -1)
		return 0;

	visited[row*WIDTH + col] = true;

	// Explore all directions - returns 0 if not possible to go there, the running sum otherwise
	int right = sum(grid, row, col + teleportation_distance, cur_sum + teleportation_distance);
	int down = sum(grid, row + teleportation_distance, col, cur_sum + teleportation_distance);
	int left = sum(grid, row, col - teleportation_distance, cur_sum + teleportation_distance);
	int up = sum(grid, row - teleportation_distance, col, cur_sum + teleportation_distance);

	visited[row*WIDTH+col] = false;

	// If reached a dead end, return the current running sum
	if(!up && !down && !left && !right)
		return cur_sum;

	// Otherwise return the maximum of the four directions
	return max_of_four(up, down, left, right);
}

int main(int argc, char const *argv[])
{
	// Expect: 23
	int grid[HEIGHT][WIDTH] = { 
		{1,-1,5,4,6,4},
		{3,2,-1,2,6,2},
		{9,1,7,6,3,1},
		{8,2,7,3,8,6},
		{3,6,1,3,1,2}
	};

	// Expect: 0
	int grid2[HEIGHT][WIDTH] = {
		{1,-1,5,4,6,4},
		{-1,2,-1,2,6,2},
		{9,1,7,6,3,1}, 
		{8,2,7,3,8,6},
		{3,6,1,3,1,2}
	};

	// Expect: 1
	int grid3[HEIGHT][WIDTH] = {
		{1,-1,5,4,6,4},
		{0,2,-1,2,6,2},
		{9,1,7,6,3,1}, 
		{8,2,7,3,8,6},
		{3,6,1,3,1,2}
	};

	// Expect: 18
	int grid4[HEIGHT][WIDTH] = {
		{1,-1,5,4,6,4},
		{3,2,-1,2,6,3},
		{9,1,7,6,3,1},
		{8,2,7,0,8,6},
		{3,6,0,1,0,5}
	};

	// Expect: 94 with starting point 0,2
	// Note: Change the WIDTH and HEIGHT up in the #define if testing this case
	// int grid5[9][7] = {
	// 	{2,5,4,-1,-1,1,-1},
	// 	{5,3,-1,2,6,3,5},
	// 	{2,-1,4,1,3,1,6},
	// 	{6,2,-1,3,1,1,6},
	// 	{1,3,3,4,6,3,1},
	// 	{4,4,4,-1,2,4,4},
	// 	{-1,1,-1,5,-1,4,3},
	// 	{4,2,-1,6,6,4,2},
	// 	{4,2,4,6,6,4,5}
	// };

	// Note: I don't reset visited to false

	std::cout << "Max sum: " << sum(grid, 0, 0, 0) << std::endl;

	return 0;
}