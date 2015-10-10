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
    srand(time(NULL));
    int arr_size = 10;
    int masiv[arr_size];
    for ( int i = 0; i < arr_size; i++ )
    {
        masiv[i] = rand() % 101;
    }
    int sum = 0;
    double product = 1;
    for ( int j = 0; j < arr_size; j++ )
    {
        cout << masiv [j] << " ";
        sum += masiv[j];
        product *= masiv[j];
    }
    cout << "\nSum=" << sum << endl;
    cout << "Product=" << setiosflags(ios::fixed) << setiosflags(ios::showpoint) <<
        setprecision( 2 ) << product << endl;

    return 0;
}
