#include "./actions.h"

bool movePlayer(char board[9][9],char hw[8][8],char vw[8][8], int* r, int* c){
    int nr, nc;

    printf("Enter destination row and column: ");
    scanf("%d %d", &nr, &nc);

    if(nr < 0 || nr >= 9 || nc < 0 || nc >= 9)
    {
        printf("Invalid position!\n");
        return false;
    }

    if(board[nr][nc] != ' ')
    {
        printf("Position occupied!\n");
        return false;
    }

    if(!((nr == *r-1 && nc == *c) ||
            (nr == *r+1 && nc == *c) ||
            (nr == *r && nc == *c-1) ||
            (nr == *r && nc == *c+1)))
    {
        printf("Invalid move!\n");
        return false;
    }

    // Check horizontal walls
    if(nr == *r-1 &&
        (hw[*r-1][*c] == 'H' ||
        (*c > 0 && hw[*r-1][*c-1] == 'H')))
    {
        printf("Wall blocks movement!\n");
            return false;
    }

    if(nr == *r+1 &&
        (hw[*r][*c] == 'H' ||
        (*c > 0 && hw[*r][*c-1] == 'H')))
    {
        printf("Wall blocks movement!\n");
        return false;
    }

    // Check vertical walls
    if(nc == *c-1 &&
        (vw[*r][*c-1] == 'V' ||
        (*r > 0 && vw[*r-1][*c-1] == 'V')))
    {
        printf("Wall blocks movement!\n");
        return false;
    }

    if(nc == *c+1 &&
        (vw[*r][*c] == 'V' ||
        (*r > 0 && vw[*r-1][*c] == 'V')))
    {
        printf("Wall blocks movement!\n");
        return false;
    }
    char player = board[*r][*c];
    // Update board
    board[*r][*c] = ' ';
    board[nr][nc] = (player == '1') ? '1' : '2';
    *r = nr;
    *c = nc;

    return true;
}

