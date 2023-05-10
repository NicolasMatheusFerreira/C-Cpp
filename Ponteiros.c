#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int a = 5; // A variável 'a' guarda o valor 5
	int *b = &a; // A variável 'b' guarda o endereço de memória da variável a

	printf("Endereco de memoria da variavel 'a' = %p\n", &a); 
	printf("Endereco de memoria da variavel 'b' = %p\n", &b);

	printf("Conteudo guardado na variavel 'a', apontado pela variavel 'b' = %d\n", *b);
	printf("Endereco da variavel 'a' a partir do conteudo guardado de 'b' = %p", b);
	return 0;
}
