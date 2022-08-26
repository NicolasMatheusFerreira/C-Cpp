#ifndef ESTRUTURADADOS_H_  
#define ESTRUTURADADOS_H_
				// Bibliotecas
#include "EntradaSaida.h"

				// Variáveis e constantes (globais)
int criptografia;
				// Protótipos das funções

void CriptografaCifraDeCesar(Pessoa func[], int posic);
void DescriptografaCifraDeCesar(Pessoa func[], int posic);
void setCriptografia(Pessoa func[], int opcao);
int getCriptografia(); 

int PesquisaIterativa(Pessoa func[], char texto[], int op);
int PesquisaBinaria(Pessoa func[], char texto[], int op);

void OrdenaBolha(Pessoa func[], int op); 


#endif 
