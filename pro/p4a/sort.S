	.globl	main
	.type	main, @function
main:
/*
int main() {
    // gets pointer to random array
    int* arr = getArr();

    int i = 0;
    goto outterCmpr;

	outterCode:;
		// code
		int j = 0;
		goto innerCmpr;
		

			function: ;
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;

			functionCmpr:
				if (arr[j] > arr[j + 1]) {
					goto function;
				}

				j++;
		innerCmpr:
			if (j < 19 - i) {
				goto functionCmpr;
			}
		
		i++;

	outterCmpr:
		if (i < 19) {
			goto outterCode;
		}

    printArr(arr);
    return 0;
}
*/

// Initializes function, startup code
	pushl	%ebp
	movl	%esp, %ebp

// %eax is empty right now, 
	call	getArr@PLT
// %eax now has address to array


// write your code here 
	subl	$16, %esp       			// Reserve space
	movl	$0, %edi					// initialize (i)
	movl	$0, %esi					// initialize (j)
	push 	%edi						// push (i) onto stack
	push	%esi						// push (j) onto stack
	movl	%eax, -4(%ebp)				// Stores array pointer in memory

	jmp		.OutterCmpr					// Goes to outter for loop


.OutterCode:
	movl	$0, %esi					// Sets (j) as 0 
	jmp		.InnerCmpr					// goes to inner for loop


.Swap:
	addl	-4(%ebp), %ecx				// address of arr[j + 1] -> %ecx
	movl	%eax, (%ecx)				// move arr[j] (%edx) into arr[j+1] (%ecx)

	subl	$4, %ecx					// get address of arr[j] from arr[j+1]
	movl	%edx, (%ecx)				// move arr[j] (%eax)  into arr[j+1] (%ecx)


.FunctionCmpr:
	leal	0(, %esi, 4), %ecx			// address of j * 4 -> %ecx
	movl	-4(%ebp), %eax				// adddress of arr  -> %eax
	addl	%ecx, %eax					// address of arr[j]
	movl 	(%eax), %eax				// gets value of arr[j]

	movl	%esi, %edx					// moves (j) to edx
	inc		%edx						// calculatets (j+1)

	leal	0(,%edx, 4), %ecx			// address of (j+1) * int -> %ecx
	movl	-4(%ebp), %edx				// address of arr      -> %edx
	addl	%ecx, %edx					// address of arr[j+1]
	movl 	(%edx), %edx				// gets value of arr[j+1]

	cmpl	%edx, %eax					// calculates arr[j] - arr[j+1]
	jg		.Swap						// goes to swapping if above is larger
	
	inc		%esi						// Increment (j)


.InnerCmpr:
	movl	$19, %eax					// moving 19 into eax
	subl	%edi, %eax					// computes (19 - i)
	cmpl	%eax, %esi					// compare if j < (19 - i) 
	jl		.FunctionCmpr					// moves onto inside if true
	
	inc		%edi						// increment (i)


.OutterCmpr:
	cmpl	$19, %edi					// Outter for loop comparason
	jl		.OutterCode					// Goto inner loop if ( i < 19)


.End:
	movl	-4(%ebp), %eax				// Move array to eax for return

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