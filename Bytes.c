#include <stdio.h>

int main(void) {

	int a;
	float b;
	double c;
	char d;

	printf("Inteiro = %ld bytes -- %ld bits\n", sizeof(a), sizeof(a)*8);
	printf("Real Simples = %ld bytes -- %ld bits\n", sizeof(b), sizeof(b)*8);
	printf("Real Duplo = %ld bytes -- %ld bits\n", sizeof(c), sizeof(c)*8);
	printf("Caractere = %ld bytes -- %ld bits\n\n", sizeof(d), sizeof(d)*8);

	int e[10];
	float f[10];
	double g[10];
	char h[10];

	printf("Vetor inteiro = %ld bytes -- %ld bits\n", sizeof(e), sizeof(e)*8);
	printf("Vetor Real simples = %ld bytes -- %ld bits\n", sizeof(f), sizeof(f)*8);
	printf("Vetor Real dublo = %ld bytes -- %ld bits\n", sizeof(g), sizeof(g)*8);
	printf("Vetor caractere = %ld bytes -- %ld bits\n", sizeof(h), sizeof(h)*8);



}
