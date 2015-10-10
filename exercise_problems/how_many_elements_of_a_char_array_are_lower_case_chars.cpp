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
    char masiv[5] = {'a', 'G', '#', '@', 'f'};
    int k = 0;
    for ( int i = 0; i < 5; i++ )
    {
        if ( masiv[i] >= 'a' && masiv[i] <= 'z' )
            k++;
    }
    cout << "k=" << k << endl;
    return 0;
}
