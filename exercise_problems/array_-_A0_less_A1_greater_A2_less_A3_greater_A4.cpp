#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main ()
{
    int my_Array[5] = {1,2,3,4,5};
    int i = 0;
    bool check = true;
        while ( i < 5 )
        {
            if ( check == false )
                i = 0;
            check = true;
            if ( i % 2 == 0 )
            {
                if ( my_Array[i] > my_Array[i+1] )
                {
                    int temp = my_Array[i];
                    my_Array[i] = my_Array[i+1];
                    my_Array[i+1] = temp;
                    check = false;
                }
            }
            else
            {
                if ( my_Array[i] < my_Array[i+1] )
                {
                    int temp = my_Array[i];
                    my_Array[i] = my_Array[i+1];
                    my_Array[i+1] = temp;
                    check = false;
                }
            }
            i++;
        }
    for ( int j = 0; j < 5; j++ )
    {
        cout << my_Array[j] << " ";
    }
    return 0;
}
