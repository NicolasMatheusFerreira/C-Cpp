#include <stdio.h>
#include <stdlib.h>

int Soma(int *vlrA, int *vlrB) {
	return (*vlrA)+(*vlrB);
}

int main(void) {

	// Cria um array de 50 inteiros (200 bytes)
	int *v = malloc(200);
	// Cria um array de 200 chars (200 bytes)
	char *x = malloc(200);

	int a = 5, b = 2;
	printf("%d", Soma(&a, &b));
	return 0;
}
