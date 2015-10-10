#include <iostream>
#include <string>

using namespace std;

int number_of_figures ( int a )
{
    int figures = 0;
    while ( a != 0 )
    {
        figures++;
        a /= 10;
    }
    return figures;
}

bool isPalindrome ( int number )
{
    int figures = number_of_figures(number);
    int array[figures];
    int temp_holder = 0;
    int k = 1;

    while ( number != 0 )
    {
        temp_holder = number % 10;
        array[figures-k] = temp_holder;
        number /= 10;
        k++;
    }

    int mid = figures / 2;
    bool flag = true;

    for ( int i = 0; i < mid; i++ )
    {
        if ( array[i] != array[figures-1-i] )
        {
            flag = false;
            break;
        }
    }

    if ( flag == true )
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int number = 0;
    int max_palindrome = 0;
    bool flag = false;

    for ( int i = 999; i > 1; i-- )
    {
        for ( int j = 999; j >= i; j-- ) // optimized; used to be j > 1
        {
            number = i*j;
            if ( isPalindrome(number) == true )
            {
                if ( number > max_palindrome )
                {
                    max_palindrome = number;
                }
            }
        }
    }

    cout << max_palindrome << endl;

    return 0;
}
