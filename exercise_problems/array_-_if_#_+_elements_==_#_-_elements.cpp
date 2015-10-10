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
Напишете програма, която определя дали броят на отрицателните е равен на броя на положителните елементи на масива.

*/

int main ( )
{
    srand ( time ( NULL ) );
    int myArray[20];
    int size1 = 20;
    int k = 0;
    for ( int i = 0; i < size1; i++ )
    {
        myArray[i] = ( rand() % 201 ) - 100;
        if ( myArray[i] > 0 )
            k++;
        else
            k--;
    }
    if ( k == 0 )
        cout << "\nYes.\n";
    else
        cout << "\nNo.\n";

    return 0;
}
