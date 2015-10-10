#include <stdio.h>
#include <stdlib.h>

struct foo
{
	int value1;
	int value2;
};

int main()
{
	const int SIZE = 5;
	// the explicit cast is not mandatory in C, but it is in C++
	// for compiler-compatibility it's best included just in case
	int *dynamic_array = (int*)malloc(sizeof(int) * SIZE);
	int i;

	struct foo *foo_array = (struct foo*)malloc(sizeof(struct foo) * SIZE);
	
	for(i = 0; i < SIZE; ++i)
	{
		*(dynamic_array+i) = i + 1;
		printf("%d ", *(dynamic_array+i));	
		// *(arr+index) <--> arr[index]
	}

	printf("\n\n\n");

	for(i = 0; i < SIZE; ++i)
	{
		(foo_array+i)->value1 = i * 5;
		(foo_array+i)->value2 = i * 10;

		printf("%d %d\n", (foo_array+i)->value1, 
			(foo_array+i)->value2);
	}

	struct foo instance1;
	instance1.value1 = 5;
	instance1.value2 = 10;
	
	struct foo instance2 = instance1;

	printf("Instance One: %d, %d\n", instance1.value1, instance1.value2);
	printf("Instance Two: %d, %d\n", instance2.value1, instance2.value2);

	struct foo *p1 = malloc(sizeof(struct foo));
	p1->value1 = 50;
	p1->value2 = 100;
	struct foo *p2 = p1;

	return 0;
}
