#include <stdio.h>
#include "./board.h"
#include "./actions.h"

int main() {
    char board[9][9];
    char hw[8][8], vw[8][8];

    int i, j;

    // Correct starting positions
    int p1r = 0, p1c = 4;
    int p2r = 8, p2c = 4;






    int r, c, nr, nc;
    int player = 1;

    int p1w = 10, p2w = 10;
    int valid;

    char move_wall, direction;

    // Initialize board
    initializeBoard(board, hw, vw);

    // Starting positions
    board[p1r][p1c] = '1';
    board[p2r][p2c] = '2';

    while(1) {
        displayBoard(board, hw, vw);

        printf("\nPlayer %d's turn\n", player);

        printf("Walls remaining: %d\n", player == 1 ? p1w : p2w);
        
        printf("Enter M to move or W to place wall: ");
        scanf(" %c", &move_wall);

        // ---------------- MOVEMENT ----------------

        if(move_wall == 'M' || move_wall == 'm')
        {
            bool isValidAction = movePlayer(board,hw,vw, player == 1 ? &p1r : &p2r , player == 1 ? &p1c : &p2c);
            if(isPlayerAtEdge(board, player, nr, nc)){
                displayBoard(board, hw, vw);
                printf("\nPLAYER %d WINS!\n", player);
                break;
            }
            if (isValidAction) {
                player = (player == 1) ? 2 : 1;  
            }
        }

        // ---------------- WALL PLACEMENT ----------------

        else if(move_wall == 'W' || move_wall == 'w')
        {
            if((player == 1 && p1w == 0) ||
               (player == 2 && p2w == 0))
            {
                printf("No walls remaining!\n");
                continue;
            }

            printf("Enter wall direction (H/V): ");
            scanf(" %c", &direction);

            printf("Enter wall row and column (0-7): ");
            scanf("%d %d", &r, &c);

            if(r < 0 || r >= 8 || c < 0 || c >= 8)
            {
                printf("Invalid wall position!\n");
                continue;
            }

            valid = 1;

            // Horizontal wall
            if(direction == 'H' || direction == 'h')
            {
                if(hw[r][c] == 'H' ||
                   hw[r][c+1] == 'H' ||
                   vw[r][c] == 'V')
                {
                    valid = 0;
                }

                if(!valid)
                {
                    printf("Wall overlaps an existing wall!\n");
                    continue;
                }

                hw[r][c] = 'H';
                hw[r][c+1] = 'H';
            }

            // Vertical wall
            else if(direction == 'V' || direction == 'v')
            {
                if(vw[r][c] == 'V' ||
                   vw[r+1][c] == 'V' ||
                   hw[r][c] == 'H')
                {
                    valid = 0;
                }

                if(!valid)
                {
                    printf("Wall overlaps an existing wall!\n");
                    continue;
                }

                vw[r][c] = 'V';
                vw[r+1][c] = 'V';
            }

            else
            {
                printf("Invalid wall direction!\n");
                continue;
            }

            // Reduce wall count
            if(player == 1)
                p1w--;
            else
                p2w--;

            printf("Wall placed successfully!\n");

            // Change turn
            player = (player == 1) ? 2 : 1;    
        }
        else
        {
            printf("Invalid choice! Enter M or W.\n");
        }
    }

    return 0;
}