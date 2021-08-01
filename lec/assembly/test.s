	movl 	$1, %eax
	movl	$2, %ebx

	cmpl 	%ebx, %eax
	jle 	DONT

DO:
	addl 	$1, %eax
	jmp END
DONT:
	movl	%eax, %ebx
END: