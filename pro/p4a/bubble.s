	.file	"bubble.c"
	.text
	.globl	getArr
	.type	getArr, @function
getArr:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$7, -20(%ebp)
	movl	$90, -24(%ebp)
	movl	$7919, -28(%ebp)
	subl	$12, %esp
	pushl	$200
	call	malloc
	addl	$16, %esp
	movl	%eax, -32(%ebp)
	movl	$1, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	.L2
.L3:
	movl	-12(%ebp), %eax
	imull	-20(%ebp), %eax
	movl	%eax, %edx
	movl	-24(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	cltd
	idivl	-28(%ebp)
	movl	%edx, -12(%ebp)
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%edx)
	addl	$1, -16(%ebp)
.L2:
	cmpl	$19, -16(%ebp)
	jle	.L3
	movl	-32(%ebp), %eax
	leave
	ret
	.size	getArr, .-getArr
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	printArr
	.type	printArr, @function
printArr:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$0, -12(%ebp)
	jmp	.L6
.L7:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	addl	$1, -12(%ebp)
.L6:
	cmpl	$19, -12(%ebp)
	jle	.L7
	nop
	leave
	ret
	.size	printArr, .-printArr
	.globl	main
	.type	main, @function
main:
	endbr32
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$20, %esp
	call	getArr
	movl	%eax, -20(%ebp)
	movl	$0, -12(%ebp)
	jmp	.L10
.L14:
	movl	$0, -16(%ebp)
	jmp	.L11
.L13:
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-16(%ebp), %eax
	addl	$1, %eax
	leal	0(,%eax,4), %ecx
	movl	-20(%ebp), %eax
	addl	%ecx, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jle	.L12
	movl	-16(%ebp), %eax
	addl	$1, %eax
	leal	0(,%eax,4), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -24(%ebp)
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movl	-16(%ebp), %edx
	addl	$1, %edx
	leal	0(,%edx,4), %ecx
	movl	-20(%ebp), %edx
	addl	%ecx, %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-20(%ebp), %eax
	addl	%eax, %edx
	movl	-24(%ebp), %eax
	movl	%eax, (%edx)
.L12:
	addl	$1, -16(%ebp)
.L11:
	movl	$19, %eax
	subl	-12(%ebp), %eax
	cmpl	%eax, -16(%ebp)
	jl	.L13
	addl	$1, -12(%ebp)
.L10:
	cmpl	$18, -12(%ebp)
	jle	.L14
	subl	$12, %esp
	pushl	-20(%ebp)
	call	printArr
	addl	$16, %esp
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	leave
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 4
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 4
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 4
4:
