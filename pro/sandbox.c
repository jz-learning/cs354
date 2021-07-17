#include <stdio.h>

char at(char *arr, int idx);

int main() {
    char arr[6] = "hello";

    printf("%c\n", at(arr, 1));

    char a = 0;
    if (a = 'c')
        printf("true\n");
    else
        printf("false\n");
}

char at(char *arr, int idx) { return *(arr + idx * sizeof(char)); }
