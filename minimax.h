#ifndef MINIMAX_H_
#define MINIMAX_H_

#define MAXCHILD 9

struct node {
    char grid[3][3];
    float eval;
    struct node *children[MAXCHILD];
};

// minimax: uses the minimax algorithm to find the best move, returns a pointer to this move
struct node *minimax(struct node *root, char grid[3][3], int depth, int isMaximizer);
// gridcopy: copy the grid in "source" to "destination"
void gridcopy(char destination[3][3], char source[3][3]);

#endif