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
    int arr_size = 10;
    int masiv[arr_size];
    int positive = 0, negative = 0;
    for ( int i = 0; i < arr_size; i++ )
    {
        masiv[i] = (rand() % 201) - 100;
        cout << masiv[i] << " ";
        if ( masiv[i] > 0 )
        {
            positive++;
        }
        else
        {
            negative++;
        }
    }
    cout << "\n# of + numbers = " << positive << endl;
    cout << "# of - numbers = " << negative << endl;

    return 0;
}
