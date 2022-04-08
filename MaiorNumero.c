#include <stdio.h>

int main(int argc, char *argv[]) {

	float valor_1, valor_2;

	printf("I. Informe o primeiro valor: ");
	scanf("%f", &valor_1);

	printf("II. Informe o segundo valor: ");
	scanf("%f", &valor_2);

	if (valor_1>valor_2) {
		printf("O maior valor e o %.2f\n", valor_1);
	} else {
		printf("O maior valor e o %.2f\n", valor_2);
	}
	printf("\aFim do programa!");
	return 0;
}
