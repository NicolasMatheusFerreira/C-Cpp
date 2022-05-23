#include <stdio.h>
#include <stdlib.h>

int main(void) {

	// Incrementação de ponteiros
	int x = 20;
	int *p = &x;
	printf("%d\n", *p);

//	*p = ++(*p);
//	(*p)++;
//	*p = (*p) * 10;
	printf("%d\n", x);
	return 0;
}
