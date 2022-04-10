#include <stdio.h>

int main(void) {
	float salario, aument_salario, novo_salario, percent = 1.5;
	int i = 2000, ano;

	printf("Salario: R%c ", 36);
	scanf("%f", &salario);

	printf("Ano: ");
	scanf("%d", &ano);

	while(i<ano) {
		percent*=2;
		i++;
	}
	aument_salario = percent*salario/100;
	novo_salario = salario + aument_salario;
	printf("Aumento de salario foi de R%c %.2f\nE seu novo salario no ano de %d foi de R%c %.2f\n", 36, aument_salario, ano, 36, novo_salario);
}
