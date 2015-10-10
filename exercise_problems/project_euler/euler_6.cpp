#include <iostream>

using namespace std;

int sum_of_squares ( int n )
{
    int sum = 0;

    for ( int i = 1; i <= n; i++ )
    {
        sum += ( i * i );
    }

    return sum;
}

int square_of_sum ( int n )
{
    int sum = 0;

    for ( int i = 1; i <= n; i++ )
    {
        sum += i;
    }

    return sum * sum;
}

int main()
{
    const int limit = 100;

    long long b = sum_of_squares(limit);
    long long a = square_of_sum(limit);

    cout << a - b << endl;

    return 0;
}
