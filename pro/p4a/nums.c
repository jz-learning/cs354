#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 20

int* getArr() {
    int b, c, d;
    b = 7;
    c = 90;
    d = 7919;

    int* a = malloc(sizeof(int) * 50);
    int run = 1;
    for (int i = 0; i < ARR_SIZE; ++i) {
        run = run * b + c;
        run = run % d;
        a[i] = run;
    }

    return a;
}

void printArr(int* arr) {
    for (int i = 0; i < ARR_SIZE; ++i) {
        printf("%d\n", arr[i]);
    }
    return;
}

int main() {
    // gets pointer to random array
    int* arr = getArr();

    // // Runs n times
    // for (int i = 0; i < ARR_SIZE - 1; i++) {
    //     // each run, bubble everything from the begining
    //     for (int j = 0; j < ARR_SIZE - i - 1; j++) {
    //         // if larger, then swap
    //         if (arr[j] > arr[j + 1]) {
    //             int temp = arr[j + 1];
    //             arr[j + 1] = arr[j];
    //             arr[j] = temp;
    //         }
    //     }
    // }

    int i = 0;
    goto outterCmpr;

outterCode:;
    // code
    int j = 0;
    goto innerCmpr;
    {
    innerCode:
        // code
        goto functionCmpr;

        function: ;
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;

            

        functionCmpr:
            if (arr[j] > arr[j + 1]) {
                goto function;
            }

            j++;
    innerCmpr:
        if (j < 19 - i) {
            goto innerCode;
        }
    }
    i++;
    
outterCmpr:
    if (i < 19) {
        goto outterCode;
    }

    printArr(arr);
    return 0;

    // middle:
    //     if (i < 19) {
    //         int j = 0;
    //     inner:
    //         if (j < 19 - i) {
    //             if (arr[j] > arr[j + 1]) {
    //                 int temp = arr[j + 1];
    //                 arr[j + 1] = arr[j];
    //                 arr[j] = temp;
    //             }
    //             j++;
    //             goto inner;
    //         }
    //         i++;
    //         goto middle;
    //     }
}
