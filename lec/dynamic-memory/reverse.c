#include <stdio.h>
void print_array(int *a);
int *reverse(int a[]);

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    print_array(a);

    int *p = reverse(a);
    print_array(p);
}

void print_array(int *a) {
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int *reverse(int a[]) {
    int b[5];
    for (int i = 0; i < 5; i++) {
        b[i] = a[5 - i];
    }
    return b;
}