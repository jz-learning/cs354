#include <stdio.h>

int main() {
    // for loop
    for (int i = 0; i < 19; i++) {
        printf("%i, ", i);
    }

    printf("\n");

    // other way
    int i = 0;

top:
    if (i < 19) {
        printf("%i, ", i);
        i++;
        goto top;
    }

	printf("\n");
}