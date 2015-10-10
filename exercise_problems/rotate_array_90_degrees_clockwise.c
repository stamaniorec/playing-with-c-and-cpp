#include <stdio.h>

int main (int argc, char *argv[])
{
	int T; 
	printf("Enter number of test cases.\n");
	scanf("%d", &T);

	int n, i;
	int k, h, number;
	int p, q; 

	for ( i = 0; i < T; i++ )
	{
		printf("Enter number of dimensions.\n");
		scanf("%d", &n);
		char array[n][n];

		for ( k = 0; k < n; k++ )
		{
			for (h = 0; h < n; h++ )
			{
				scanf("%d", &number);
				array[k][h] = number;
			}
		}		

		for ( p = 0; p < n; p++ )
		{
			for ( q = n-1; q >= 0; q-- )
			{
				printf("%d ", array[q][p]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
