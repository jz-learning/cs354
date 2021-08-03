	.file	"factorial.c"
	.text
	.globl	factorial
	.type	factorial, @function
factorial:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$1, -4(%ebp)
	jmp	.L2
.L3:
	movl	-4(%ebp), %eax
	imull	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	subl	$1, 8(%ebp)
.L2:
	cmpl	$1, 8(%ebp)
	jg	.L3
	movl	-4(%ebp), %eax
	leave
	ret
	.size	factorial, .-factorial
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
