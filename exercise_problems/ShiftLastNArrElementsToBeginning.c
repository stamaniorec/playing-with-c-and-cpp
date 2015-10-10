#include <stdio.h>

#define EXIT_VALUE -255

void print_array(int *array, int size)
{
	int i;
	for(i = 0; i < size; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void welcome_user()
{
	printf("Welcome! This program is going to shift the last\n");
	printf("n elements of an array to the beginning of the array.");
	printf("\n\n");	
	printf("The program accepts no more than 30 elements!\n");
	printf("Now please start entering values. \n"); 
	printf("Enter %d to stop entering.\n\n", EXIT_VALUE);	
}

void read_array(int *array, int length, int *actual_size)
{
	int cur_index = 0;
	int cur_num;
	while(scanf("%d", &cur_num) == 1)
	{
		if(cur_num == EXIT_VALUE)
			break;

		array[cur_index++] = cur_num;
		
		if(cur_index >= length)
		{
			printf("As mentioned before, the program");
			printf(" does not work with more than %d numbers!\n", length);

			// BUG: if more values are entered, 
			// the ARRAY_SIZE+1-th value will 
			// be assigned to the number n later on
			// CAUSE: scanf does not fully discard the output

			break;
		}
	}

	*actual_size = cur_index;
}

int read_n()
{
	printf("\nNow please enter the number n, i.e. how many elements\n");
	printf("from the end you'd like to shift to the beginning.\n\n");

	int n;
	while(1)
	{
		if(scanf("%d", &n) != 1)
		{
			printf("Uh-oh, something went wrong.\n");
			printf("Please enter a NUMBER!\n");

			// BUG: If an alphabetical string is entered
			// the program gets stuck in an infinite loop here
			// CAUSE: scanf 
		
			continue;	
		}

		if(n < 0)
		{
			printf("n cannot be negative!\n");
			continue;
		}

		// for n = 0 and n = array size
		// nothing changes but the user will not be notified
		// actual_size is cumbersome
		// global variables aren't a good thing
		// but it doesn't make sense for it to be an argument here either

		break; 

	}

	return n;
}

void shift_elements(int *array, int actual_size, int n)
{
	int right_index = actual_size - n;
	int left_index = 0;

	while(right_index < actual_size)
	{
		int k = right_index;
		while(k > left_index)
		{
			int temp = array[k];
			array[k] = array[k-1];
			array[k-1] = temp;
			k--;
		}
		left_index++;
		right_index++;
	}
}

int main()
{
	welcome_user();

	const int ARRAY_SIZE = 30;
	int array[ARRAY_SIZE];
	int actual_size;	

	read_array(array, ARRAY_SIZE, &actual_size);

	printf("\nThe array you entered is: \n");
	print_array(array, actual_size);
	
	int n = read_n();

	shift_elements(array, actual_size, n);

	printf("\nHere is the shifted array: \n\n");
	print_array(array, actual_size);

	return 0;
}
