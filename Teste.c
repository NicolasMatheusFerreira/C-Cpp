#include <stdio.h>

int Retorno(int x) {
	
	if (x>50)
		if (x>60)
			return 1;
	else
		return 2;
	return 3;
}

int main(void) {

	int x = 51;
	printf("%d", Retorno(x));
	return 0;
}
