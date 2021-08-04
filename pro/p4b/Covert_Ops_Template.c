#include <stdio.h>
#define N 4

int Is_Number_Correct(int a, int b, int i) {
    if (a == b) {
        printf("Number %d: Correct. Nice Job.\n", i);
        return 1;
    }
    printf("Number %d: Incorrect\n", i);
    return 0;
}

// write f0 here
// answer 5589516
int f0() { return 5589516; }

// write f1 here
// answer 26
int f1() {
    int arr[6] = {25027, 51330, 67548, 30404, 49, 17};
    int x = arr[1];
    int y = arr[2];

    if (arr[0] > (x + y)) {
        arr[0] = arr[0] >> 4;
        printf("Doesn't Run\n");
    }

    x = arr[1] * arr[0];

    if (arr[3] < x) return arr[2] % arr[4];
    return arr[3] % arr[5];
}

// write f2 here
// answer 7042
int f2(int n) {
    int x = 0;
    int y = 0;
    while (x < 28) {
        y += (x * x) + n;
        x++;
    }
    return y;
}

// write f3_helper here
void f3_Help(int *p) { *p = 3 + *p; }

// write f3 here
void f3(int x, int *px) {
    printf("%i\n", *px);
    f3_Help(px);
    printf("%i\n", *px);
    f3_Help(px);
    printf("%i\n", *px);
    // int *y = &x;
    // px = px << 3;
    // &x = px + y;
}

int main() {
    int i;
    int n[N];
    int a[N];
    int c = 0;

    // get numbers from user
    printf("Enter four numbers: ");
    for (i = 0; i < N; i++) scanf("%d", &n[i]);
    printf("\nYou have entered: %d, %d, %d, %d\n", n[0], n[1], n[2], n[3]);

    // get answers
    a[0] = f0();
    a[1] = f1();
    a[2] = f2(i);
    a[3] = 4046;
    f3(a[3], &a[3]);

    // print answers
    for (i = 0; i < N; i++) printf("answers #%d = %d\n", i, a[i]);

    // test
    c += Is_Number_Correct(n[0], a[0], 0);
    c += Is_Number_Correct(n[1], a[1], 1);
    c += Is_Number_Correct(n[2], a[2], 2);
    c += Is_Number_Correct(n[3], a[3], 3);

    // report results
    if (c == 0) printf("You didn't get any correct numbers. Please try again.\n");
    if (c > 0 && c < N) printf("You got %d correct numbers.  Please try again.\n", c);
    if (c == N) printf("All numbers are correct! Nice work!\n");

    return 0;
}
