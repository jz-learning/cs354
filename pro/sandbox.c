#include <stdio.h>

char at(char *arr, int idx);

int main() {
    char arr[6] = "hello";

    printf("%c\n", at(arr, 1));
}

char at(char *arr, int idx) {
    return *(arr + idx * sizeof(char));
}