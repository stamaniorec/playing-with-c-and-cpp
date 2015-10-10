#include <stdio.h>

int main()
{
    // Hello guys! How are you?

    int c;

    while ( ( c = getchar() ) != EOF )
    {
        if ( c == ' ' )
            putchar('\n');
        else
            putchar(c);
    }



    return 0;
}
