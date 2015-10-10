#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
Даден е масив А, съдържащ N числа. Напишете
програма, която въвежда цяло положително число
К<N и премества първите К елемента в края на
масива.
*/

int main ()
{
    int my_Array[5] = {1, 2, 3, 4, 5};
    int k = 0;
    int array_size = 5;
    cout << "Enter k: ";
    while ( 1 )
    {
        cin >> k;
        if ( k < array_size )
            break;
        else
            cout << "Error, please try again. " << endl;
    }
    k--;
    int temp;
    int r = k;
    int y = 0;
    while ( y <= k )
    {
        while ( r > 0 + y )
        {
            temp = my_Array[r];
            my_Array[r] = my_Array[r-1];
            my_Array[r-1] = temp;
            r--;
        }
        y++;
        r = k + y;
    }
    for ( int p = 0; p < array_size; p++ )
    {
        cout << my_Array[p] << " ";
    }
    cout << endl;
    return 0;
}
