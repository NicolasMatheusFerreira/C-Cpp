#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int *p, x = 10;
	p = &x;

	printf("Conteudo que o apontado pelo ponteiro = %d\n", *p);
	printf("Endereco de memoria da variavel apontada pelo ponteiro = %p\n", p);
	printf("Endereco de memoria da variavel que armazena o valor 10 = %p\n\n", &x);

	printf("Endereco de memoria do apontador %p\n", &p);
	return 0;
}
