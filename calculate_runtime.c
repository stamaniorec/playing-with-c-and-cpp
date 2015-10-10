#include <stdio.h>
#include <time.h>

int main()
{
	clock_t start_time = clock();

	int i;
	for(i = 0; i < 1000000000; ++i)
	{
		
	}

	printf("DONE! Time: %f", (double)(clock() - start_time)/CLOCKS_PER_SEC);

	return 0;
}
