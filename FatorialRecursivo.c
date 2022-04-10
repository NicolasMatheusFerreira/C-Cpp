#include <stdio.h>
#include <string.h>

int FatRec(int num) {

	if (num==1)
		return 1;
	else num *= FatRec(num-1);
	return num;
}

int main(int argc, char *argv[]) {

	int resultado;

	if (argc==2) {
		if (strcmp(argv[1], "0")==0)
			resultado = 0;
		else if (strcmp(argv[1], "1")==0)
				resultado = 1;
		else resultado = FatRec(atoi(argv[1]));

		printf("O resultado do fatorial de %d e igual a %d\n", atoi(argv[1]), resultado);
	} else printf("\aValor (es), invalidos! \n");
	return 0;
}
