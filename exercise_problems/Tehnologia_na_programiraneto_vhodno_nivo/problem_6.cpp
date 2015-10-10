#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

    /*
    Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където 0<x<10.
    Да се инициализира масив от 100 целочислени елемента. Стойностите на елементите да са случайни числа в интервала [0, 100).
    Елементите на масива да се подредят така, че числата завършващи на x да са в началото.
    */

int main ( )
{
    srand ( time ( NULL ) );

    // Variables used
    int x;
    int arr_size = 10;
    int masiv[arr_size];
    int random;
    int limit = 100;
    int k = 0;
    int temp;
    //

    cout << "Enter x: ";
    while ( 1 )
    {
        cin >> x;
        if ( x > 0 && x < 10 )
        {
            break;
        }
        else
        {
            cout << "Error, please try again.\n";
        }
    }

    for ( int i = 0; i < arr_size; i++ )
    {
        random = rand () % limit;
        masiv[i] = random;
    }

    for ( int j = 0; j < arr_size; j++ )
    {
        if ( masiv[j] % 10 == x )
        {
            temp = masiv[j];
            masiv[j] = masiv [k];
            masiv[k] = temp;
            k++;
        }
    }

    for ( int z = 0; z < arr_size; z++ )
    {
        cout << masiv[z] << " ";
    }

    return 0;
}
