	.globl	main
	.type	main, @function
main:
// add a comment here
	pushl	%ebp
	movl	%esp, %ebp

// add a comment here - what is in %eax?
	call	getArr@PLT

// write your code here 

// add a comment here
    pushl   %eax
	call	printArr@PLT
    popl    %eax

// add a coment here
    movl	$0, %eax
	popl	%ebp
	ret
