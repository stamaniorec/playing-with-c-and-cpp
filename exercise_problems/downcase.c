#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* downcase(const char *string, const int length)
{
	int i;
	const int DIFFERENCE = 'a' - 'A';
	char *downcase_string = (char*) malloc(sizeof(char) * length);
	// aaand there's a memory leak for you... 
	// that's what I get for not using toLower... 
	for(i = 0; i < length; ++i)
	{
		if(string[i] >= 'A' && string[i] <= 'Z')
		{
			downcase_string[i] = string[i] + DIFFERENCE;
		} 
		else
		{
			downcase_string[i] = string[i];
		} 
	}
	downcase_string[length] = '\0';
	return downcase_string;
}

int main()
{
	const char *string = "HELLO_WORLd";
	printf("%s\n", downcase(string, strlen(string)));

	return 0;
}
