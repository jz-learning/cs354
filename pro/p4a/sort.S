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
// will be pointer to array after this function
	call	getArr@PLT


// write your code here 
	movl	%eax, -4(%ebp)


	movl	-4(%ebp), %eax

//  pushes %eax onto stack as parameter
    pushl   %eax
	call	printArr@PLT
    popl    %eax

// 	sets return value of main as 0, and pop off stack
    movl	$0, %eax
	popl	%ebp
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


			->	pointer to arr
%ebp		->	OS Stored Base Pointer
*/