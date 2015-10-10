#include <iostream>

using namespace std;

bool is_even (int a)
{
    if ( a % 2 == 0 )
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
    int a = 1, b = 1;
    int i = 2;
    int fib = 1;
    int sum = 0;
    while ( fib < 4000000 )
    {
        fib = a + b;
        if ( is_even(fib) == true )
        {
            sum += fib;
        }
        a = b;
        b = fib;
        i += 2;
    }
    cout << sum << endl;
    return 0;
}
