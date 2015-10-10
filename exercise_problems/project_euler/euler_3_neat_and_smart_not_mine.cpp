#include <iostream>
using namespace std;

int main()
{
    unsigned long long BIG = 600851475143LL;
    unsigned long long count;

    for(count = 2; count < BIG/2; count++)
    {
        if(0 == BIG % count)
        {
            BIG /= count;
        }
    }

    cout << "Biggest prime factor is " <<  BIG << endl;

    return 0;
}
