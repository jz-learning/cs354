	.file	"struct1.c"
	.text
	.globl	main
	.type	main, @function
main:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp

	subl	$32, %esp			# reserve space in memory
	movl	$0, -24(%ebp)		# x
	movl	$0, -20(%ebp)		# y
	movb	$111, -16(%ebp)		
	movb	$114, -15(%ebp)
	movb	$105, -14(%ebp)
	movb	$103, -13(%ebp)
	movb	$105, -12(%ebp)
	movb	$110, -11(%ebp)
	movb	$0, -10(%ebp)
	movb	$42, -4(%ebp)
	movl	$0, %eax
	leave
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
