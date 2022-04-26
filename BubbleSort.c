#include <stdio.h>


int main(int argc, char* argv[]) {
	double numeros[10];

	for(int i = 0; i<sizeof(numeros)/sizeof(double); i++) { // Entrada de valores
		printf("Informe um valor: ");
		scanf("%lf", &numeros[i]);			
	}

	double aux=0; // Ordenação por método da bolha
	for(int i=0; i<sizeof(numeros)/sizeof(double); i++) {
		for(int j=0; j<sizeof(numeros)/sizeof(double)-1; j++) {
			if (numeros[j]>numeros[j+1]) {
				aux = numeros[j];
				numeros[j] = numeros[j+1];
				numeros[j+1] = aux;
			}
		}
	}

	int cont = 0; // Saída de valores
	while(cont!=sizeof(numeros)/sizeof(double)) {
		printf(" %.lf", numeros[cont]);
		cont = cont + 1;
	}
	printf("\n");
}

