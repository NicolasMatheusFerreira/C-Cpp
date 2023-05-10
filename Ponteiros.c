#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int a = 5; // A vari�vel 'a' guarda o valor 5
	int *b = &a; // A vari�vel 'b' guarda o endere�o de mem�ria da vari�vel a

	printf("Endereco de memoria da variavel 'a' = %p\n", &a); 
	printf("Endereco de memoria da variavel 'b' = %p\n", &b);

	printf("Conteudo guardado na variavel 'a', apontado pela variavel 'b' = %d\n", *b);
	printf("Endereco da variavel 'a' a partir do conteudo guardado de 'b' = %p", b);
	return 0;
}
