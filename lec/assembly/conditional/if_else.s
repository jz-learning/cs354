	.file	"if_else.c"
	.text
	.globl	func
	.type	func, @function
func:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$1, -4(%ebp)
	movl	$2, -8(%ebp)
	movl	-4(%ebp), %eax
	cmpl	-8(%ebp), %eax
	jle	.L2
	movl	$0, -4(%ebp)
	jmp	.L4
.L2:
	movl	$0, -8(%ebp)
.L4:
	nop
	leave
	ret
	.size	func, .-func
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
