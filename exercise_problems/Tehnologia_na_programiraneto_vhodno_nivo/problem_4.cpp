#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

    /* Да се разработи програма, която изисква от потребителя да въведе две целочислени числа, x и y, където x < y.
    Да се намерят и изведат всички числа на Фибоначи в интервала [x, y].
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
            cout << "Error, please try again. Remember: x < y!" << endl;
        }
    }
    int a = 0, b = 1, counter1 = 0;
    int fibonacci;
    while ( 1 )
    {
        fibonacci = a + b;
        a = b;
        b = fibonacci;
        counter1++;
        if ( x == 0 && counter1 == 1 )
        {
			cout << "0 ";
		}
        if ( fibonacci >= x && fibonacci <= y )
        {
            cout << fibonacci << " ";
        }
        else if ( fibonacci > y )
        {
            break;
        }
    }
    return 0;
}
