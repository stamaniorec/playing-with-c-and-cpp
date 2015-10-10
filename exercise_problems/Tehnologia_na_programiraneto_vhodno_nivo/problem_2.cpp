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
Да се намери и изведе сумата на числата делящи се на 17 в интервал [x, y].

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
            cout << "Error, please try again. \n\n";
        }
    }
    int sum = 0;
    for ( int i = x; i <= y; i++ )
    {
        if ( i % 17 == 0 )
        {
            sum += i;
        }
    }
    cout << "Sum: " << sum << endl;
    return 0;
}
