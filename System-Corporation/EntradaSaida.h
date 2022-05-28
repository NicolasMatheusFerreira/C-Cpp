#ifndef ENTRADASAIDA_H_   
#define ENTRADASAIDA_H_

			// Bibliotecas;
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
			// Estruturas;
struct Pessoa {
	char nome[101], cpf[16], rg[15];
	char sexo, civil[21];

	struct Endereco {
		char rua[31], bairro[31];
		int num;
		char cidade[21], estado[21], cep[12];
	} ender;
	
	struct DataNascimento {
		int dia, mes, ano;
	} dataNasc;
	
	struct Funcionario {
		char setor[21];
		int id;
		char cargo[21], funcao[21];
		float salario;
	} empresa;
} typedef Pessoa;

		// Variáveis (globais) e Constantes;

#define TAM 10000 // Constante indica quantidade de posições na struct pessoa;
int QtdRegistros;

		// Protótipos das funções;

						// Entradas
void Entrada(struct Pessoa func[], int cont);

void setNome(Pessoa func[], int cont);
void setCpf(Pessoa func[], int cont);
void setRg(Pessoa func[], int cont);
void setSexo(Pessoa func[], int cont);
void setCivil(Pessoa func[], int cont);
void setDataNasc(Pessoa func[], int cont);
void setRua(Pessoa func[], int cont);
void setNum(Pessoa func[], int cont);
void setBairro(Pessoa func[], int cont);
void setCidade(Pessoa func[], int cont);
void setEstado(Pessoa func[], int cont);
void setCep(Pessoa func[], int cont);
void setSetor(Pessoa func[], int cont);
void setId(Pessoa func[], int cont);
void setCargo(Pessoa func[], int cont);
void setFuncao(Pessoa func[], int cont);
void setSalario(Pessoa func[], int cont);
						// Saidas
void Saida(struct Pessoa func[], int i);
void SaidaNome(Pessoa func[], int i);
void SaidaNomeCpfRgId(Pessoa func[], int i);
						// Entradas e Saidas p/Arquivos
void FormatoGravacao(FILE *arquiv, Pessoa funcionario[], int i); 
void FormatoLeitura(FILE *arquiv, Pessoa funcionario[], int i); 

						// Retorno de tipos
char GetChar(char string[], int i);
int GetInt(char texto[]); 
const char *GetString(char string[]);
bool CharBoolean(char condic, char caractere); 
						// LimparBuffer
void Limpabuffer();

#endif 
