#include <stdio.h>

int main(void) {

	int a = 5, b = 2, c;
	int *ptr_1, *ptr_2;

	ptr_1 = &a;
	ptr_2 = &b;

	printf("%p, %p\n\n", ptr_1, ptr_2);

	c = *ptr_1 + *ptr_2;
	printf("Soma e igual a = %d", c);
	return 0;
}
