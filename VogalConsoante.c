#include <stdio.h>
#include <ctype.h>

int main(void) {

	char caractere;

	printf("Informe uma letra.\nLetra: ");
	setbuf(stdin, NULL);
	scanf("%c", &caractere);
	caractere = toupper(caractere);
	
	if (caractere=='A' || caractere=='E' || caractere=='I' || caractere=='O' || caractere=='U') {
		printf("\aVogal.");
	} else if (caractere>=33 && caractere<=64 || caractere>=91 && caractere<=255) {
		printf("\aCaractere invalido!");
	} else printf("\aConsoante.");

	return 0;
}
