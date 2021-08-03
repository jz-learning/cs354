	.globl	main
	.type	main, @function
main:
/*
// Runs n times
for (int i = 0; i < ARR_SIZE - 1; i++) {

	// each run, bubble everything from the begining
	for (int j = 0; j < ARR_SIZE - i - 1; j++) {

		// if larger, then swap
		if (arr[j] > arr[j + 1]) {

			int temp = arr[j + 1];
			arr[j + 1] = arr[j];
			arr[j] = temp;
		}
*/

// Initializes function, startup code
	pushl	%ebp
	movl	%esp, %ebp

// %eax is empty right now, 
	call	getArr@PLT
// %eax now has address to array

// write your code here 
	subl	$16, %esp       	// Reserve space
	movl	$0, %edi			// initialize (i)
	movl	$0, %esi			// initialize (j)
	push 	%edi				// push (i) onto stack
	push	%esi				// push (j) onto stack
	movl	%eax, -4(%ebp)		// Stores array pointer in memory

	jmp		.OutterCmpr			// Goes to outter for loop

.OutterCode:
	movl	$0, %esi			// Sets (j) as 0 
	jmp		.InnerCmpr			// goes to inner for loop






.InnerCmpr:
	movl	$19, %eax			// moving 19 into eax
	subl	%edi, %eax			// computes (19 - i)
	cmpl	%eax, %esi			// compare if j < (19 - i) 
	jl		.InnerCode			// moves onto inside if true
	inc		%edi				// else, increment (i)


.OutterCmpr:
	cmpl	$19, %edi			// Outter for loop comparason
	jl		.OutterCode			// Goto inner loop if ( i < 19)


.End:
	movl	-4(%ebp), %eax		// Move array to eax for return
//  pushes %eax onto stack as parameter
    pushl   %eax
	call	printArr@PLT
    popl    %eax

// Restore registers
	pop		%edi
	pop		%esi

// 	sets return value of main as 0, and pop off stack
    movl	$0, %eax
	leave
	ret


/*
####### somewhere #######
			->	97
			->	769
			->	5473
			->	6725
			->	7570
			->	5566
			->	7376
			->	4208
			->	5789
			->	1018
			->	7216
			->	3088
			->	5868
			->	1571
			->	3168
			->	6428
			->	5491
			->	6851
			->	533
			->	3821

####### stack #######

%esp		->	0 %esi	(f)
			->	0 %edi  (i)
			->
			->	
			->	
			->	pointer to arr
%ebp		->	OS Stored Base Pointer
*/