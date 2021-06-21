#include <stdio.h>

int main(){

	printf("size of int is %d\n",sizeof(int));

	int arr[4] = {10, 20, 30, 40};
	arr[0] = 15;

	for (int i = 0; i < 4; i++) {
		printf("arr[%d] = %d at address %p\n", i, arr[i], &arr[i]);
	}

	return 0;
}

