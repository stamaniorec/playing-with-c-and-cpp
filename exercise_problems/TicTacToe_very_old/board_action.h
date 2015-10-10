#ifndef BOARD_ACTION_H
#define BOARD_ACTION_H

void setBoard ( char board[][7] );
void printBoard ( char board[][7] );
int takeInput();
void writeOnBoard ( char board[][7], char turn, int *p_moveCount );

#endif
