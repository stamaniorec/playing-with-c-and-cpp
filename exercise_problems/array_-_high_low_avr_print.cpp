#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Highest_Lowest_Average ( int array [], int );
void printOut ( int array [], int );


int main ()
{
    cout << "Please enter ten values.";
    int array_size = 5;
    int array[array_size];
    int a;
    for ( int i = 0; i < array_size; i++ )
    {
        cout << "\n " << i+1 << ": ";
        cin >> a;
        array[i] = a;
    }
    Highest_Lowest_Average ( array, array_size );
    printOut ( array, array_size );
    return 0;
}

void Highest_Lowest_Average ( int array [], int array_size )
{
    int max = array[0];
    int min = array[0];
    float average = array [0];
    for ( int i = 1; i < array_size; i++ )
    {
        if ( array[i] > max )
        {
            max = array [i];
        }
        if ( array[i] < min )
        {
            min = array [i];
        }
        average += array [i];
    }
    cout << "\nThe highest number is " << max << endl;
    cout << "The lowest number is " << min << endl;
    cout << "The average number is " << average / array_size << endl;
}

void printOut ( int array [], int array_size )
{
    for ( int i = 0; i < array_size; i++ )
    {
        cout << " array["<< i+1 << "] = " << array [i] << endl;
    }
}
