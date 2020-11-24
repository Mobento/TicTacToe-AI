#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "minimax.h"
#include "tictactoe.h"

#define MAXMOVES 255168

int main(void)
{
    // clear everything so that the command is clear
    system("cls");
    struct node *root = NULL;
    int player, sign, pos, result;
    player = 'O';
    while (!(result = isWin(gamegrid)) && isTie(gamegrid) != 0) {
        // set player to O if it was X and vice versa
        player = (player == 'X') ? 'O' : 'X';
        show_grid(gamegrid);
        printf("It is the turn of %c to play: ", player);
        if (player == 'O') {
            scanf("%d", &pos);
            if (getsign(player, pos) == -1) {
                printf("Error: Cannot place at this slot\n");
                sleep(1.5);
            }
        } else {
            sleep(1);
            root = minimax(root, gamegrid, MAXMOVES, 1);
            gridcopy(gamegrid, root->grid);
        }
        system("cls");
    }
    show_grid(gamegrid);
    if (isTie(gamegrid) == 0) {
        printf("The game is a Tie!\n");
    } else {
        printf("Player %c won, Congrats!\n", (result == 1) ? 'X' : 'O');
    }
    return 0;
}