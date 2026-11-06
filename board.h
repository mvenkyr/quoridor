#ifndef BOARD_H
#define BOARD_H

void displayBoard(char board[9][9], char h[8][8], char vwall[8][8]);
void initializeBoard(char board[9][9], char h[8][8], char vwall[8][8]);
bool isPlayerAtEdge(char board[9][9], int player, int r, int c);

#endif