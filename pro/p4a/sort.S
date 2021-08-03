	.globl	main
	.type	main, @function
main:
/*
// Runs n times
for (int i = 0; i < ARR_SIZE - 1; i++) {
	// each run, bubble everything from the begining
	for (int j = 0; j < ARR_SIZE - i - 1; j++) {
		// if larger, then swap
		if (arr[j] > arr[j + 1]) {
			int temp = arr[j + 1];
			arr[j + 1] = arr[j];
			arr[j] = temp;
		}
*/
// Initializes function, startup code
	pushl	%ebp
	movl	%esp, %ebp

// add a comment here - what is in %eax?
	call	getArr@PLT
    pushl   %eax
	call	printArr@PLT

// write your code here 

// add a comment here
    pushl   %eax
	call	printArr@PLT
    popl    %eax

// add a coment here
    movl	$0, %eax
	popl	%ebp
	ret
