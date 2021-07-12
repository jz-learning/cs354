// Do not turn this file in.
// Do all of your work in 
// latin_square_functions.c!!!
// make sure your functions 
// work with the original 
// latin_square_main.c file!


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// you will write definitions for these functions in latin_square_functions.c
extern void Read_Latin_Square_File(char *filename, char ***latin_square, int *n);
extern int Verify_Alphabet(int n, char **latin_square);
extern int Verify_Rows_and_Columns(int n, char **latin_square);
extern void Free_Memory(int n, char **latin_square);


// use this function to verify that you have correctly read the latin square puzle
void Print_Latin_Square(int n, char **latin_square) {
    if (latin_square == NULL) {
        printf("Print_Square - latin_square is NULL\n"); 
        return;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) 
            printf("%c",latin_square[i][j]); 
        printf("\n");
    }
}

int main(int argc, char *argv[] ) {
  // Verify command line parameters
    if(argc != 2){
        printf("expected usage: %s <file_name>", argv[0]); 
        exit(1);
    }

    /* Declare variables
     * n ::  the dimensions of the square 
     * latin_square :: represents the puzzle.  This variable is a pointer to a pointer.  
     * You can think of it as an array that contains pointers to arrays of characters for each row.
     */
    int n=0;
    char **latin_square = NULL;
    int alphabet_valid, rows_cols_valid;

    // Read the Latin Square file
    Read_Latin_Square_File(argv[1], &latin_square, &n);
    
    // Print the Latin Square;
    Print_Latin_Square(n, latin_square);

    // Verify Alphabet
    if ((alphabet_valid = Verify_Alphabet(n, latin_square))) 
        printf("Alphabet is Valid\n"); 
    else printf("Alphabet is Invalid\n");

    // Verify each letter used once per row and column
    if ((rows_cols_valid = Verify_Rows_and_Columns(n, latin_square))) 
        printf("Rows and Columns do not contain duplicate entries\n"); 
    else printf("Rows and Columns contain duplicate entries\n");

    if (alphabet_valid && rows_cols_valid) 
        printf("Latin Square is valid\n");
    else printf("Latin Square is invalid\n");

    // Free memory
    Free_Memory(n, latin_square);
    
    return 0;
}
