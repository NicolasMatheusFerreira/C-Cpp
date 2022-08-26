#include "EntradaSaida.h"

void Limpabuffer() {

    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

bool CharBoolean(char condic, char caractere) {
	if (condic==caractere) {
		return true;
	} else return false;
} 

const char *GetString(char string[]) {
	
	static char texto[11];
	printf("%s", string);
	setbuf(stdin, NULL);
	fgets(texto, sizeof(texto), stdin);
	texto[strlen(texto)-1]='\0';
	return texto;
}

int GetInt(char texto[]) {

	int valor;
	printf("%s", texto);
	scanf("%d", &valor);
	return valor;
}

char GetChar(char string[], int i) {
	
	char caractere;
	printf("%s", string);
	setbuf(stdin, NULL);
	scanf("%c", &caractere);

	if (i==0) {
		caractere = tolower(caractere);
	} else caractere = toupper(caractere);
	Limpabuffer();
	return caractere;
}
						// Entradas e Saidas para arquivo

void FormatoLeitura(FILE *arquiv, Pessoa funcionario[], int i) {

	// Leitura dos dados em arquivos para as structs;
	
	fgets(funcionario[i].nome, sizeof(funcionario[i].nome), arquiv); // Lendo dados gerais;
	funcionario[i].nome[strlen(funcionario[i].nome)-1]='\0';
	fscanf(arquiv, "\n%s\n", funcionario[i].cpf); 
	fscanf(arquiv, "%s\n", funcionario[i].rg); 
	fscanf(arquiv, "%d/%d/%d\n", &funcionario[i].dataNasc.dia, &funcionario[i].dataNasc.mes, &funcionario[i].dataNasc.ano);
	fscanf(arquiv, "%c\n", &funcionario[i].sexo);
	fgets(funcionario[i].civil, sizeof(funcionario[i].civil), arquiv);
	funcionario[i].civil[strlen(funcionario[i].civil)-1]='\0';

	fgets(funcionario[i].ender.rua, sizeof(funcionario[i].ender.rua), arquiv); // Lendo dados de endereço;
	funcionario[i].ender.rua[strlen(funcionario[i].ender.rua)-1]='\0';
	fscanf(arquiv, "\n");
	fscanf(arquiv, "%d\n", &funcionario[i].ender.num);
	fgets(funcionario[i].ender.bairro, sizeof(funcionario[i].ender.bairro), arquiv);
	funcionario[i].ender.bairro[strlen(funcionario[i].ender.bairro)-1]='\0';
	fscanf(arquiv, "\n");
	fgets(funcionario[i].ender.cidade, sizeof(funcionario[i].ender.cidade), arquiv);
	funcionario[i].ender.cidade[strlen(funcionario[i].ender.cidade)-1]='\0';
	fscanf(arquiv, "\n");
	fgets(funcionario[i].ender.estado, sizeof(funcionario[i].ender.estado), arquiv);
	funcionario[i].ender.estado[strlen(funcionario[i].ender.estado)-1]='\0';
	fscanf(arquiv, "\n");
	fgets(funcionario[i].ender.cep, sizeof(funcionario[i].ender.cep), arquiv);
	funcionario[i].ender.cep[strlen(funcionario[i].ender.cep)-1]='\0';
	fscanf(arquiv, "\n");
	fgets(funcionario[i].empresa.setor, sizeof(funcionario[i].empresa.setor), arquiv); // Lendo dados de empresa;
	funcionario[i].empresa.setor[strlen(funcionario[i].empresa.setor)-1]='\0';
	fscanf(arquiv, "\n");
	fscanf(arquiv, "%d\n", &funcionario[i].empresa.id);
	fgets(funcionario[i].empresa.cargo, sizeof(funcionario[i].empresa.cargo), arquiv);
	funcionario[i].empresa.cargo[strlen(funcionario[i].empresa.cargo)-1]='\0';
	fscanf(arquiv, "\n");
	fgets(funcionario[i].empresa.funcao, sizeof(funcionario[i].empresa.funcao), arquiv);
	funcionario[i].empresa.funcao[strlen(funcionario[i].empresa.funcao)-1]='\0';
	fscanf(arquiv, "\n");
	fscanf(arquiv, "%f\n\n", &funcionario[i].empresa.salario);
}

void FormatoGravacao(FILE *arquiv, Pessoa funcionario[], int i) {

	// Gravação dos dados em structs nos arquivos;
	
	fprintf(arquiv, "%s\n%s\n%s\n", funcionario[i].nome, funcionario[i].cpf, funcionario[i].rg); // Gravando dados gerais
	fprintf(arquiv, "%d/%d/%d\n", funcionario[i].dataNasc.dia, funcionario[i].dataNasc.mes, funcionario[i].dataNasc.ano);
	fprintf(arquiv, "%c\n%s\n", funcionario[i].sexo, funcionario[i].civil);
	fprintf(arquiv, "%s\n%d\n%s\n", funcionario[i].ender.rua, funcionario[i].ender.num, funcionario[i].ender.bairro); // Gravando endereço;
	fprintf(arquiv, "%s\n%s\n%s\n", funcionario[i].ender.cidade, funcionario[i].ender.estado, funcionario[i].ender.cep);
	fprintf(arquiv, "%s\n%d\n", funcionario[i].empresa.setor, funcionario[i].empresa.id);
	fprintf(arquiv, "%s\n%s\n%f", funcionario[i].empresa.cargo, funcionario[i].empresa.funcao, funcionario[i].empresa.salario);
	fprintf(arquiv, "\n\n");
}
						// Saidas - Exibição de dados
void SaidaNome(Pessoa func[], int i) {

	printf("(%d) - %s\n", 1+i, func[i].nome);
}
void SaidaNomeCpfRgId(Pessoa func[], int i) {

	printf("(%d) - %s - %s - %s - %d\n", 1+i, func[i].nome, func[i].cpf, func[i].rg, func[i].empresa.id);
}


void Saida(Pessoa func[], int i) {

	printf("%s - %s - %s - %c - %s\n", func[i].nome, func[i].cpf, func[i].rg, func[i].sexo, func[i].civil);
	printf("%d/%d/%d\n", func[i].dataNasc.dia, func[i].dataNasc.mes, func[i].dataNasc.ano);
	printf("%s - %d - %s - %s - %s - %s\n", func[i].ender.rua, func[i].ender.num, func[i].ender.bairro, func[i].ender.cidade, func[i].ender.estado, func[i].ender.cep);
	printf("%s - %d - %s - %s - %.2f\n\n", func[i].empresa.setor, func[i].empresa.id, func[i].empresa.cargo, func[i].empresa.funcao, func[i].empresa.salario);
}
						// Entradas - Definição de dados
void setSalario(Pessoa func[], int cont) {
	
	printf("Salario: ");
	scanf("%f", &func[cont].empresa.salario);
}
void setFuncao(Pessoa func[], int cont) {

	printf("Função: ");
	setbuf(stdin, NULL);
	fgets(func[cont].empresa.funcao, sizeof(func[cont].empresa.funcao), stdin);
	func[cont].empresa.funcao[strlen(func[cont].empresa.funcao)-1]='\0';
}
void setCargo(Pessoa func[], int cont) {

	printf("Cargo: ");
	setbuf(stdin, NULL);
	fgets(func[cont].empresa.cargo, sizeof(func[cont].empresa.cargo), stdin);
	func[cont].empresa.cargo[strlen(func[cont].empresa.cargo)-1]='\0';
}
void setId(Pessoa func[], int cont) {

	printf("ID: ");
	scanf("%d", &func[cont].empresa.id);
}
void setSetor(Pessoa func[], int cont) {

	printf("Setor: ");
	setbuf(stdin, NULL);
	fgets(func[cont].empresa.setor, sizeof(func[cont].empresa.setor), stdin);
	func[cont].empresa.setor[strlen(func[cont].empresa.setor)-1]='\0';
}
void setCep(Pessoa func[], int cont) {

	printf("CEP: ");
	setbuf(stdin, NULL);
	fgets(func[cont].ender.cep, sizeof(func[cont].ender.cep), stdin);
	func[cont].ender.cep[strlen(func[cont].ender.cep)-1]='\0';
}
void setEstado(Pessoa func[], int cont) {

	printf("Estado: ");
	setbuf(stdin, NULL);
	fgets(func[cont].ender.estado, sizeof(func[cont].ender.estado), stdin);
	func[cont].ender.estado[strlen(func[cont].ender.estado)-1]='\0';
}
void setCidade(Pessoa func[], int cont) {
	
	printf("Cidade: ");
	setbuf(stdin, NULL);
	fgets(func[cont].ender.cidade, sizeof(func[cont].ender.cidade), stdin);
	func[cont].ender.cidade[strlen(func[cont].ender.cidade)-1]='\0';
}
void setBairro(Pessoa func[], int cont) {

	printf("Bairro: ");
	setbuf(stdin, NULL);
	fgets(func[cont].ender.bairro, sizeof(func[cont].ender.bairro), stdin);
	func[cont].ender.bairro[strlen(func[cont].ender.bairro)-1]='\0';
}
void setNum(Pessoa func[], int cont) {

	printf("N: ");
	scanf("%d", &func[cont].ender.num);
}
void setRua(Pessoa func[], int cont) {
	
	printf("Rua: ");
	setbuf(stdin, NULL);
	fgets(func[cont].ender.rua, sizeof(func[cont].ender.rua), stdin);
	func[cont].ender.rua[strlen(func[cont].ender.rua)-1]='\0'; 
}
void setDataNasc(Pessoa func[], int cont) {
	
	printf("Data Nasc: "); 
	scanf("%d/%d/%d", &func[cont].dataNasc.dia, &func[cont].dataNasc.mes, &func[cont].dataNasc.ano);
}
void setCivil(Pessoa func[], int cont) {

	printf("Estado Civil: ");
	setbuf(stdin, NULL);
	Limpabuffer();
	fgets(func[cont].civil, sizeof(func[cont].civil), stdin);
	func[cont].civil[strlen(func[cont].civil)-1]='\0';
}
void setSexo(Pessoa func[], int cont) {

	printf("Sexo: ");
	setbuf(stdin, NULL);
	scanf("%c", &func[cont].sexo);
}
void setRg(Pessoa func[], int cont) {

	printf("RG: ");
	setbuf(stdin, NULL);
	fgets(func[cont].rg, sizeof(func[cont].rg), stdin);
	func[cont].rg[strlen(func[cont].rg)-1]='\0';
}
void setCpf(Pessoa func[], int cont) {

	printf("CPF: ");
	setbuf(stdin, NULL);
	fgets(func[cont].cpf, sizeof(func[cont].cpf), stdin);
	func[cont].cpf[strlen(func[cont].cpf)-1]='\0';
}
void setNome(Pessoa func[], int cont) {

	printf("Nome (Completo): "); 
	setbuf(stdin, NULL);
	fgets(func[cont].nome, sizeof(func[cont].nome), stdin);
	func[cont].nome[strlen(func[cont].nome)-1]='\0'; // Para remover o \n lido ao final de cada string;
}

void Entrada(Pessoa func[], int cont) {

	// Leitura dos dados e armazenamento nas structs;

					// Leitura dados gerais;
	setNome(func, cont);
	setCpf(func, cont);
	setRg(func, cont);
	setSexo(func, cont);
	setCivil(func, cont);
	setDataNasc(func, cont);
	setRua(func, cont);		// Leitura endereço;
	setNum(func, cont);
	setBairro(func, cont);
	setCidade(func, cont);
	setEstado(func, cont);
	setCep(func, cont);
	setSetor(func, cont);		// Leitura empresa (funcionario);
	setId(func, cont);
	setCargo(func, cont);
	setFuncao(func, cont);
	setSalario(func, cont);	
}
