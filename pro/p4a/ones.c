#include <stdio.h>

extern int countOnes(int n);

//! C Implementation
// int countOnes(int n) {
//     int sum = 0;
//     while (n) {
//         if (n & 1) sum++;
//         n = n >> 1;
//     }
//     return sum;
// }

int main() {
    unsigned int a;

    // 0000 0000 0000 0000
    a = countOnes(0);  // answer 0
    printf("%d\n", a);

    // 0000 0000 0000 0001
    a = countOnes(1);  // answer 1
    printf("%d\n", a);

    // 0000 0000 0000 0010
    a = countOnes(2);  // answer 1
    printf("%d\n", a);

    // 0000 0000 0000 0011
    a = countOnes(3);  // answer 2
    printf("%d\n", a);

    // 0000 0000 0000 1111
    a = countOnes(15);  // answer 4
    printf("%d\n", a);

    // 0000 0000 0001 0000
    a = countOnes(16);  // answer 1
    printf("%d\n", a);

    // 1111 1111 1111 1111
    a = countOnes(0xFFFF);  // answer 16
    printf("%d\n", a);

    // write your own test such that the answer is 31
}
