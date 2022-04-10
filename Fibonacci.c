#include <stdio.h>

int main(int argc, char *argv[]) {

	int i = 0, a = 0, b = 1, result = 0;

	if (argc==2)
		while(i<atoi(argv[1])) {
			a = result;
			result = a + b;
			printf("%d ", result);
			b = a;
		
			i++;
		}
	else printf("\aO programa nao pode ser executado!\n");
	return 0;
}
