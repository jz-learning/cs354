#include <stdio.h>

char at(char *arr, int idx);

int Pad_Size(int x) {
    int mod;
    if ((mod = x % 4)) {
        x += (4 - mod);
    }
    return x;
}

int main() {
    int arr[5] = {2, 4, 6, 8, 10};

    // printf("%c\n", at(arr, 1));

    // char a = 0;
    // if (a = 'c')
    //     printf("true\n");
    // else
    //     printf("false\n");

    // for (int i = 0; i < 5; i++) {
    //     printf("%i\n", arr[i]);
    //     printf("Address of arr: %p\n", &arr[i]);
    // }
    // printf("=============\n");
    // for (int i = 0; i < 5; i++) {
    //     printf("%i \n", *(arr + i));
    //     printf("Address of arr: %p\n", arr);
    //     printf("Address of arr: %p\n", &*(arr + i));
    // }

    // op = 0000 0000 0010
    // xx = 0000 0000 0001

    /*
        int op = 0x02;
        int xx = 0x1;
        op = op & xx;
        printf("%x\n", op);
    */

    int x = 9;
    printf("Original: %i \nAfter: %i\n", x, Pad_Size(x));
}

char at(char *arr, int idx) { return *(arr + idx * sizeof(char)); }
