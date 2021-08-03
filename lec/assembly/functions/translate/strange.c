int strange(int *a, int b) {
    int c = (*a) * b;
    *a = (*a) + b;
    return c;
}

int main() {
    int a = 3;
    int b = 4;
    int z = strange(&a, b);
    return 0;
}

%esp		->
			->
			->
			->	3 * 4 = 12 (c)
%ebp		->	Stores base pointer
			-> 	return address
			->	address of (a)
			->	4 (a)
			->
			->	3 (b)
			->	  (z)
			->	4 (a)
			->	OS Stored Base Pointer