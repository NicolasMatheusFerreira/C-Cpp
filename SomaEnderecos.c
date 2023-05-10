#include <stdio.h>
#include <stdlib.h>

void soma(int* ptr1, int* ptr2) {

	printf("0x%p -> %d\n", (ptr1), (*ptr1));
	printf("0x%p -> %d\n", (ptr2), (*ptr2));

	printf("\nSoma de 1 no endereco de memoria da variavel apontada.\n");
	printf("0x%p\n", (ptr1)+1);
	printf("0x%p\n", (ptr2)+1);

	printf("\nSoma de 1 no valor do endereco da variavel apontada.\n");
	printf("%d\n", (*ptr1)+1);
	printf("%d\n", (*ptr2)+1);

}

int main(void) {

	int a = 5;
	int b = 3;

	printf("a = 0x%p -> %d\n", &a, a);
	printf("b = 0x%p -> %d\n\n", &b, b);

	soma(&a, &b);
	return 0;
}
