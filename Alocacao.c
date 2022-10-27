#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Imprime(int *valores, int tam) {
	for(int i = 0; i<tam; i++)
		printf("%d ", valores[i]);

}

int main(void) {

	int **valores;
	int n = 0, tam;
	bool parada = true;

	valores = (int *) malloc(5*sizeof(int));
	
	tam = 5;
	
	do {
		printf("Informe valor: ");
		scanf("%d", &valores[n]);

		if (valores[n]==-1)
			parada = true;
		else n++;

	} while(parada && n<tam);
	
	Imprime(valores, tam);
	free(valores);
	Imprime(valores, tam);
	return 0;
}
