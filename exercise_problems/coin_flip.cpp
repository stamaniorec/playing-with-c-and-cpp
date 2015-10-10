#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main ()
{
    srand ( time ( NULL ) );
    char user_input;
    cout << "Heads or Tails? Please enter 0 for Heads or 1 for Tails." << endl;
    while ( 1 )
    {
        cin >> user_input;
        if ( user_input != '0'  && user_input != '1' )
        {
            cout << "Hm, wrong input. Please try again." << endl;
        }
        else
        {
            break;
        }
    }
    int random;
    random = rand();
    char random1;
    if ( random % 2 == 0 )
    {
        random1 = '0';
    }
    else
    {
        random1 = '1';
    }
    if ( user_input == random1 )
    {
        cout << "You were right!" << endl;
    }
    else
    {
        cout << "Sorry, you lose." << endl;
    }
    return 0;
}
