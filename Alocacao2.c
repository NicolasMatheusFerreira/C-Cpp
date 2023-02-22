#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	char* caracter;
	caracter = malloc(11);
		
	printf("Informe seu nome: ");
	setbuf(stdin, NULL);

	fgets(caracter, 11, stdin);

	printf("%s\n", caracter);

	free(caracter);	
	puts(caracter);

	return 0;
}
