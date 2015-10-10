#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
Даден е масив А, съдържащ 20 произволни числа.
Напишете програма, която определя дали масивът е симетричен – първият елемент е равен на последния, втория – на предпоследния и т.н.
*/

int main ( )
{
	srand ( time ( NULL ) );
    int masiv[10] = {1,2,3,4,5,5,4,3,2,1};
    int arr_size = 9;
    for ( int i = 0; i <= arr_size; i++ )
    {
        //masiv[i] = rand () % 101;
        cout << masiv[i] << " ";
    }
    int j = 0;
    int h = arr_size / 2;
    bool mah_bool = true;
    while ( j != h )
    {
        if ( masiv[0+j] != masiv[arr_size-j] )
        {
            mah_bool = false;
            break;
        }
        j++;
    }
    if ( mah_bool == true )
    {
        cout << "\nSimetrichen e.\n";
    }
    else
    {
        cout << "\nNe e simetrichen.\n";
    }
    return 0;
}
