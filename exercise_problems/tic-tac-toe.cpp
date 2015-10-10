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

void setBoard ( char board[][7] )
{
    /* ---       Sets the |'s        --- */

    for ( int i = 0; i < 7; i++ )
    {
        for ( int j = 0; j < 7; j += 2 )
        {
            board[i][j] = '|';
        }
    }

    /* ---       Sets the -'s        --- */

    for ( int k = 0; k < 7; k += 2 )
    {
        for ( int m = 1; m < 7; m += 2 )
        {
            board[k][m]='-';
        }
    }

    /* ---       Sets empty spaces        --- */

    for ( int a = 1; a < 7; a += 2 )
    {
        for ( int b = 1; b < 7; b += 2 )
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

bool ifWin_Rows ( char board [][7] )
{
    char a;
    bool boolean;
    bool boolean1;
    bool checky = false;
    for ( int y = 1; y < 7; y += 2 )
    {
        boolean = true;
        boolean1 = true;
        a = board [y][1];
        if ( a != 'O' && a != 'X' )
        {
            boolean1 = false;;
        }
        for ( int x = 3; x < 7; x += 2 )
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

bool ifWin_Columns ( char board[][7] )
{
    char a;
    bool boolean;
    bool boolean1;
    bool checky = false;
    for ( int y = 1; y < 7; y += 2 )
    {
        boolean = true;
        boolean1 = true;
        a = board [1][y];
        if ( a != 'O' && a != 'X' )
        {
            boolean1 = false;;
        }
        for ( int x = 3; x < 7; x += 2 )
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

bool ifWin_Diagonals ( char board[][7] )
{
    char a;
    char b;
    bool boolean = false;
    bool boolean1 = false;
    bool boolean2 = true;
    bool boolean3 = true;
    a = board[1][1];
    if ( a != 'O' && a != 'X' )
        {
            boolean2 = false;;
        }
    if ( board[3][3] == a )
    {
        if ( board[5][5] == a )
        {
            if ( boolean2 == true )
            {
                boolean = true;
                winner = a;
            }
        }
    }
    b = board[5][1];
    if ( b != 'O' && b != 'X' )
        {
            boolean3 = false;;
        }
    if ( board[3][3] == b )
    {
        if ( board[1][5] == b )
        {
            if ( boolean3 == true )
            {
                boolean1 = true;
                winner = b;
            }
        }
    }
    if ( ( boolean == true && boolean2 == true ) || ( boolean1 == true && boolean3 == true ) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ifWin ( char board[][7] )
{
    bool a = ifWin_Rows ( board );
    bool b = ifWin_Columns ( board );
    bool c = ifWin_Diagonals ( board );
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
    char board[7][7];
    setBoard ( board );
    int i = 0;
    char turn;
    while ( ifWin ( board ) != true && moveCount < 9)
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
