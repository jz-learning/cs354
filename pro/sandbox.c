#include <stdio.h>

char at(char *arr, int idx);

int main() {
    int arr[5] = {2, 4, 6, 8, 10};

    // printf("%c\n", at(arr, 1));

    // char a = 0;
    // if (a = 'c')
    //     printf("true\n");
    // else
    //     printf("false\n");

    for (int i = 0; i < 5; i++) {
        printf("%i\n", arr[i]);
        printf("Address of arr: %p\n", &arr[i]);
    }
    printf("=============\n");
    for (int i = 0; i < 5; i++) {
        printf("%i \n", *(arr + i));
        printf("Address of arr: %p\n", arr);
        printf("Address of arr: %p\n", &*(arr + i));
    }
}

char at(char *arr, int idx) { return *(arr + idx * sizeof(char)); }
