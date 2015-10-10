#include <iostream>

void print_matrix(int matrix[][4], int size)
{
    for ( int rows = 0; rows < size; rows++ )
    {
        for ( int columns = 0; columns < size; columns++ )
        {
            std::cout << matrix[rows][columns] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    const int size = 4;
    int matrix[size][size];

    int number = 0;
    for ( int i = 0; i < size; i++ )
    {
        for ( int j = 0; j <= i; j++ )
        {
            matrix[j][i-j] = ++number;
        }
    }

    int a = 0;
    for ( int i = 1; i < size; i++ )
    {
        int temp = i;
        for ( int j = size - 1; j > a; j-- )
        {
            matrix[temp++][j] = ++number;
        }
        a++;
    }

    print_matrix(matrix, size);

    return 0;
}
