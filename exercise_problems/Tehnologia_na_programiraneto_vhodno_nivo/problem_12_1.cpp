#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където 0<x<10.
Да се инициализира масив от 10 елемента. Да се намери първото число N в интервала [0; +∞) делящо се на х.
Да се намери сумата на всички числа в интервала [0; N] и да се запише като първи елемент в масива.
Да се намери второто число N' в интервала [0; +∞) делящо се на x. Да се намери сумата на всички числа в интервала [0, N']
и да се запише като втори елемент в масива.
Аналогично да се запълнят и останалите елементи на масива. Масивът да се изведе на стандартния изход.


*/

int main ()
{
    int x;
    while ( 1 )
    {
        cout << "Enter x: ";
        cin >> x;
        if ( x > 0 && x < 10 )
        {
            break;
        }
        else
        {
            cout << "Invalid input. Please try again. Remember: 0 < x < 10 !!! \n\n";
        }
    }
    int masiv[10];
    int i = 1;
    int j = 0;
    int sum;
    while ( 1 )
    {
        i++;
        if ( i % x == 0 )
        {
            sum = 0;
            for ( int k = 0; k <= i; k++ )
            {
                sum += k;
            }
            masiv[j] = sum;
            j++;
        }
        if ( j >= 10 )
        {
            break;
        }
    }
    for ( int h = 0; h < 10; h++ )
    {
        cout << "masiv[" << h << "] = " << masiv[h] << endl;
    }
    return 0;
}
