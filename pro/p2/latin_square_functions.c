// James Zhang
// jzhang924
// JAMES ZHANG
// 9079769411
// 7/14/2021
// N/A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    // there are many approaches that will work to read in the puzzle data
    // you will need to do at least the following
    // 1) open the file
    // 2) read in the text from the file
    // 3) figure out the dimensions of the puzzle (n)
    //   3a) note the puzzle will always be square - we will not test any input that is not nxn.
    //   3b) we will only test with puzzles using valid symbols
    //   3c) a valid symbol has ascii code 33 to 126
    // 4) reserve memory for the latin_square with malloc. This requires 2 steps
    //   4a) reserve an array of pointers to the rows
    //   4b) reserve an array of characters for each row
    // 5) fill in the latin_square data structure
    // 6) close the file
    return;
}


/** 
 * This function checks to see that exactly n symbols are used and that each symbol is used exactly n times.
 * Valid symbols include charcters with ascii codes 33 to 126 (inclusive)
 * Google "man ascii" to pull up the table
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
void Free_Memory(int n, char **latin_square) {
    return;
}
