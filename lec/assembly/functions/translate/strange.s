	.file	"strange.c"
	.text
	.globl	strange
	.type	strange, @function
strange:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	imull	%edx, %eax
	movl	%eax, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	addl	%eax, %edx			// 3 + 4, edx=7
	movl	8(%ebp), %eax		
	movl	%edx, (%eax)		// *b = 7 
	movl	-4(%ebp), %eax
	leave
	ret
	.size	strange, .-strange
	.globl	main
	.type	main, @function
main:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$3, -12(%ebp)
	movl	$4, -4(%ebp)
	pushl	-4(%ebp)
	leal	-12(%ebp), %eax
	pushl	%eax
	call	strange
	addl	$8, %esp
	movl	%eax, -8(%ebp)
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-10ubuntu2) 9.3.0"
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
