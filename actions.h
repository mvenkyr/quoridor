#ifndef ACTIONS_H
#define ACTIONS_H


bool movePlayer(char board[9][9],char hw[8][8],char vw[8][8], int* r, int* c);
void placeWall(char board[9][9], char h[8][8], char vwall[8][8], int row, int col, char direction);

#endif