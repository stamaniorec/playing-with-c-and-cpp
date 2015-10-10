#include <stdio.h>
#include <string.h>

// Given a C-style string containing lowercase letters only,
// remove any duplicates from it.

void solution(char* string)
{
	int tail = 0;
	int memo = 0;
	char* itr = string;

	while(*itr)
	{
		int index = *itr - 'a';
		if(!(memo & (1 << index)))
		{
			string[tail++] = *itr;
			memo = memo | (1 << index);
		}
		++itr;
	}

	string[tail] = '\0';
}

int main(int argc, char const *argv[])
{
	char case1[255] = "abcd";
	char case2[255] = "aaaaa";
	char case3[255] = "aabbbb";
	char case4[255] = "abababba";
	char case5[255] = "ababcbca";
	
	solution(case1);
	solution(case2);
	solution(case3);
	solution(case4);
	solution(case5);

	printf("%s\n", case1); // abcd
	printf("%s\n", case2); // a
	printf("%s\n", case3); // ab
	printf("%s\n", case4); // ab
	printf("%s\n", case5); // abc

	return 0;
}
