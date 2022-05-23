#include <stdio.h>
#include <stdlib.h>

// Ponteiros e arranjos

int main(void) {

	int z = 10;
	int *p;

//	printf("%d\n", *p);

			// malloc serve para alocar memória ao computador, durante a execução do programa. E ao alocar devolve (retorna) um endereço de memória com o espaço reservado pelo malloc.
	
	p = (int *) malloc(1*sizeof(int));

	if (p==NULL)
		printf("\aMemoria insuficiente.\n");
	else {
		p[0] = 1;
		p[1] = 2;
		p[2] = 3;
		p[3] = 4;
		p[4] = 5;
	}

	for(int i = 0; i<5; i++)
		printf("%d\n", p[i]);

	free(p);
//	printf("Tamanho em bytes ocupado pelo ponteiro p: %ld\n", sizeof(*p));
	
	return 0;
}
