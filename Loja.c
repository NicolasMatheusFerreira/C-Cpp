#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	float valor_compra, total = 0;
	int desconto;

	printf("Loja\n\n");

	printf("Valor da compra: ");
	scanf("%f", &valor_compra);

	desconto = 0;

	for(int i=500; i<=valor_compra && desconto<25; i+=500) {
		desconto++;
	}

	total = valor_compra-(desconto*valor_compra/100);

	printf("Valor da compra: %.2f - Desconto: %d %% - Total: R%c %.2f\n", valor_compra, desconto, 36, total);
	return 0;
}
