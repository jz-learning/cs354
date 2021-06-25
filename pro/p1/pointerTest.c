/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

#define USER_NAME_LENGTH 256
#define EMAIL_LENGTH 512
#define PASSWORD_LENGTH 256

int main(void) {
    // int a = 5;
    // int *pa = &a;

    // printf("a is:\t %d\n", a);
    // printf("pa is:\t %p\n", pa);

    // printf("\n");

    // char c = 'a';
    // char *pc = &c;
    // int *ppc = &c;

    // pc++;
    // *pc = 1;

    // printf("c is:\t\t %c\n", c);
    // printf("pc is:\t\t %p\n", pc);
    // printf("ppc is:\t\t %p\n", ppc);
    // printf("*pc is:\t\t %d\n", *pc);
    // printf("*ppc is:\t %i\n", *ppc);

    char arr[] = "jameszhang@gmail.com";
    printf("String is: %s\n", arr);
    
    // at the end of the string is a '\0'. Just had to make sure
    printf("at %p, arr: %d, char: %c\n", arr+20, *(arr+20), *(arr+20));

    int length = 0;
    char *s = arr;
    while (*s) {
        printf("(%c, %d) at:\t x%p\n", *s, *s, s);
        s++;
        length++;
    }
    printf("Email length: %i\n", length);

}