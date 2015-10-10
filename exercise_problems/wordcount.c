#include <stdio.h>

int main()
{
    // Hello guys! How are you?

    int c;

    int wordcount = 1;

    while ( ( c = getchar() ) != EOF )
    {
        if ( c == ' ' )
            wordcount++;
    }

    printf ("Number of words: %d", wordcount);



    return 0;
}
