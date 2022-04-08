#include <stdio.h>

int main(void) {

					// Tamanho em que cada (tipo de variável) ocupa na memória do computador
	printf("Inteiro = %ld\n", sizeof(int)); 
	printf("Real = %ld\n", sizeof(float));
	printf("Real duplo = %ld\n", sizeof(double));
	printf("Caractere = %ld\n", sizeof(char));

	struct {
		int azul, vermelho;
		int quentes[5];
	} typedef Cores;

	printf("Tamanho em Bytes de Cores = %ld Bytes, igual a %ld bits.\n", sizeof(Cores), sizeof(Cores)*8);

	int u = 1234, y = 2345;
	printf("u = %d\n", u);
	printf("&u = %ld\n", (long int) &u);
	printf("&u = %p\n", (void *) &u);
	printf("&y = %p\n", (void *) &y);
	return 0;
}
