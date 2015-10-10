#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

bool ifSorted ( int array[], int list_size )
{
    int a = list_size - 1;
    bool boolean = true;
    int max;
    max = array[a];
    while ( a > 0 )
    {
        a -= 1;
        if ( array[a] > max )
        {
            boolean = false;
            break;
        }
        else
        {
            max = array[a];
        }
    }
    if ( boolean == true )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void sort_array ( int array [], int list_size )
{
    int temp;
        for ( int k = 1; k <= list_size; k++ )
        {
            for ( int i = 0; i < list_size - k; i++ )
            {
                if ( array[i] > array [i+1] )
                {
                    temp = array[i];
                    array[i] = array[i+1];
                    array[i+1] = temp;
                }
            }

        }
}

void printOut ( int array [], int list_size )
{
    for ( int i = 0; i < list_size; i++ )
    {
        cout << "array[" << i+1 << "] = " << array [i] << endl;
    }
}

int main ()
{
    int list_size;
    cout << "How long is your list?" << endl;
    cin >> list_size;
    cout << "Please enter all elements of the list.\n";
    int array[list_size];
    for ( int i = 0; i < list_size; i++ )
    {
        cout << i+1 << ": ";
        cin >> array[i];
    }
    if ( ifSorted ( array, list_size ) == false )
    {
        sort_array ( array, list_size );
        printOut ( array, list_size );
    }
    else
    {
        cout << "The list is already sorted." << endl;
    }
    return 0;
}
