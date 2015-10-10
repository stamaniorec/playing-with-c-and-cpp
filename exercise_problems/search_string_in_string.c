#include <stdio.h>
#include <string.h>

/* 
That was the problem Kamena was given to raise her grade to an A.
She couldn't do it on her own so the teachers told her the solution.
And they still gave her an A. 
My first attempt at this problem took me about 20 minutes because 
my while loops got crazy and really messed up. 
Then I deleted everything, started from scratch, used for loops and
solved the problem in a matter of minutes. 
It was 10-something in the evening and I was half asleep and I still 
figured out the solution by myself. -_-;
*/

int function(char string1[], char string2[])
{
	int i, j, flag, temp;
	for ( i = 0; i < strlen(string1); i++ )
	{
		flag = 1;
		temp = i;
		for ( j = 0; j < strlen(string2); j++ )
		{
			if ( string1[temp] != string2[j] ) 
			{
				flag = 0;
				break;
			}
			temp++;
		}
		if ( flag ) 
			break;
	}
	if ( flag ) 
		return i;
	else
		return -1;
}

int main()
{
	char string1[] = "hello world";
	char string2[] = "world";

	printf("%d \n", function(string1, string2));

	return 0;
}
