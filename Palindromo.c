#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM 1001

void CharMinuscula(char text[]) {
	
	for(int i = 0; i<strlen(text); i++)
		if (text[i]>=65 && text[i]<=90)
			text[i] += 32;
}

void RemoveEspacos(char text[]) {

	int i;
	for(i = 0; i<strlen(text); i++)
		if (text[i]==' ')
			for(int j = i; j<strlen(text); j++)
				text[j] = text[j+1];
	text[i] = '\0';
}

char* Inverte(char text[]) {
	
	char *aux = NULL;
	int j = 0;

	aux = (char *) malloc(TAM*sizeof(char));
	for(int i = strlen(text) - 1; i>=0; i--)
		aux[j++] = text[i];

	return aux;
}

bool Palindromo(char text[]) {

	CharMinuscula(text);
	RemoveEspacos(text);

	char *inverso;
	inverso = Inverte(text);

	if (strcmp(text, inverso)==0) {		
		free(inverso);
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) {

	char entrada[TAM];

	if (argc==2) {
		strcpy(entrada, argv[1]);
	} else {
		printf("Informe um texto de entrada: ");
		fgets(entrada, sizeof(entrada), stdin);
		entrada[strlen(entrada)-1] = '\0'; // Correção de um '\n' que o leitor ler ao pressionar 'enter' do teclado;
	}

	if (Palindromo(entrada)==true)
		printf("\a%s E um palindromo!\n", entrada);
	else 
		printf("\a%s Nao e um palindromo!\n", entrada);

	return 0;
}
