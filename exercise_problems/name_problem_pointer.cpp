#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

void userInput ( string *p_first, string *p_second )
{
    cout << "Please enter your first name: ";
    cin >> *p_first;
    cout << "Please enter your family name: ";
    cin >> *p_second;

}

int main ()
{
    string first_name = "", family_name = "";
    userInput ( & first_name, & family_name );
    cout << "Your name is: " << first_name << " " << family_name << endl;
    return 0;
}
