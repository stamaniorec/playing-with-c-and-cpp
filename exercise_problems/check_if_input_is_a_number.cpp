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
    while ( int x = -1 )
    {
        if ( !(cin >> x) )
        {
            cout << "Wrong answer mothafucka. \n";
            cin.clear();
            cin.ignore(10000,'\n');
        }
        else 
        {
            cout << "Hi!\n";
            break;
        }
    }
    return 0;
}
