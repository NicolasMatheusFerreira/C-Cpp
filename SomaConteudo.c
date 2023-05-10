#include <stdio.h>
#include <stdlib.h>

int soma(int* ptr1, int* ptr2) {
	return (*ptr1)+(*ptr2);
}

int main(void) {

	int a = 5;
	int b = 3;

	printf("%d", soma(&a, &b));
	return 0;
}
