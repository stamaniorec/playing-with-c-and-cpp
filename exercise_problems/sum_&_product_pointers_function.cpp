#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

void myFunction ( int a, int b, int *sum, int *product )
{
    *sum = a + b;
    *product = a * b;
}

int main ()
{
    int x, y;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    int sum = 0;
    int product = 0;
    myFunction ( x, y, & sum, & product );
    cout << "The sum of " << x << " and " << y << " is: "
        << sum;
    cout << "\nThe product of " << x << " and " << y << " is: "
        << product << endl;
    return 0;
}
