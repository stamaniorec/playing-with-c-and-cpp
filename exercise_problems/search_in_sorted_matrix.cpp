#include <iostream>
#include <sstream>

#define MATRIX_SIZE 5

// Standard iterative binary search but for a matrix - low is 0, high is SIZE * SIZE
int search_in_matrix(int matrix[][MATRIX_SIZE], int key, int low, int high)
{
	while(low <= high)
	{
		int mid = (low + high) / 2;

		int row = mid / MATRIX_SIZE;
		int col = mid % MATRIX_SIZE;
		
		if(matrix[row][col] == key)
			return mid;
		else if(matrix[row][col] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

// Wrapper for the function above
std::string binary_search(int matrix[][MATRIX_SIZE], int key)
{
	int index = search_in_matrix(matrix, key, 0, MATRIX_SIZE * MATRIX_SIZE);
	if(index == -1)
		return "not found";
	else
	{
		int row = index / MATRIX_SIZE;
		int col = index % MATRIX_SIZE;
		std::stringstream res;
		res << "found at row " << row << ", " << " col " << col;
		return res.str();
	}
}

std::string int_to_string(int num)
{
	std::stringstream stream;
	stream << num;
	return stream.str();
}

// Concerning the second matrix (the real problem statement), there are two more ways to go about it.
// The first is, of course, brute force, but it's very inefficient - O(n^2).
// The second is to do a binary search on every row. This is better, but still not perfect - O(n*log(n)).

// Returns whether the given sorted matrix includes a given value 
bool solve(int matrix[][MATRIX_SIZE], int key)
{
	int row = 0;
	int col = MATRIX_SIZE - 1;

	while(row < MATRIX_SIZE && col >= 0)
	{
		if(matrix[row][col] == key)
			return true;
		if(matrix[row][col] < key)
			++row;
		if(matrix[row][col] > key)
		{
			--col;
		}
	}

	return false;
}

int main(int argc, char const *argv[])
{
	// Initially I misunderstood the problem statement and solved it for this kind of sorted matrix
	int matrix[][MATRIX_SIZE] = {
		{1,5,10,11,16},
		{22,25,26,43,78},
		{84,99,120,144,185},
		{283,394,433,468,499},
		{512,660,783,815,927}
	};

	// This is what the actual problem statement is about - a matrix sorted column- and row-wise
	int matrix2[][MATRIX_SIZE] = {
		{4,8,15,16,23},
		{6,9,20,21,44},
		{8,11,24,26,49},
		{9,13,25,27,54},
		{10,17,29,30,66}
	};

	// Tests for the first matrix (the first problem)
	std::cout << "26 " << binary_search(matrix, 26) << std::endl;
	std::cout << "433 " << binary_search(matrix, 433) << std::endl;
	std::cout << "5 " << binary_search(matrix, 5) << std::endl;
	std::cout << "815 " << binary_search(matrix, 815) << std::endl;
	std::cout << "2192 " << binary_search(matrix, 2192) << std::endl;

	// Tests for the second matrix (the second problem)
	std::cout << "9 " << solve(matrix2, 9) << std::endl;
	std::cout << "30 " << solve(matrix2, 30) << std::endl;
	std::cout << "4 " << solve(matrix2, 4) << std::endl;
	std::cout << "49 " << solve(matrix2, 9) << std::endl;
	std::cout << "19 " << solve(matrix2, 19) << std::endl;
	std::cout << "22 " << solve(matrix2, 22) << std::endl;

	return 0;
}