#include <iostream>

using namespace std;

int divisible_by( int a, int target );

int main ()
{
	int target = 999;
    cout << divisible_by(3, target) + divisible_by(5, target) - divisible_by(15, target);
	return 0;
}

int divisible_by( int a, int target )
{
    int p = target / a;
    return a*(p*(p+1)) / 2;
}
