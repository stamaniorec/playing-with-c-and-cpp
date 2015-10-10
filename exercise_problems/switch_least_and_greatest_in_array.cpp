#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

    /*
    Даден е целочислен масив А с N елемента. Напишете програма, която разменя местата на минималния и максималния му елементи.

    */

int main ( )
{
    int arr_length = 5;
    int array1[arr_length];
    array1[0] = 5;
    array1[1] = 28831;
    array1[2] = 2;
    array1[3] = 10;
    array1[4] = 1;
    int max_index, min_index;
    for ( int i = 1; i < arr_length; i++ )
    {
        if ( array1[i] > max1 )
        {
            max_index = i;
        }
        if ( array1[i] < min1 )
        {
            min_index = i;
        }
    }
    int temp = array1[max_index];
    array1[max_index] = array1[min_index];
    array1[min_index] = temp;
    for ( int j = 0; j < arr_length; j++ )
    {
        cout << array1[j] << " ";
    }
    return 0;
}
