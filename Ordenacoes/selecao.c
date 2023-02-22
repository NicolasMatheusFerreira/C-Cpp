#include <stdio.h>
#include <stdlib.h>

int Tamanho(int vetor[]) {

	return sizeof(vetor);
}

void Listar(int conjunto[]) {
	for(int s = 0; s<Tamanho(conjunto); s++)
		printf("%d ", conjunto[s]);
	printf("\n");
}

void SelectionSort(int vetor[]) {
	
	for(int i = 0; i<Tamanho(vetor)-1; i++)
		for(int j = i+1; j<Tamanho(vetor); j++)
			if (vetor[j]<vetor[i]) {
				int aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
}

int main(void) {

	int conjunto[] = {10, 9, 4, 3, 2, 6, 7, 8, 1, 5, 0};

	Listar(conjunto);

	SelectionSort(conjunto);
	
	Listar(conjunto);


	return 0;
}
