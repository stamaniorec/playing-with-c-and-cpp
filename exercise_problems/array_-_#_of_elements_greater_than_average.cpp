#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
Напишете програма, която въвежда масив А, съдържащ 10 цели числа и намира броя на елементите,
които са по-големи от средноаритметичното от елементите на масива.
*/

int main ()
{
    int myArray[10] = { 3, 4, 2, 93, 23, 53, 44, 99, 11, 47 };
    float average = 0;
    for ( int i = 0; i < 10; i++ )
    {
        average += myArray[i];
    }
    average /= 10;
    int k = 0;
    for ( int j = 0; j < 10; j++ )
    {
        if ( myArray[j] > average )
            k++;
    }
    cout << "k=" << k << endl;
    return 0;
}
