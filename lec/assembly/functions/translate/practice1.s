/*
setup
prologue
function body
epilogue
cleanup
*/



increment:
	# PROLOGUE
	pushl 	%ebp
	movl	%esp, %ebp
	
	# BODY
	movl	8(%ebp), %eax
	inc		%eax
	
	# EPILOGUE
	popl	%ebp
	ret


main:
	pushl 	%ebp
	movl	%esp, %ebp
	subl 	$4, %esp		// Move stack pointer up
	movl	$10, %-4(ebp)	// Move 10 into stack

	# Function Call
	# SETUP
	pushl 	-4(%ebp)		// set (f)
	call	increment

	# CLEAN UP
	addl	$4, %esp		// clear stack
	movl	%eax, -4(%ebp)	// set (f) as return val
	movl 	$0, %eax
	leave
	ret



########## Memory ##########
// At Function (Epilogue)
%esp/%esp	->	store main's base pointer
			->	return address
			->  10 (param)
			->	10 (f)
			->	OS Stored Base Pointer


// Cleanup
%esp		->  10 (param)
			->	10 (f)
%ebp		->	OS Stored Base Pointer