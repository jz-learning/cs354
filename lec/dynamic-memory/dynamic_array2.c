#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <num_elems>\n", argv[0]);
        exit(1);
    }

    int num = atoi(argv[1]);
    printf("num = %d\n", num);

    // create a dynamic array on the heap
    int *a = malloc(num * sizeof(int));

    // malloc might fail if there's not enough storage on heap,
    // double checking to make sure allocation succeeds
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < num; ++i) {
        a[i] = i;
    }

    for (int i = 0; i < num; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    printf("\n\n");

    // TODO: Need to double the size of the array
    // Initialize new array with 2 x size
    int *p = malloc(2 * num * sizeof(int));

    // malloc might fail if there's not enough storage on heap,
    // double checking to make sure allocation succeeds
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    // ! set all to 0
    for (int i = 0; i < 2 * num; ++i) {
        p[i] = 0;
    }

    // ! copy old array
    int i = 0;
    while (i < num) {
        p[i] = a[i];
        i++;
    }
    free(a);

    a = p;
    for (int i = 0; i < 2 * num; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    // a or p both work here
    // ! doing both is bad
    //free(a);
    free(p);

    return 0;
}
