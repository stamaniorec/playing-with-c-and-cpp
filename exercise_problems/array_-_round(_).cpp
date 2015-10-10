#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
Оценките на 5 ученика от 11в клас от контролно по информатика се съхраняват в масив A.
Напишете програма, която коригира с +0,5 всички оценки в класа, ако това е възможно.

*/

int main ()
{
    float myArray[5] = { 3, 4.5, 4, 5.5, 6 };
    for ( int i = 0; i < 5; i++ )
    {
        myArray[i] = round (myArray[i]);
        cout << myArray[i] << " ";
    }
    cout << endl;
    return 0;
}
