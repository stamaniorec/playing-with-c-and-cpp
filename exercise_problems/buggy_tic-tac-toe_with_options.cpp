#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdlib>


using namespace std;

int moveCount = 0;
char winner = ' ';
int size1;

void setBoard ( char board[][size1], int size1 )
{
    /* ---       Sets the |'s        --- */

    for ( int i = 0; i < size1; i++ )
    {
        for ( int j = 0; j < size1; j += 2 )
        {
            board[i][j] = '|';
        }
    }

    /* ---       Sets the -'s        --- */

    for ( int k = 0; k < size1; k += 2 )
    {
        for ( int m = 1; m < size1; m += 2 )
        {
            board[k][m]='-';
        }
    }

    /* ---       Sets empty spaces        --- */

    for ( int a = 1; a < size1; a += 2 )
    {
        for ( int b = 1; b < size1; b += 2 )
        {
            board[a][b] = ' ';
        }
    }

}

void printBoard ( char board[][7] )
{
    for ( int k = 0; k < 7; k ++ )
    {
        for ( int m = 0; m < 7; m++ )
        {
            cout << board[k][m] << " ";
        }
        cout << endl;
    }
}

bool ifWin_Rows ( char board [][7], int size1 )
{
    char a;
    bool boolean;
    bool boolean1;
    bool checky = false;
    for ( int y = 1; y < size1; y += 2 )
    {
        boolean = true;
        boolean1 = true;
        a = board [y][1];
        if ( a != 'O' && a != 'X' )
        {
            boolean1 = false;;
        }
        for ( int x = 3; x < size1; x += 2 )
        {
            if ( board[y][x] != a )
            {
                boolean = false;
                break;
            }
        }
        if ( boolean == true && boolean1 == true )
        {
            winner = a;
            checky = true;
            return true;
            break;
        }
    }
    if ( checky == false )
    {
        return false;
    }
}

bool ifWin_Columns ( char board[][7], int size1 )
{
    char a;
    bool boolean;
    bool boolean1;
    bool checky = false;
    for ( int y = 1; y < size1; y += 2 )
    {
        boolean = true;
        boolean1 = true;
        a = board [1][y];
        if ( a != 'O' && a != 'X' )
        {
            boolean1 = false;;
        }
        for ( int x = 3; x < size1; x += 2 )
        {
            if ( board[x][y] != a )
            {
                boolean = false;
                break;
            }
        }
        if ( boolean == true && boolean1 == true )
        {
            winner = a;
            checky = true;
            return true;
            break;
        }
    }
    if ( checky == false )
    {
        return false;
    }
}

bool ifWin_Diagonals ( char board[][7], int size1 )
{
    char a;
    char b;
    bool boolean = true;
    bool boolean1 = true;
    bool boolean2 = true;
    bool boolean3 = true;
    a = board[1][1];
    if ( a != 'O' && a != 'X' )
    {
        boolean = false;
    }
    for ( int i = 3; i < size1; i += 2 )
    {
        if ( board[i][i] != a )
        {
            boolean1 = false;
            break;
        }
    }
    b = board[size1][1];
    if ( b != 'O' && b != 'X' )
    {
        boolean2 = false;
    }
    for ( int i = 2; i < size1; i++ )
    {
        if ( board[size1-i][1+i] != b )
        {
            boolean3 = false;
            break;
        }
    }
    if ( boolean == true && boolean1 == true )
    {
        winner = a;
        return true;
    }
    else if ( boolean2 == true && boolean3 == true )
    {
        winner = b;
        return true;
    }
    else
    {
        return false;
    }
}

bool ifWin ( char board[][7], int size1 )
{
    bool a = ifWin_Rows ( board, size1 );
    bool b = ifWin_Columns ( board, size1 );
    bool c = ifWin_Diagonals ( board, size1 );
    if ( a == true || b == true || c == true )
    {
        return true;
    }
    else
    {
        return false;
    }
    return a;
}

void writeOnBoard ( char board[][7], char turn )
{
    int x;
    int y;
    while ( 1 )
    {
        x = 0;
        y = 0;
        cout << "Enter x coordinate: ";
        cin >> x;
        cout << "Enter y coordinate: ";
        cin >> y;
        switch ( x )
        {
            case 3: x = 5;
            break;
            case 2: x = 3;
            break;
        }
        switch ( y )
        {
            case 3: y = 5;
            break;
            case 2: y = 3;
            break;
        }
        if ( board[y][x] != 'O' && board[y][x] != 'X' )
        {
            board[y][x] = turn;
            moveCount++;
            break;
        }
        else
        {
            cout << "\nInvalid move, please try again.\n\n";
        }
    }
}


int main ()
{
    cout << "How big do you want your board to be? Enter a number. Example: 3 -> 3x3 board\n";
    int x = 0;
    int input;
    while ( x = -1 )
    {
        if ( !(cin >> x) )
        {
            cout << "Wrong answer mothafucka. \n";
            cin.clear();
            cin.ignore(10000,'\n');
        }
        else if ( x != -1 )
        {
            input = x;
            if ( input >= 2 && input <= 9 )
            {
                break;
            }
            else
            {
                cout << "Wrong answer mothafucka. \n";
            }
        }
    }
    size1 = 2*input + 1;
    char board[size1][size1];
    setBoard ( board, size1 );
    int i = 0;
    char turn;
    while ( ifWin ( board, size1 ) != true && moveCount < 9)
    {
        if ( i % 2 == 0 )
        {
            turn = 'O';
        }
        else
        {
            turn = 'X';
        }
        cout << "It is " << turn << "'s turn! \n\n\n";
        printBoard ( board );
        cout << endl << endl;
        writeOnBoard ( board, turn );
        i++;
        system("CLS");
    }
    cout << "Congratulations, the game is over!" << endl;
    if ( winner != 'O' && winner != 'X' )
    {
        cout << "The game is a tie. \n";
    }
    else
    {
        cout << "Winner: " << winner << endl;
    }
    return 0;
}
