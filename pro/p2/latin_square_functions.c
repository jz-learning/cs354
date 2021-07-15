// James Zhang
// jzhang924
// JAMES ZHANG
// 9079769411
// 7/14/2021
// N/A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ascii code of the new line character
#define NL 10

// structure for keeping count of each incountered char, size if 8 bytes
typedef struct {
    char c;
    int count;
} CL;

/**
 * This helper function returns 1 if the character is between 33: '!' and 126: '~'
 * returns 0 otherwise
 *
 * @param c  :: pointer to the char calue
 * @return   :: if the char is valid
 */
int Valid_Symbol(char c) { return (c >= 33) && (c <= 126); }

/**
 * This function takes the name of the file containing the latin square puzzle
 * and reads in the data to the the latin_square variable in main.
 *
 * @param n               :: the dimensions of the board.
 *                           Note all boards tested will be square (i.e. nxn)
 * @param filename        :: the name of the file to read in
 * @param latin_square_in :: a pointer to the latin square variable in main
 */
void Read_Latin_Square_File(char *filename, char ***latin_square_in, int *n) {
    // Open file and make sure it exists
    FILE *f = fopen(filename, "r");
    if (f == NULL) return;

    int c;

    // For keeping count of #of chars in the first row
    int temp = 0;

    // Reads file to find the size of the matrix
    while ((c = getc(f)) != EOF) {
        // After reaching new line, assign temp to size (n)
        if (c == NL && !*n) *n = temp;
        temp++;
    }
    fclose(f);

    // Assigns n to size for clearity and readibility
    int size = *n;
    //? printf("The size of the array is: %i\n\n", size);

    // TODO allocate memory based on size
    //? printf("Allocating memory for matrix\n\n");

    char **matrix = malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        *(matrix + i * sizeof(char)) = malloc(size * sizeof(char));
    }

    if (matrix == NULL) {
        printf("Something's wrong with memory allocation\n");
    }

    *latin_square_in = matrix;

    // TODO assign matrix to reserved memory
    //? printf("Assigning chars to the matrix in heap\n");

    f = fopen(filename, "r");
    // Initializing index variables
    int i = 0;
    int j = 0;
    // Reads each character of the grid and adds to matrix
    while ((c = getc(f)) != EOF) {
        //? printf("%c", c);

        // When reaching an end line character go to new row
        // and reset col count
        if (c == NL) {
            i++;
            j = 0;
            continue;
        }
        matrix[i][j] = c;
        j++;
    }
    fclose(f);
    return;
}

/**
 * This function checks to see that exactly n symbols are used and that each symbol is used exactly
 * n times. Valid symbols include charcters with ascii codes 33 to 126 (inclusive) Google "man
 * ascii" to pull up the table
 *
 * @param n            :: the dimensions of the puzzle - all puzzles will be square (i.e. nxn)
 * @param latin_square :: the puzzle data structure
 * @return             :: 0 if the alphabet is invalid and 1 if the alphabet is valid
 */
int Verify_Alphabet(int n, char **latin_square) {
    if (latin_square == NULL) {
        printf("Verify_Alphabet - latin_square is NULL\n");
        return 0;
    }

    // Checks to make sure each character is valid
    for (int i = 0; i < n; i++) {
        char c = latin_square[0][i];
        if (!Valid_Symbol(c)) return 0;
    }

    // create a dynamic array on the heap
    CL *a = calloc(n, sizeof(CL));

    // double checking to make sure allocation succeeds
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    //? printf("\nchar is: %c\ncount is: %i\n", a[0].c, a[0].count);
    //? printf("char is: %c\ncount is: %i\n", a[1].c, a[1].count);
    //? printf("char is: %c\ncount is: %i\n", a[2].c, a[2].count);
    //? printf("char is: %c\ncount is: %i\n", a[3].c, a[3].count);

    // TODO populate the map with char's and counts
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // increment the count of each char
            for (int k = 0; k < n; k++) {
                // if char wasn't in the map,
                // add it
                if (!a[k].c) {
                    a[k].c = latin_square[i][j];
                    a[k].count = 1;
                    break;
                }
                // if char is already in the map,
                // increment its count
                else if (latin_square[i][j] == a[k].c) {
                    a[k].count++;
                    break;
                }
            }
        }
    }

    // Checks if the count of each char has the right amount, n
    for (int i = 0; i < n; i++) {
        if (!a[i].c) {
            printf("Map not filled fully!\n");
            return 0;
        }
        if (a[i].count != n) {
            printf("Char: '%c' doesn't have the right count\n", a[i].c);
            printf("Expected: %i\nActual: %i\n", n, a[i].count);
            return 0;
        }
        return 1;
    }

    //? printf("\nchar is: %c\ncount is: %i\n", a[0].c, a[0].count);
    //? printf("char is: %c\ncount is: %i\n", a[1].c, a[1].count);
    //? printf("char is: %c\ncount is: %i\n", a[2].c, a[2].count);
    //? printf("char is: %c\ncount is: %i\n", a[3].c, a[3].count);

    //? printf("There are %i unique chars.\n", UniqueChar);

    //? printf("size of CL: %i\n", sizeof(CL));
    //? printf("size of int: %i\n", sizeof(int));
    //? printf("size of char: %i\n", sizeof(char));

    printf("\n\n");

    return 0;
}

/**
 * This function verifies that no symbol is used twice in a row or column.
 * It prints an error message alerting the user which rows or columns have duplicate symbols
 * Test all rows first then test all columns.
 * Error messages have been included for you.
 *
 * @param n            :: the dimensions of the puzzle - all puzzles will be square (i.e. nxn)
 * @param latin_square :: the puzzle data structure
 * @return             :: 0 if the any row or column contains a duplicate symbol otherwise return 1
 */
int Verify_Rows_and_Columns(int n, char **latin_square) {
    if (latin_square == NULL) {
        printf("Verify_Rows_and_Columns - latin_square is NULL\n");
        return 0;
    }

    // printf("Error in row %d\n", row);
    // printf("Error in column %d\n", col);

    return 0;
}

/**
 * This function calls free to return all memory used by the latin_square puzzle
 * note you will have n+1 calls to free where n is the size of the puzzle.
 *
 * @param n            :: the dimensions of the puzzle - all puzzles will be square (i.e. nxn)
 * @param latin_square :: the puzzle data structure
 */
void Free_Memory(int n, char **latin_square) { return; }
