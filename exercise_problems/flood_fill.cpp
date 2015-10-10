#include <iostream>
#include <cstdlib>

using namespace std;

class Matrix
{
private:
	int matrix[7][7];
public:
	Matrix()
	{
		for(int i = 0; i < 7; i++)
		{
			for(int j = 0; j < 7; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	void print_matrix()
	{
		for(int i = 0; i < 7; i++)
		{
			for(int j = 0; j < 7; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	void set_ones()
	{
		for(int i = 0; i < 5; i++)
		{
			while(1)
			{
				int rand_x = rand() % 7;
				int rand_y = rand() % 7;
				if(matrix[rand_x][rand_y] != 1)
				{
					matrix[rand_x][rand_y] = 1;
					break;
				}
			}
		}
	}
	void flood_fill(int start_x, int start_y)
	{
		if(matrix[start_x][start_y] == 0)
		{
			matrix[start_x][start_y] = 5;
		}
		else
		{
			return;
		}
		flood_fill(start_x + 1, start_y);
		flood_fill(start_x - 1, start_y);
		flood_fill(start_x, start_y + 1);
		flood_fill(start_x, start_y - 1);
	}
};

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	Matrix matrix;
	matrix.print_matrix();
	matrix.set_ones();
	cout << endl;
	matrix.print_matrix();
	matrix.flood_fill(3, 4);
	cout << endl;
	matrix.print_matrix();
	return 0;
}