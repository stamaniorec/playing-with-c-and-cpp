#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
Даден е масив А, съдържащ 20 произволни цели числа.
Напишете програма, която определя колко от елементите на масива са точни квадрати.
*/

int main ( )
{
    srand ( time ( NULL ) );
    int masiv[10];
    int k = 0;
    for ( int i = 0; i < 10; i++ )
    {
        masiv[i] = rand() % 100;
        cout << masiv[i] << " ";
        if ( sqrt ( masiv[i] ) == floor ( sqrt (masiv[i] ) ) )
            k++;
    }
    cout << "\nk=" << k << endl;
    return 0;
}
