#include <stdio.h>

extern int countOnes(int n);

int main(){
    unsigned int a;

    a=countOnes(0); // answer 0
    printf("%d\n", a);

    a=countOnes(1); // answer 1
    printf("%d\n", a);

    a=countOnes(2); // answer 1
    printf("%d\n", a);

    a=countOnes(3); // answer 2
    printf("%d\n", a);

    a=countOnes(15); // answer 4
    printf("%d\n", a);

    a=countOnes(16); // answer 1
    printf("%d\n", a);

    a=countOnes(0xFFFF); // answer 16
    printf("%d\n", a);

    // write your own test such that the answer is 31

}
