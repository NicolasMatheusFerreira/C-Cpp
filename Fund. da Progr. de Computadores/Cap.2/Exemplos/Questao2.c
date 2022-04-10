#include <stdio.h>

int main(void) {

	int n, i = 1, fat = 1, numerador = 0;

	printf("Informe N: ");
	scanf("%d", &n);

	if (n>0) {
		while(i<=n) {
			numerador++;
			fat *= i;
			i = i + 1;
		}
		printf("%.4f", (float) numerador/fat);
	} else printf("\aValor invalido!");
	return 0;
}
