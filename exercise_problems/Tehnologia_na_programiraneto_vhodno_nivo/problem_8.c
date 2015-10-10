#include <stdio.h>

int main()
{
	int x;

	while ( 1 )
	{
		scanf("%d", &x);
		if ( x >= 0 && x < 10 )
		{
			break;
		}
	}

	const int array_length = 10;
	long long my_array[array_length];

	long long a = 1, b = 1, fibonacci;
	int fib_counter = 1; // 0,
	my_array[0] = 1;

	while ( fib_counter < 10 )
	{
		fibonacci = a + b;
		a = b;
		b = fibonacci;
		if ( fibonacci % x == 0 )
		{
			my_array[fib_counter] = fibonacci;
			fib_counter++;
		}
	}

	int i;
	for ( i = 0; i < array_length; i++ )
	{
		printf("%lld ", my_array[i]);
	}

	return 0;
}
