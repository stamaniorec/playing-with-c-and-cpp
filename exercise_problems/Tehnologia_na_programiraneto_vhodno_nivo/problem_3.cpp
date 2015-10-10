#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>


using namespace std;

/* Да се разработи програма, която изисква от потребителя да въведе две целочислени числа, x и y, където x < y.
Да се намерят и изведат всички прости числа завършващи на 3 в интервал [x,y].
*/

int main ()
{
    int x, y;
    while ( 1 )
    {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
        if ( x < y )
        {
            break;
        }
        else
        {
            cout << "Error with input, please try again. \n";
        }
    }
    bool ifPrime = true;
    for ( int i = x; i <= y; i++ )
    {
        for ( int j = 2; j < i; j++ )
        {
            if ( x % j == 0 )
            {
                ifPrime = false;
                break;
            }
        }
        if ( ifPrime == true )
        {
            if ( i % 10 == 3 )
            {
                cout << i << endl;
            }
        }
    }
    return 0;
}
