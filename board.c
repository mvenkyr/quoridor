#include "./board.h"


void initializeBoard(char board[9][9], char h[8][8], char vwall[8][8]){
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            board[i][j] = ' ';

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++) {
            h[i][j] = ' ';
            vwall[i][j] = ' ';
        }
}

void displayBoard(char board[9][9], char h[8][8], char vwall[8][8]){
    printf("\n     ");

    for(int j = 0; j < 9; j++)
        printf("  %d   ", j);

    printf("\n");

    for(int i = 0; i < 9; i++)
    {
        // Horizontal walls
        printf("   ");

        for(int j = 0; j < 9; j++)
        {
            if(i > 0 && j < 8 && h[i-1][j] == 'H')
                printf("******");
            else
                printf("------");
        }

        printf("-\n");

        // Player positions and vertical walls
        printf("%d  |", i);

        for(int j = 0; j < 9; j++)
        {
            printf("  %c  ", board[i][j]);

            if(j < 8)
            {
                if(i < 8 && vwall[i][j] == 'V')
                    printf("*");
                else
                    printf("|");
            }
        }

        printf("|\n");
    }

    printf("   ");

    for(int j = 0; j < 9; j++)
        printf("------");

    printf("-\n");


}

bool isPlayerAtEdge(char board[9][9], int player, int r, int c){
    return (player == 1 && r == 8) || (player == 2 && r == 0);
}
