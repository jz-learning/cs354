int main() {
    int a[5];
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    a[3] = 40;
    a[4] = 50;

    return 0;
}

// To compile this 
// gcc -S array1.c -m32 -fno-asynchronous-unwind-tables -fno-pie -fno-stack-protector




//! Stack
-32  ::   
-28  ::
-24  ::
-20  :: 10  a[0]    // First element is at the lowest address
-16  :: 20  a[1]
-12  :: 30  a[2]
-8   :: 40  a[3]
-4   :: 50  a[4]
%ebp :: stored %ebp
return value
