#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

void counting ( int );

int main ()
{
    for ( int i = 1; i <= 12; i++ )
    {
        cout << "On my ";
        counting (i);
        cout << " day of Christmas, \n";
        cout << "my true love sent to me \n";
        switch (i)
        {
        case 12:
            cout << "Twelve drummers drumming, \n";
        case 11:
            cout << "Eleven pipers piping, \n";
        case 10:
            cout << "Ten lords a-leaping, \n";
        case 9:
            cout << "Nine ladies dancing, \n";
        case 8:
            cout << "Eight maids a-milking, \n";
        case 7:
            cout << "Seven swans a-swimming, \n";
        case 6:
            cout << "Six geese a-laying, \n";
        case 5:
            cout << "Five golden rings, \n";
        case 4:
            cout << "Four calling birds, \n";
        case 3:
            cout << "Three French hens, \n";
        case 2:
            cout << "Two turtle doves, \nAnd ";
        case 1:
            cout << "A partridge in a pear tree \n\n\n";
        }
    }
    return 0;
}

void counting ( int i )
{
    switch ( i )
    {
    case 1:
        cout << "first";
        break;
    case 2:
        cout << "second";
        break;
    case 3:
        cout << "third";
        break;
    case 4:
        cout << "fourth";
        break;
    case 5:
        cout << "fifth";
        break;
    case 6:
        cout << "sixth";
        break;
    case 7:
        cout << "seventh";
        break;
    case 8:
        cout << "eighth";
        break;
    case 9:
        cout << "ninth";
        break;
    case 10:
        cout << "tenth";
        break;
    case 11:
        cout << "eleventh";
        break;
    case 12:
        cout << "twelfth";
        break;
    }
}
