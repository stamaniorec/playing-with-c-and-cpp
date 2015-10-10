#include <stdio.h>

int main ( )
{

    // Hello      guys! -> Hello guys!

    int c;

    int blankcount = 0;

    while ( ( c = getchar() ) != EOF )
    {
        if ( c == ' ' )
            blankcount++;
        else
            blankcount = 0;
			
        if ( blankcount < 2 )
        {
            putchar(c);
        }
    }

    return 0;
}
