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
    srand (time(NULL));
    int low, high;
    cout << "Dolna granica=";
    cin >> low;
    cout << "Gorna granica=";
    cin >> high;
    int arr_size = 10;
    int masiv[arr_size];
    int j = 0;
    for ( int i = 0; i < arr_size; i++ )
    {
        masiv[i] = rand();
        cout << masiv[i] << " ";
        if ( masiv[i] >= low && masiv[i] <= high )
        {
            j++;
        }
    }
    cout << "\n\nThe numers in the array in the interval [" << low << "; "
        << high << "] is " << j;
    return 0;
}
