#include <stdio.h>

int main(void) {
	int times = 5, jogadores = 11, idade, x = 0, y = 0, qtd_jogadores_menor = 0, total_idades = 0, total_alturas = 0, cont_peso = 0;
	float peso, altura, media_idades, media_alturas, percent80;

	while(x<times) {
		idade = 0;
		altura = 0;
		peso = 0;
		cont_peso = 0;
		qtd_jogadores_menor = 0;
		total_idades = 0;
		total_alturas = 0;
		y = 0;
		while(y<jogadores) {
			printf("Jogador %d.\nInforme idade: ", y+1);
			scanf("%d", &idade);
			printf("Altura: ");
			scanf("%f", &altura);
			printf("Peso: ");
			scanf("%f", &peso);

			if (idade<18)
				qtd_jogadores_menor = qtd_jogadores_menor + 1;
			total_idades += idade;
			total_alturas += altura;

			if (peso>80.0)
				cont_peso++;
			y = y + 1;
		}
							// Processamento
		media_idades = total_idades / 11.0;
		media_alturas = total_alturas / 11.0;
		percent80 = cont_peso / 11.0 * 100;
							// Saída
		printf("Existem %d jogadores com a idade inferior a 18 anos no time. \n", qtd_jogadores_menor);
		printf("A media das idades dos jogadores %.2f\n", media_idades);
		printf("A media das alturas dos jogadores %.2f\n", media_alturas);
		printf("A porcentagem dos jogadores com peso superior a 80.0 KG e %.2f %%\n\n", percent80);
		x = x + 1;
	}
}
