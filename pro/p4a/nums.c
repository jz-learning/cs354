#include <stdlib.h>
#include <stdio.h>

#define ARR_SIZE 20

int * getArr(){
    int b,c,d;
    b = 7;
    c = 90;
    d = 7919;

    int * a = malloc(sizeof(int)*50);
    int run = 1;
    for  (int i = 0; i < ARR_SIZE; ++i){
        run = run * b + c;
        run = run % d;
        a[i] = run;
    }

    return a;
}

void printArr(int * arr) {
    for  (int i = 0; i < ARR_SIZE; ++i){
        printf("%d\n",arr[i]);
    }
    return;
}

