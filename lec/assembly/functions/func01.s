	.file	"func01.c"
	.text
	.globl	sum
	.type	sum, @function
sum:
	endbr32
	pushl	%ebp			# push the base pointer to point at bot of main
	movl	%esp, %ebp
	subl	$16, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	ret
	.size	sum, .-sum
	.globl	main
	.type	main, @function
main:
	endbr32
	pushl	%ebp			# push base pointer
	movl	%esp, %ebp		# move stack pointer to base pointer
	subl	$16, %esp		# prepare space for return value
	pushl	$2				# pushing params onto stack
	pushl	$1
	call	sum				# call func
	addl	$8, %esp
	movl	%eax, -4(%ebp)
	movl	$0, %eax
	leave					# movl %ebp, %esp     ||    popl %ebp
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
