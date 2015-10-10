#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
Да се разработи програма, която изисква от потребителя да въведе две целочислени числа, x и y, където x < y.
Да се намери сумата на всички нечетни числа в интервала [x,y].
*/

int main ()
{
    int x;
    int y;
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
            cout << "Error, please try again. \n";
        }
    }
    int sum = 0;
    for ( int i = x; i <= y; i++ )
    {
        if ( i % 2 != 0 )
        {
            sum += i;
        }
    }
    cout << "Sum: " << sum << endl;
    return 0;
}
