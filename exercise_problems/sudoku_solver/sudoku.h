#ifndef SUDOKU_H
#define SUDOKU_H value

#ifndef SUDOKU_SIZE
#define SUDOKU_SIZE 9
#endif

bool rows(int file[SUDOKU_SIZE][SUDOKU_SIZE], int row, int num);
bool columns(int file[SUDOKU_SIZE][SUDOKU_SIZE], int col, int num);
bool square(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, int num);
int count_blanks(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE]);
void read_sudoku_from_file(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE]);
void print_sudoku(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE]);

#endif