#include <iostream>

using namespace std;

char winner = ' ';

bool ifWin_Rows ( char board [][7] )
{
    char a;
    bool boolean;
    bool boolean1;
    for ( int y = 1; y < 7; y += 2 )
    {
        boolean = true;
        boolean1 = true;
        a = board [y][1];
        if ( a != 'O' && a != 'X' )
        {
            boolean1 = false;
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
            return true;
        }
    }
    return false;
}

bool ifWin_Columns ( char board[][7] )
{
    char a;
    bool boolean;
    bool boolean1;
    for ( int y = 1; y < 7; y += 2 )
    {
        boolean = true;
        boolean1 = true;
        a = board [1][y];
        if ( a != 'O' && a != 'X' )
        {
            boolean1 = false;
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
            return true;
        }
    }
    return false;
}

bool ifWin_Diagonals ( char board[][7] )
{
    /* Brute force, I know, but I was lazy ok? */
    char a;
    char b;
    bool boolean = true;
    bool boolean1 = true;
    a = board[1][1];
    if ( a != 'O' && a != 'X' )
        {
            boolean = false;
        }
    if ( board[3][3] == a )
    {
        if ( board[5][5] == a )
        {
            if ( boolean == true )
            {
                winner = a;
            }
        }
    }
    b = board[5][1];
    if ( b != 'O' && b != 'X' )
        {
            boolean1 = false;
        }
    if ( board[3][3] == b )
    {
        if ( board[1][5] == b )
        {
            if ( boolean1 == true )
            {
                winner = b;
            }
        }
    }
    if ( winner == 'O' || winner == 'X' )
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
}

char getWinner()
{
    return winner;
}
