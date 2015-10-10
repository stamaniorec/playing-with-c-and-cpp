#include <iostream>
#include <fstream>
#include "sudoku.h"

bool rows(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE], int row, int num)
{
	for(int i = 0; i < SUDOKU_SIZE; i++)
	{
		if(sudoku[row][i] == num)
		{
			return false;
		}
	}
	return true;
}

bool columns(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE], int col, int num)
{
	for(int i = 0; i < SUDOKU_SIZE; i++)
	{
		if(sudoku[i][col] == num)
		{
			return false;
		}
	}
	return true;
}

bool square(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, int num)
{
	for(int i = row / 3 * 3; i < row / 3 * 3 + 3; i++)
	{
		for(int j = col / 3 * 3; j < col / 3 * 3 + 3; j++)
		{
			if(sudoku[i][j] == num)
			{
				return false;
			}
		}
	}
	return true;
}

int count_blanks(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE])
{
	int blanks = 0;
	
	for(int i = 0; i < SUDOKU_SIZE; ++i)
	{
		for(int j = 0; j < SUDOKU_SIZE; ++j)
		{
			if(sudoku[i][j] == 0)
			{
				++blanks;
			}
		}
	}
	
	return blanks;
}

void read_sudoku_from_file(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE])
{
	int holder;
	int i = 0;
	int j = 0;

	std::ifstream sudoku_file("sudoku_1.txt");
	
	while(sudoku_file >> holder)
	{
		sudoku[i][j] = holder;
		
		if(++j >= 9)
		{
			j = 0;
			i++;
		}
	}
}

void print_sudoku(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE])
{
	for(int i = 0; i < SUDOKU_SIZE; ++i)
	{
		for(int j = 0; j < SUDOKU_SIZE; ++j)
		{
			std::cout << sudoku[i][j] << " ";
		}
		std::cout << std::endl;
	}
}