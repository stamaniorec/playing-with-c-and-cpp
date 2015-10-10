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
    int size1 = 5;
    int array1[size1] = {1,2,3,4,5};
    for ( int k = 0; k < size1; k++ )
    {
        for ( int i = 0; i < size1 - 1 - k; i++ )
        {
            for (int j = 0; j < size1; j++ )
            {
                cout << array1[j] << " ";
            }
            if ( array1[i] < array1[i+1] )
            {
                int temp = array1[i];
                array1[i] = array1[i+1];
                array1[i+1] = temp;
            }
            cout << endl;
        }
    }
    return 0;
}
