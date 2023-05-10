#include <stdio.h>
#include <stdlib.h>

void Vetor(char* memoria) {

	printf("%d ", (*memoria)+1);
	printf("%c", (*memoria)+1);

}

int main(void) {

	char caractere = 'a';
	Vetor(&caractere);
	return 0;
}
