#include <stdio.h>

// function prototpye
// declaration
int sum(const int a, const int b);

int main() {
    // variable names
    // start with _ or letter
    // may include digits
    // case sensitive

    // char data type
    char ch = 'A';
    // char 1 byte
    // map a character to a binary representation
    // ASCII encoding
    printf("ch = %c\n", ch);
    printf("ch = %d\n", ch);
    printf("ch = %x\n", ch);
    // we can do math on char
    ch = ch + 1;
    printf("ch = %c\n", ch);
    printf("ch = %d\n", ch);
    printf("ch = %x\n", ch);

    // float and double
    float f = 1.2345678901234567890;
    double d = 1.2345678901234567890;
    printf("f = %20.16f\n", f);
    printf("d = %20.16f\n", d);

    // int
    int num = 14;        // 4 bytes typically
    short nshort = 3;    // 2 bytes typically
    long nlong = 12345;  // 8 bytes
    printf("num = %d\n", num);
    printf("nshort = %d\n", nshort);
    printf("nlong = %ld\n", nlong);

    // strings
    char course[] = "CS354";  // 'C' 'S' '3' '5' '4' '\0'
    printf("course = %s\n", course);

    // char vs string
    // char a[] = "A";  // 'A' '\0'
    // char b = 'B';    // 'B'

    // Operators
    // Arithmetic + - * / %
    // Relational < <= > >= == !=
    // Logical && || !
    // Assignment = += -= *= /= %=
    // Increment i++ ++i i-- --i
    // Bitwise & | ^ << >>

    // boolean
    // 0 is false
    // non 0 is true

    /////
    if (0)
        printf("0 is true\n");
    else
        printf("0 is false\n");

    /////
    if (1)
        printf("1 is true\n");
    else
        printf("1 is false\n");

    /////
    if (-31)
        printf("-31 is true\n");
    else
        printf("-31 is false\n");

    /////
    if ('a')
        printf("a is true\n");
    else
        printf("a is false\n");

    /////
    char x = 'x';
    if (x == 'a')
        printf("x == a is true\n");
    else
        printf("x == a is false\n");

    /////
    char y = 'y';
    if (y = 'a')
        printf("y = a is true\n");
    else
        printf("y = a is false\n");
    printf("y = %c\n", y);

    /* this is a comment  */
    // this line is a comment
    /*
      comment switch
    // */

    //*
    // short circuit
    char c = 'F';
    if (0 || (c = 'T'))
        printf("short circuit 0  true\n");
    else
        printf("short circuit 0  false\n");
    printf("c = %c\n", c);

    c = 'F';
    if (1 || (c = 'T'))
        printf("short circuit 1 true\n");
    else
        printf("short circuit 1 false\n");
    printf("c = %c\n", c);
    // */

    // loops
    printf("\nDo While Loop\n");
    int i = -3;
    do {
        printf("i = %d\n", i);
        i--;
    } while (i > 0);

    printf("\nWhile Loop\n");
    i = -3;
    while (i > 0) {
        printf("i = %d\n", i);
        i--;
    }

    printf("\nFor Loop\n");
    for (int i = 3; i > 0; i--) printf("i = %d\n", i);

    // for (decl stmt; stmt; post stmts)
    for (int i = 3, j = 12; i > 0; i--, j -= 3, printf("i=%d, j=%d\n", i, j))
        ;

    int s = sum(1, 2);
    printf("s = %d\n", s);

    return 0;
}

int sum(const int a, const int b) {
    int result = a + b;
    return result;
}
