#include <stdio.h>

void Tabuada(int x, int y, int z) {
	for(int i=0; i<=x; i++) {
		for(int j=y; j<=z; j++) {
			printf("%d x %d = %d\n", i, j, i*j);
		}
	}
}

int main(int argc, char *argv[]) {
	
	if (argc==4)
		Tabuada(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	else printf("\aO programa nao pode ser executado!");
	return 0;
}
