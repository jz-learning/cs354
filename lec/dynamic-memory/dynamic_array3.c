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

    // double the size of the array 
    // THIS IS THE BAD WAY!!!
    // 1) We lose access to the original a - so we can't copy the old data
    // 2) We lose access to the original a - so we can't free the memory
    //  a = malloc(2 * num * sizeof(int));
    //  if (a == NULL) {
    //      fprintf(stderr, "Memory allocation failed.\n");
    //      exit(1);
    //  }

    int *p = malloc(2 * num * sizeof(int));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i< num; i++) 
        p[i] = a[i];
    
    free(a);
    a = p;

    for (int i = 0; i < 2*num; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    free(a);

    return 0;
}
