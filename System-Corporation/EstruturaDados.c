#include "EstruturaDados.h"
					// Criptografia
int getCriptografia() {
	return criptografia;
} 

void setCriptografia(Pessoa func[], int opcao) {

	if (criptografia==1 && opcao==0) {
		for(int k=0; k<QtdRegistros; k++)
			DescriptografaCifraDeCesar(func, k);
		criptografia = 0;
	} else if (criptografia==0 && opcao==1) {
		for(int k=0; k<QtdRegistros; k++)
			CriptografaCifraDeCesar(func, k);
		criptografia = 1;
	}
}


void DescriptografaCifraDeCesar(Pessoa func[], int posic) {
		
	const int repeticoes = 5, chave = 3;

	for(int j=0; j<repeticoes; j++) {

		func[posic].sexo-=chave;		
		func[posic].dataNasc.dia-=chave;
		func[posic].dataNasc.mes-=chave;
		func[posic].dataNasc.ano-=chave;
		func[posic].ender.num-=chave;
		func[posic].empresa.id-=chave;
		func[posic].empresa.salario-=chave;

		for(int z=strlen(func[posic].nome)-1; z>=0; z--)
			func[posic].nome[z]-=chave;
		for(int z=strlen(func[posic].cpf)-1; z>=0; z--)
			func[posic].cpf[z]-=chave;
		for(int z=strlen(func[posic].rg)-1; z>=0; z--)
			func[posic].rg[z]-=chave;
		for(int z=strlen(func[posic].civil)-1; z>=0; z--)
			func[posic].civil[z]-=chave;
		for(int z=strlen(func[posic].ender.rua)-1; z>=0; z--) 
			func[posic].ender.rua[z]-=chave;
		for(int z=strlen(func[posic].ender.bairro)-1; z>=0; z--)
			func[posic].ender.bairro[z]-=chave;
		for(int z=strlen(func[posic].ender.cidade)-1; z>=0; z--)
			func[posic].ender.cidade[z]-=chave;
		for(int z=strlen(func[posic].ender.estado)-1; z>=0; z--)
			func[posic].ender.estado[z]-=chave;
		for(int z=strlen(func[posic].ender.cep)-1; z>=0; z--)
			func[posic].ender.cep[z]-=chave;
		for(int z=strlen(func[posic].empresa.setor)-1; z>=0; z--) 
			func[posic].empresa.setor[z]-=chave;
		for(int z=strlen(func[posic].empresa.cargo)-1; z>=0; z--) 
			func[posic].empresa.cargo[z]-=chave;
		for(int z=strlen(func[posic].empresa.funcao)-1; z>=0; z--)
			func[posic].empresa.funcao[z]-=chave;
	}
}

void CriptografaCifraDeCesar(Pessoa func[], int posic) {
	
	const int repeticoes = 5, chave = 3;
	
	for(int j=0; j<repeticoes; j++) {

		func[posic].sexo+=chave;
		func[posic].ender.num+=chave;
		func[posic].empresa.id+=chave;
		func[posic].dataNasc.dia+=chave;
		func[posic].dataNasc.mes+=chave;
		func[posic].dataNasc.ano+=chave;
		func[posic].empresa.salario+=chave;

		for(int z=0; z<strlen(func[posic].nome); z++)
			func[posic].nome[z]+=chave;
		for(int z=0; z<strlen(func[posic].cpf); z++) 
			func[posic].cpf[z]+=chave;
		for(int z=0; z<strlen(func[posic].rg); z++) 
			func[posic].rg[z]+=chave;		
		for(int z=0; z<strlen(func[posic].civil); z++)
			func[posic].civil[z]+=chave;
		for(int z=0; z<strlen(func[posic].ender.rua); z++)
			func[posic].ender.rua[z]+=chave;		
		for(int z=0; z<strlen(func[posic].ender.bairro); z++)
			func[posic].ender.bairro[z]+=chave;
		for(int z=0; z<strlen(func[posic].ender.cidade); z++)
			func[posic].ender.cidade[z]+=chave;
		for(int z=0; z<strlen(func[posic].ender.estado); z++) 
			func[posic].ender.estado[z]+=chave;
		for(int z=0; z<strlen(func[posic].ender.cep); z++) 
			func[posic].ender.cep[z]+=chave;
		for(int z=0; z<strlen(func[posic].empresa.setor); z++) 
			func[posic].empresa.setor[z]+=chave;
		for(int z=0; z<strlen(func[posic].empresa.cargo); z++) 
			func[posic].empresa.cargo[z]+=chave;
		for(int z=0; z<strlen(func[posic].empresa.funcao); z++)
			func[posic].empresa.funcao[z]+=chave;
	}
}
					// Pesquisas				

int PesquisaIterativa(Pessoa func[], char texto[], int op) {
	
	int posic = 0;
	switch (op) {

		case 1:
			while(posic<TAM) { // Varia os vetor até achar a posição;
				if (strcmp(texto, func[posic].nome)==0) { // Testa se id é igual a posição variando o j;
					return posic; // Se id for igual a posicao retorna a posic;
				}
				posic++;
			}
			return -1;
		break;

		case 2:
			while(posic<TAM) { // Varia os vetor até achar a posição;
				if (strcmp(texto, func[posic].cpf)==0) { // Testa se id é igual a posição variando o j;
					return posic; // Se id for igual a posicao retorna a posic;
				}
				posic++;
			}
			return -1;
		break;

		case 3:
			while(posic<TAM) { // Varia os vetor até achar a posição;
				if (strcmp(texto, func[posic].rg)==0) { // Testa se id é igual a posição variando o j;
					return posic; // Se id for igual a posicao retorna a posic;
				}
				posic++;
			}
			return -1;
		break;
	}
}

int PesquisaBinaria(Pessoa func[], char texto[], int op) {

}

					// Ordenações
					//
void OrdenaBolha(Pessoa func[], int op) {

	Pessoa aux;
	switch(op) {
		case 1:
			for(int i=0; i<QtdRegistros; i++) {
				for(int j=0; j<QtdRegistros-1; j++) {
					if (strcmp(func[j].nome, func[j+1].nome)>0) {
						aux = func[j];
						func[j] = func[j+1];
						func[j+1] = aux;
					}
				}
			}
		break;
	}
}
