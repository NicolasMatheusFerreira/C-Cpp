#include <stdio.h>

float Potencia(float a, int b) {
	
	int cont = 1;
	float resultado = 1;
	while(cont<=b) {
		resultado = resultado*a;
		cont = cont + 1;
	}
	return resultado;
}

int main(int argc, char *argv[]) {

	float base;
	int expo;

	printf("Informe base: ");
	scanf("%f", &base);

	printf("Informe expoente: ");
	scanf("%d", &expo);

	printf("O resultado da potencia de %.2f elevado a %d e igual a %.2f\n\n", base, expo, Potencia(base, expo));
	return 0;
}
