.section .data
.section .text
.globl countOnes

countOnes:
// write a C version of your code to return the number of ones in the bit representation of the 
// integer parameter as a comment

##### C Version #####
/*
int countOnes(int n) {
    int sum = 0;
    while (n) {
        if (n & 1) sum++;
        n = n >> 1;
    }
    return sum;
*/

// translate your C code to assembly
// comment every line
// do not use assemblier directives (e.g. .cfi_something)
    pushl   %ebp            // Create return address on stack
    movl    %esp, %ebp      // Move stack pointer up
	subl	$16, %esp       // Reserve space

    movl    $0, %eax        // Set (sum) as 0
    movl    %eax, -4(%ebp)  // put variable (sum) in memory

    jmp     .Compare         // Checks if n > 0

.Loop:
    movl    8(%ebp), %edx   // move (n) to a register
    andl    $1, %edx        // compares 1 against last digit of (n), store in %edx
    jz      .Shift          // skip increment if not 0
    movl    -4(%ebp), %edx  // move sum to register
    inc     %edx            // increment sum if last digit is 1
    movl    %edx, -4(%ebp)  // move sum back into (sum)

.Shift:
    shrl    $1, 8(%ebp)     // shift (n) to right by 1

.Compare:
    movl    8(%ebp), %eax   // move (n) to register
    testl   %eax, %eax      // Checks if (n) is 0
    jnz     .Loop           // jumps to loop if not 0 
    movl    -4(%ebp), %eax  // prepare to return sum
    popl    %ebp            // clean up stack
    ret                     // return to caller


####### stack #######          
// %esp        ->
//             ->
//             ->
// 			   ->   2 (sum)
// %ebp		   ->	base pointer   
//             ->   return address
//             ->   0 (n)
