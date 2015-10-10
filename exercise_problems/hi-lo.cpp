#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Function declarations */

int f_user_input();
void f_actual_stuff(int, int);

/* --------------------- */

int main ()
{
    /* --- Variables --- */

    int user_input;
    int random;

    /* ----------------- */

    srand ( time ( NULL ) );

    cout << "Enter a number between 1 and 100. \n";
    user_input = f_user_input();

    random = rand ();
    random = random % ( 100 - 1 ) + 1;

    cout << "Random: " << random << endl;

    f_actual_stuff ( random, user_input );

    return 0;
}

int f_user_input ()
{
    int user_input;
    while ( 1 )
        {
            cin >> user_input;
            if ( user_input < 1 || user_input > 100 )
            {
                cout << "Nasty input man, try again. \n";
            }
            else
            {
                break;
            }
        }
    return user_input;
}

void f_actual_stuff ( int random, int user_input )
{
    bool correct = false;
    while ( 1 )
    {
        if ( user_input > random )
        {
            cout << "Too high. \n";
        }
        if ( user_input < random )
        {
            cout << "Too low. \n";
        }
        if ( user_input == random )
        {
            cout << "You're goddamn right!";
            correct = true;
            break;
        }
        if ( correct != true )
        {
            cout << "Please try again. \n";
            cin >> user_input;
        }
    }
}
