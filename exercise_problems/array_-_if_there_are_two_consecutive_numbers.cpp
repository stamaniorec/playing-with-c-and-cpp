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
Напишете програма, която определя дали в масива се съдържат два последователни равни елемента.
*/

int main ( )
{
    srand (time (NULL));
    int masiv[10];//= {1,2,3,5,4,5,6,7,8,9};
    for ( int i = 0; i < 10; i++ )
    {
        masiv[i] = rand() % 101;
        cout << masiv[i] << " ";
    }
    bool mah_bool = false;
    for ( int j = 0; j < 10; j++ )
    {
        if ( masiv[j] == masiv[j+1] && j != 9 )
        {
            mah_bool = true;
            break;
        }
    }
    if ( mah_bool == true )
        cout << "\nYes.\n";
    else
        cout << "\nNo.\n";
    return 0;
}
