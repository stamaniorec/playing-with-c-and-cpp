#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

int main ( )
{
	srand ( time ( NULL ) );
    int masiv[10]; // = {1,2,3,4,5,6,4,8,9,10};
    int arr_size = 9;
    for ( int i = 0; i <= arr_size; i++ )
    {
        masiv[i] = rand () % 101;
        cout << masiv[i] << " ";
    }
    int j = 1;
    int max1 = masiv[0];
    while ( j <= arr_size )
    {
        if ( masiv[j] > max1 )
            max1 = masiv[j];
        else
            break;
        j++;
    }
    if ( j <= arr_size )
        cout << "\nNo.\n";
    else
        cout << "\nYes.\n";
    return 0;
}
