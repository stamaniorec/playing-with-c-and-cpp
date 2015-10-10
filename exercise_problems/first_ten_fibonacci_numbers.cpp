#include <iostream>

using namespace std;

int main()
{
    // 1 1 2 3 5 8 11
    int a = 1;
    int b = 1;
    int fib = 1;
    int i = 2;
    cout << "1 1 ";
    while ( i < 10 )
    {
        fib = a + b;
        a = b;
        b = fib;
        i++;
        cout << fib << " ";
    }


    return 0;
}
