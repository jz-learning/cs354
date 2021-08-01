//? C Code
int a = 1, b = 2;
if (a >= b) {
    stmts;
}

//! Assembly
movl	$1, %eax
movl 	$2, %ebx
cmpl	%ebx, %eax

