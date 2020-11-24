#ifndef TICTACTOE_H_
#define TICTACTOE_H_

extern char gamegrid[3][3];

// show_grid: shows the X, O grid
void show_grid(char grid[3][3]);
// getsign: gets a sign and place it at the position pos (sign = X or O)
int getsign(char sign, int pos);
// isWin: returns 1 if X is the winner, -1 if O, 0 if none
int isWin(char grid[3][3]);
int isTie(char grid[3][3]);

#endif