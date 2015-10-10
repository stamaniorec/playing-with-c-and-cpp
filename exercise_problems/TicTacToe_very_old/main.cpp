#include <iostream>
#include "board_action.h"
#include "check_for_win.h"

using namespace std;

int main ()
{
    char winner;
    char board[7][7];
    setBoard ( board );
    int i = 0;
    int moveCount = 0;
    char turn;
    while ( ifWin ( board ) != true && moveCount < 9 )
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
        writeOnBoard ( board, turn, & moveCount );
        i++;
    }
    cout << "Congratulations, the game is over!" << endl;
    winner = getWinner();
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
