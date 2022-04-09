#include <stdio.h>
#include <string.h>

void Cabecalho() {

	char tabulacao[10] = "\t\t\t\t\t\t\t\t\t";
	printf("%s M.M.C. --- Minimo Multiplo Comum --- \n\n", tabulacao);
	printf("%s --- Por Nicolas M. Ferreira ---\n\n\n", tabulacao);
}

int isMMC2(int valor_1, int valor_2) {

	int num = 2, resultado = 1;

	while(valor_1!=1 || valor_2!=1) {
		if (valor_1%num==0 && valor_2%num==0) {
			valor_1/=num;
			valor_2/=num;
			resultado = resultado * num;
		} else if (valor_1%num==0) {
			valor_1/=num;	
			resultado = resultado * num;
		} else if (valor_2%num==0) {
			valor_2/=num;
			resultado = resultado * num;
		} else 
			num++;
	}
	return resultado;
}

int isMMC3(int valor_1, int valor_2, int valor_3) { 
	int num = 2, resultado = 1;
	
		while(valor_1!=1 || valor_2!=1 || valor_3!=1) {
			if (valor_1%num==0 && valor_2%num==0 && valor_3%num==0) {
				valor_1/=num;	
				valor_2/=num;	
				valor_3/=num;	
				resultado = resultado * num;
			} else if (valor_1%num==0 && valor_2%num==0) {
				valor_1/=num;	
				valor_2/=num;	
				resultado = resultado * num;
			} else if (valor_1%num==0 && valor_3%num==0) {
				valor_1/=num;
				valor_3/=num;
				resultado = resultado * num;
			} else if (valor_2%num==0 && valor_3%num==0) {
				valor_2/=num;
				valor_3/=num;
				resultado = resultado * num;
			} else if (valor_1%num==0) {
				valor_1/=num;
				resultado = resultado * num;
			} else if (valor_2%num==0) {
				valor_2/=num;
				resultado = resultado * num;
			} else if (valor_3%num==0) {
				valor_3/=num;
				resultado = resultado * num;
			} else num++;
		}
	return resultado;
}

int main(int argc, char *argv[]) {

	int valor_1, valor_2, valor_3;
		
	valor_1 = atoi(argv[1]);
	valor_2 = atoi(argv[2]);
	valor_3 = atoi(argv[3]);

	if (argc==3) {		
		printf("\nO resultado do MMC e %d \n", isMMC2(valor_1, valor_2));
	} else  if (argc==4) {
		printf("\nO resultado do MMC e %d \n", isMMC3(valor_1, valor_2, valor_3));
	}
	return 0;
}
