/* NOTE: THE AI PLAYES WITH X */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "tictactoe.h"
#include "minimax.h"

// creates all the game possibilities as node children
void childcreate(struct node *root, int isX, int depth);

int minimax_algorithm(struct node *root, char grid[3][3], int depth, int isMaximizer);

struct node *minimax(struct node *root, char grid[3][3], int depth, int isMaximizer)
{
    int i, eval;
    root = (struct node *) malloc(sizeof(struct node));
    gridcopy(root->grid, grid);
    childcreate(root, isMaximizer, depth);
    eval = minimax_algorithm(root, root->grid, depth, isMaximizer);
    for (i = 0; i < MAXCHILD; i++) {
        if (root->children[i]->eval == eval) {
            return root->children[i];
        }
    }
}

int minimax_algorithm(struct node *cnode, char grid[3][3], int depth, int isMaximizer)
{
    int result, i;
    int max_eval, min_eval, eval;
    if ((result = isWin(cnode->grid)) || depth == 0) {
        cnode->eval = result;
        return result;
    } else if ((result = isTie(cnode->grid)) == 0) {
        cnode->eval = result;
        return result;
    }

    if (isMaximizer) {
        max_eval = -100;
        // find the maximum game evaluation from all the children
        for (i = 0; i < MAXCHILD && cnode->children[i] != NULL; i++) {
            eval = minimax_algorithm(cnode->children[i], cnode->grid, depth - 1, 0);
            max_eval = (eval > max_eval) ? eval : max_eval;
        }
        cnode->eval = max_eval;
        return max_eval;
    } else {
        min_eval = 100;
        // find the minimum game evaluation from all the children 
        for (i = 0; i < MAXCHILD && cnode->children[i] != NULL; i++) {
            eval = minimax_algorithm(cnode->children[i], cnode->grid, depth - 1, 1);
            min_eval = (eval < min_eval) ? eval : min_eval;
        }
        cnode->eval = min_eval;
        return min_eval;
    }
}

void childcreate(struct node *root, int isX, int depth)
{
    // cchild: index of the current child to work on
    int i, j, cchild;
    int result;
    // set all the children of the current node to NULL
    for (i = 0; i < MAXCHILD; i++) {
        root->children[i] = NULL;
    }
    
    if ((result = isWin(root->grid)) || depth == 0) {
        return;
    }

    for (i = cchild = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (root->grid[i][j] != 'X' && root->grid[i][j] != 'O') {
                root->children[cchild] = (struct node *) malloc(sizeof(struct node));
                gridcopy(root->children[cchild]->grid, root->grid);
                root->children[cchild]->grid[i][j] = (isX) ? 'X' : 'O';
                childcreate(root->children[cchild], (isX) ? 0 : 1, depth - 1);
                cchild++;
            }
        }
    }
}

void gridcopy(char destination[3][3], char source[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            destination[i][j] = source[i][j];
        }
    }    
}