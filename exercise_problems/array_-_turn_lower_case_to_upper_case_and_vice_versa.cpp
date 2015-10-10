#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

/*

Даден е масив А, съдържащ 5 произволни символи, които са малки или главни английски букви.
Напишете програма, която преобразува масива, като заменя всяка малка буква със съответната главна и обратно.

*/
int main ( )
{
    char masiv[5] = {'a', 'G', 'D', 'c', 'f'};
    int k = 'a' - 'A';
    for ( int i = 0; i < 5; i++ )
    {
        if ( masiv[i] >= 'a' && masiv[i] <= 'z' )
            masiv[i] = toascii( masiv[i] - k );
        else
            masiv[i] = toascii( masiv[i] + k );
        cout << masiv[i] << " ";
    }
    cout << endl;
    return 0;
}
