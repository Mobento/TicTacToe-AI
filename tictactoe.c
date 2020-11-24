#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// use char to not take too much space
char gamegrid[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

void show_grid(char grid[3][3])
{
    int i, j;
    printf("+---+---+---+\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            // print X or O if there's no digit in the current position
            printf("| %c ", (grid[i][j] == 'X' || grid[i][j] == 'O') ? grid[i][j] : grid[i][j] + '0');
        }
        printf("|\n");
        printf("+---+---+---+\n");
    }
}

int getsign(char sign, int pos)
{
    int row, column;
    column = (pos - 1) % 3;
    row = (pos - 1) / 3;
    if (gamegrid[row][column] != 'X' && gamegrid[row][column] != 'O') {
        gamegrid[row][column] = sign;
        return 1;
    }
    return -1;
}


int isWin(char grid[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++) {
        // check for vertical equality
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
            return (grid[0][i] == 'X') ? 1 : -1;
        }
        // check for horizental equality 
        else if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            return (grid[i][0] == 'X') ? 1 : -1;
        }
        // check for diagonal equality
        else if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
            return (grid[0][0] == 'X') ? 1 : -1;
        } else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
            return (grid[0][2] == 'X') ? 1 : -1;
        }
    }
    return 0;
}

int isTie(char grid[3][3])
{
    int i, j;
    // loop through each place, if a place does not have neither
    // and X or an O, this means that this place is still playable and that it's not the end
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] != 'X' && grid[i][j] != 'O')
                return 1;
        }
    }
    return 0;
}