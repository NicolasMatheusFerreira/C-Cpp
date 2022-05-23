#include <stdio.h>
#include <stdlib.h>

char *Text() {

	char *nome = NULL;

	nome = (char *) malloc(11*sizeof(char));
	scanf("%s", nome);

//	free(nome);
	return nome;
}

int main(void) {
	
	printf("%s\n", Text());

	return 0;
}
