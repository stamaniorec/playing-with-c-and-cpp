#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main ()
{
    /* --- Menu Output --- */
    cout << "What UK political party do you support? \n";
    cout << "\n" << "\n";
    cout << "1. Conservative" << endl;
    cout << "2. Labour" << endl;
    cout << "3. UKIP" << endl;
    int choice = 0; int conservative = 0; int labour = 0; int ukip = 0;

    /* --- User choice loop --- */
    while ( 1 )
    {
        cin >> choice;

        if ( choice == 1 )
        {
            conservative++;
        }
        else if ( choice == 2 )
        {
            labour++;
        }
        else if ( choice == 3 )
        {
            ukip++;
        }
        else if ( choice == 0 )
        {
            break;
        }
        else
        {
            cout << "Invalid choice. \n";
        }

    }

    int digits = 0; int max = 0;

    /* --- Greatest number of voters --- */
    max = conservative;
    if ( labour > max )
    {
        max = labour;
    }
    if ( ukip > max )
    {
        max = ukip;
    }

    /* --- Number of the greatest number's digits --- */
    while ( max != 0 )
    {
        digits++;
        max = max / 10;
    }

    cout << "\n" << "\n" << "\n" << endl;
    int scale = 0;

    /* Determine scale */
    if ( digits == 1 )
    {
        scale = 1;
    }
    else if ( digits == 2 )
    {
        scale = 10;
    }
    else if ( digits == 3 )
    {
        scale = 100;
    }
    else if ( digits == 4 )
    {
        scale = 1000;
    }

    /* Output bar graph */
    cout << "Conservative: ";
    for ( int j = 1; j <= conservative / scale ; j++ )
    {
        cout << "*";
    }
    cout << "\n";

    cout << "Labour:       ";
    for ( int k = 1; k <= labour / scale; k++ )
    {
        cout << "*";
    }
    cout << "\n";

    cout << "UKIP:         ";
    for ( int g = 1 ; g <= ukip / scale; g++ )
    {
        cout << "*";
    }
    cout << "\n" << "Scale 1:" << scale << endl;
    return 0;
}
