#ifndef CHECK_FOR_WIN_H
#define CHECK_FOR_WIN_H

bool ifWin_Rows ( char board [][7] );
bool ifWin_Columns ( char board[][7] );
bool ifWin_Diagonals ( char board[][7] );
bool ifWin ( char board[][7] );
char getWinner();

#endif
