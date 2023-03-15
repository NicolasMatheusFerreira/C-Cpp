#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Imprime(int *valores, int tam) {
	for(int i = 0; i<tam; i++)
		printf("%d ", valores[i]);
}

int main(void) {

	int *valores;
	int n = 0, tam;
	bool parada = true;

	valores = (int *) malloc(5*sizeof(int));
	
	tam = 5;
	
	do {
		printf("Informe valor: ");
		scanf("%d", &valores[n]);
	
		printf("%d\n", valores[n]);
		if (valores[n]==-1)
			parada = false;
		else n++;
			
	} while(parada==true && n<tam);
	
	printf("Imprimindo valores: ");
	Imprime(valores, tam);
	printf("\n\n");
	printf("Liberacao de memoria. \n");
	printf("Imprimindo valores: ");
	free(valores);
	Imprime(valores, tam);
	return 0;
}
