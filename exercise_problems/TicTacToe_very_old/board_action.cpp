#include <iostream>

using namespace std;

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

int takeInput()
{
    int x;
    while ( 1 )
    {
        if ( !(cin >> x) )
        {
            cout << "Wrong input, please try again. \n";
            cin.clear();
            cin.ignore(10000,'\n');
        }
        else
        {
            if ( x >= 1 && x <= 3 )
            {
                break;
            }
            else
            {
                    cout << "Wrong input, please try again. \n";
            }
        }
    }
    return x;
}

void writeOnBoard ( char board[][7], char turn, int *p_moveCount )
{
    int x;
    int y;
    while ( 1 )
    {
        x = 0;
        y = 0;
        cout << "Enter x coordinate: ";
        x = takeInput();
        cout << "Enter y coordinate: ";
        y = takeInput();
        switch ( x )
        {
            case 3:
                x = 5;
                break;
            case 2:
                x = 3;
                break;
        }
        switch ( y )
        {
            case 3:
                y = 5;
                break;
            case 2:
                y = 3;
                break;
        }
        if ( board[y][x] != 'O' && board[y][x] != 'X' )
        {
            board[y][x] = turn;
            *p_moveCount = *p_moveCount + 1;
            break;
        }
        else
        {
            cout << "\nInvalid move, please try again.\n\n";
        }
    }
}
