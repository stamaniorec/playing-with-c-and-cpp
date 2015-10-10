#include <vector>
#include "sudoku.h"

int main (int argc, char const* argv[])
{
	int sudoku[SUDOKU_SIZE][SUDOKU_SIZE];
	read_sudoku_from_file(sudoku);
	int blanks = count_blanks(sudoku);

	std::vector<int> possible_numbers;

	while(blanks)
	{
		for(int i = 0; i < SUDOKU_SIZE; ++i)
		{
			for(int j = 0; j < SUDOKU_SIZE; ++j)
			{
				if(!sudoku[i][j])
				{
					for(int k = 1; k <= 9; ++k)
					{
						if(rows(sudoku, i, k) && columns(sudoku, j, k) && square(sudoku, i, j, k))
						{
							possible_numbers.push_back(k);
						}
					}
					if(possible_numbers.size() == 1)
					{
						sudoku[i][j] = possible_numbers[0];
						--blanks;
					}
					else
					{
						possible_numbers.clear();
					}
				}
			}	
		}
	}	

	print_sudoku(sudoku);

	return 0;
}