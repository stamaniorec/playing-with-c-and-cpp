#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
Даден е масив А, съдържащ 5 произволни символи.
Напишете програма, която определя колко от тях са малки английски букви, колко са главни английски букви, колко са цифри
и колко са други символи.
*/

void check ( char c, int *p_lower, int *p_upper, int *p_numbers, int *p_others )
{
    if ( c >= 'a' && c <= 'z' )
        *p_lower += 1;
    else if ( c >= 'A' && c <= 'Z' )
        *p_upper += 1;
    else if ( c >= '0' && c <= '9' )
        *p_numbers += 1;
    else
        *p_others += 1;
}

int main ()
{
    srand ( time ( NULL ) );
    char masiv[5];
    int random = 0;
    int lower = 0;
    int upper = 0;
    int numbers = 0;
    int other = 0;
    for ( int i = 0; i < 5; i++ )
    {
        random = rand() % 130;
        masiv[i] = toascii(random);
        check ( masiv[i], & lower, & upper, & numbers, & other );
        cout << masiv[i] << " ";
    }
    cout << "\nLower case: " << lower << endl;
    cout << "Upper case: " << upper << endl;
    cout << "Numbers: " << numbers << endl;
    cout << "Others: " << other << endl;
    return 0;
}
