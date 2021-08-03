/*
setup
prologue
function body
epilogue
cleanup
*/


increment:
	# Prologue
	pushl	%ebp
	movl	%esp, %ebp

	# Body
	// Goes to where f address is stored
	movl	8(%ebp), %eax	
	movl	(%eax), %eax	// gets content of address

	inc		%eax
	movl	8(%ebp), %edx
	movl	%eax, (%edx)

	# Epilogue
	popl	%ebp
	ret



main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$10, -4(%ebp)

	# Function call
	# set up
	leal	-4(%ebp), %eax
	pushl	%eax

	# function
	call	increment		// Stores ret address
	add 	$4, %esp
	leave
	ret



########## Memory ##########
// Main
%esp		->
			->
			->
			->	10 (f)
%ebp		->	OS Stored Base Pointer


// Setup
%esp		->	Adderess of (f)
			->
			->
			->
			->	10 (f)
%ebp		->	OS Stored Base Pointer

// Function call
%ebp/%esp	->	Stores base pointer
			-> 	return address 
			->	Adderess of (f)
			->
			->
			->
			->	10 (f)
			->	OS Stored Base Pointer

// epilogue
			->	Adderess of (f)
			->
			->
			->
			->	11 (f)
%ebp		->	OS Stored Base Pointer
