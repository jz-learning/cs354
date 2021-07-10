#include <stdio.h>
#include <stdlib.h>

void print_array(int *a);
int *reverse(int a[]);

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    print_array(a);

    int *p = reverse(a);
    print_array(p);
    free(p);
}

void print_array(int *a) {
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// ! won't work because after this function ends,
// all variables are thrown away
// int *reverse(int a[]) {
//     int b[5];

// ? OLD WAY
//     // for (int i = 0; i < 5; i++) {
//     //     b[i] = a[5 - i];
//     // }

// ? BETTER WAY
//     int i = 0, j = 4;
//     while (i < 5) {
//         b[i++] = a[j--];
//     }

//     return b;
// }

// ! How to use the HEAP
int *reverse(int a[]) {
    // reserving space in heap for the local array
    int *b = malloc(5 * sizeof(int));

    int i = 0, j = 4;
    while (i < 5) {
        b[i++] = a[j--];
    }
    return b;
}