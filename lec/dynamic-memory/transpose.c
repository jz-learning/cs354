#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

// TODO: Create a transpose of this matrix

// create a new matrix in the heap
int **transpose(int a[ROWS][COLS]) {
    int **p = malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        p[i] = malloc(COLS * sizeof(int));
    }

    //* create transpose
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            p[i][j] = a[j][i];
        }
    }
    return p;
}

int main() {
    int a[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("a[%d][%d] = %d\t", i, j, a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int **t = transpose(a);
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("t[%d][%d] = %d\t", i, j, t[i][j]);
        }
        printf("\n");
    }

    return 0;
}
