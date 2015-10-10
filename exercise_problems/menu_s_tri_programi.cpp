#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

void MenuOutput ()
{
    cout << "1. Greatest of N numbers"    << endl;
    cout << "2. 100 Bottles of Beer"      << endl;
    cout << "3. Calculator"               << endl;
    cout << "4. Password checking system" << endl;
    cout << "5. Exit" << endl;
    cout << endl << endl;
}

int GreatestOfN ()
{
    int n;
    int a;
    cout << "Enter N: ";
    cin >> n;
    cout << "Start entering numbers, please. \n";
    cin >> a;
    int max;
    max = a;
    for ( int i = 1; i < n; i++ )
    {
        cin >> a;
        if ( a > max )
        {
            max = a;
        }
    }
    cout << "Result: " << max << endl;
}

void Bottles ( int number )
{
    for ( int i = number; i >= 1; i-- )
    {
        cout << i << " bottles of beer on the wall, " <<
            i << " bottles of beer \n" <<
                "Take one down and pass it around, ";
        if ( i != 1 )
        {
            cout << i - 1 << " bottles of beer on the wall. \n\n";
        }
        else
        {
            cout << "no more bottles of beer on the wall\n\n";
            cout << "Go to the store boy, we need moar. \n";
        }
    }
}

// Functions for the Calculator program below

float subirane ( float result, float b )
{
    return result + b;
}

float izvajdane ( float result, float b )
{
    return result - b;
}

float umnojenie ( float result, float b )
{
    return result * b;
}

float delenie ( float result, float b )
{
    return result / b;
}

void Calculator ()
{
    cout << setiosflags( ios::fixed ) << setiosflags( ios::showpoint ) <<
        setprecision(2);
    float result;
    char op;
    float b;
    cout << "Number -> Operation -> Number -> Operation -> ... Enter @ to exit. \n";
    cin >> result;
    while ( 1 )
    {
        cin >> op;
        if ( op == '@' )
        {
            break;
        }
        cin >> b;
        if ( op == '+' )
        {
            result = subirane ( result, b );
        }
        else if ( op == '-' )
        {
            result = izvajdane ( result, b );
        }
        else if ( op == '*' )
        {
            result = umnojenie ( result, b );
        }
        else if ( op == '/' )
        {
            while ( b == 0 )
            {
                cout << "Error! Division by 0! You crazy boai?? Try again.\n";
                cin >> b;
            }
            result = delenie ( result, b );
        }
        cout << "Current result: " << result << endl;
    }
    cout << "Final Result: " << result << endl;
}

void PasswordChecker ()
{
    string user_pass;
    cout << "Please enter your password: ";
    cin >> user_pass;
    int i = 1;
    while ( i < 3 )
    {
        cout << "Wrong password, please try again. \n";
        cin >> user_pass;
        if ( user_pass == "n00b" )
            break;
        i++;
    }
    if ( i < 3 )
    {
        cout << "Welcome back!\n";
    }
    else
    {
        cout << "Sorry, you ran out of attempts. \n";
    }
}

int main ()
{
    cout << "Please select an option of the following: \n";
    MenuOutput();
    char user_option;
    bool ifexit = false;
    // Keeps doing stuff until exit
    do
    {
    // Checks for correct option input
    do
    {
        cin >> user_option;
        if ( user_option == '1' )
        {
            GreatestOfN();
        }
        else if ( user_option == '2' )
        {
            cout << "How many bottles? " << endl;
            int number;
            cin >> number;
            Bottles ( number );
        }
        else if ( user_option == '3' )
        {
            Calculator();
        }
        else if ( user_option == '4' )
        {
            PasswordChecker();
        }
        else if ( user_option == '5' )
        {
            ifexit = true;
            break;
        }
        else
        {
            cout << "Invalid option, please try again." << endl;
        }
    } while ( user_option != '1' && user_option != '2' && user_option != '3' && user_option != '4' && user_option != '5' );
    } while ( ifexit == false );
    cout << "\n\n\nThank you for using my program!\n\n\n\n";
    return 0;
}
