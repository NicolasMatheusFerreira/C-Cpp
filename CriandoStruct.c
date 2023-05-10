#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {

	char nome[31];
	int idade;
	float peso, altura;
	struct DataNasc {
		int dia, mes, ano;
	};
	struct DataNasc dataNasc;
} typedef Pessoa;

struct Cachorro {
	char nome[11];
	int idade;
};

int main(void) {

	struct Cachorro cao;
	strcpy(cao.nome, "Toto");
	cao.idade = 12;

	printf("Nome do cachorro: %s - Idade: %d\n\n", cao.nome, cao.idade);

	Pessoa pessoa;

	strcpy(pessoa.nome, "Nicolas Matheus Ferreira");
	pessoa.idade = 22;
	pessoa.peso = 55.0;
	pessoa.altura = 1.78;
	pessoa.dataNasc.dia = 13;
	pessoa.dataNasc.mes = 03;
	pessoa.dataNasc.ano = 2001;


	printf("Nome: %s - Idade: %d - Peso: %.2f - Altura: %.2f - ", pessoa.nome, pessoa.idade, pessoa.peso, pessoa.altura);
	printf("Data de nascimento: %d/%d/%d", pessoa.dataNasc.dia, pessoa.dataNasc.mes, pessoa.dataNasc.ano);
}
