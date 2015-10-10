#include <stdio.h>

int sum(int array[], int length)
{
	if ( length == 0 ) 
	{
		return 0;
	}
	return array[length-1] + sum(array, length-1);
}

int main (int argc, char *argv[])
{
	int array[5] = {1, 2, 3, 4, 5};
	printf("%d\n", sum(array, 5));
	return 0;
}

