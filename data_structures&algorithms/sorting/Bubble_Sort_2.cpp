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
    int masiv[10]= {1,2,3,4,5,6,7,8,9,10};
    int temp;
    int end1 = 10;
    int length = 10;
    for ( int i = length; i > 1; i-- )
    {
        for ( int j = 0; j < i-1; j++ )
        {
            if ( masiv[j] > masiv[j+1] )
            {
                temp = masiv[j];
                masiv[j] = masiv[j+1];
                masiv[j+1] = temp;
            }
        }
    }
    for ( int k = 0; k < 10; k++ )
    {
        cout << masiv[k] << " ";
    }

    return 0;
}
