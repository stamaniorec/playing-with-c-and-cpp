#include <iostream>

using namespace std;

int main()
{
    int number = 1;
    bool flag;
    while ( 1 )
    {
        flag = true;
        for ( int i = 1; i <= 20; i++ )     // for this problem in particular you can just go from 11 to 20
        {
            if ( number % i != 0 )
            {
                flag = false;
                break;
            }
        }
        if ( flag == true )
        {
            cout << number << endl;
            break;
        }
        number++;
    }
    return 0;
}
