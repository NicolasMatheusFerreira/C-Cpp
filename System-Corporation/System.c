#include "EntradaSaida.h"
#include "EstruturaDados.h"
#include "EmpresaFuncoes.h"

				// Variáveis e constantes (globais)

char ArquivoRegistros[] = "Cadastros.txt", ArquivoAjustes[] = "ajustes.dat";

				// Protótipos das funções

void Construtor(Pessoa func[]);
void Destrutor(Pessoa func[]); 
void Cadastrar(Pessoa funcionario[]);
bool Apagar(Pessoa funcionario[], int i);
bool ExportarCadastro(Pessoa funcionario[], int i);
bool ImportarCadastros(Pessoa funcionario[]);
bool EditaArquivo(Pessoa funcionario, int i, int op);
void EditaDadosGerais(Pessoa funcionario[], int i, int op);
void EditaEndereco(Pessoa funcionario[], int i, int op);
void EditaEmpresa(Pessoa funcionario[], int i, int op);
bool AtualizarArquivo(Pessoa funcionario[]);
void Filtro(Pessoa funcionario[], int op); 
void Exibir(Pessoa funcionario[], int i, int op);
bool ImportaAjustes(char ArquivoAjustes[]);
bool ExportaAjustes(char ArquivoAjustes[]);

				// Funções
	
bool ImportaAjustes(char ArquivoAjustes[]) {

	FILE *arquiv;
	if ((arquiv = fopen(ArquivoAjustes, "r"))!=NULL) {
		while(!feof(arquiv)) {
			fscanf(arquiv, "# CRIPTOGRAFIA SIMETRICA = %d\n", &criptografia);
		}
		fclose(arquiv);
	} else return false;
	return true;
}

bool ExportaAjustes(char ArquivoAjustes[]) {

	FILE *arquiv;
	if ((arquiv = fopen(ArquivoAjustes, "w"))!=NULL ) {
		fprintf(arquiv, "# CRIPTOGRAFIA SIMETRICA = %d\n", criptografia);
		fclose(arquiv);
	} else return false;
	return true;
}

void Exibir(Pessoa funcionario[], int i, int op) {

	ImportarCadastros(funcionario); 
	OrdenaBolha(funcionario, 1);		
	while(strcmp(funcionario[i].nome, "N/D")!=0 && i<QtdRegistros) {
		if (op==1) {
			Saida(funcionario, i++);
		} else if (op==2) {
			SaidaNome(funcionario, i++);
		} else if (op==3) {
			SaidaNomeCpfRgId(funcionario, i++);
		}
	}
}

void Filtro(Pessoa funcionario[], int op) {

	switch(op) {
		case 1:
			MaiorSalario(funcionario);
		break;

		case 2:
			MenorSalario(funcionario);
		break;
	}
}

void EditaEmpresa(Pessoa funcionario[], int i, int op) {

	switch (op) {
		case 1:
			setSetor(funcionario, i);
		break;

		case 2:
			setId(funcionario, i);
		break;

		case 3:
			setCargo(funcionario, i);
		break;

		case 4:
			setFuncao(funcionario, i);
		break;

		case 5:
			setSalario(funcionario, i);
		break;
	}
}

void EditaEndereco(Pessoa funcionario[], int i, int op) {

	switch (op) {
		case 1:
			setRua(funcionario, i);
		break;

		case 2:
			setNum(funcionario, i);
		break;

		case 3:
			setBairro(funcionario, i);
		break;

		case 4:
			setCidade(funcionario, i);
		break;

		case 5:
			setEstado(funcionario, i);
		break;

		case 6:
			setCep(funcionario, i);
		break;
	}
}

void EditaDadosGerais(Pessoa funcionario[], int i, int op) {

	switch (op) {
		case 1:
			setNome(funcionario, i);
		break;

		case 2:
			setCpf(funcionario, i);
		break;

		case 3:
			setRg(funcionario, i);
		break;

		case 4:
			setSexo(funcionario, i);
		break;

		case 5:
			setCivil(funcionario, i);
		break;

		case 6:
			setDataNasc(funcionario, i);
		break;
	}
}

bool EditarArquivo(Pessoa funcionario[], int i, int op) {

	switch (op) {
		case 1:
			EditaDadosGerais(funcionario, i, GetInt("Informe um valor"));
		break;

		case 2:
			EditaEndereco(funcionario, i, GetInt("Informe um valor"));
		break;

		case 3:
			EditaEmpresa(funcionario, i, GetInt("Informe um valor"));
		break;

		default:
			return false;
		break;
	}

	AtualizarArquivo(funcionario);
	return true;
}

bool AtualizarArquivo(Pessoa funcionario[]) {
	
	FILE *arquiv;
	int i = 0;

	if ((arquiv = fopen(ArquivoRegistros, "w+"))!=NULL) {
		while(strcmp(funcionario[i].nome, "N/D")!=0 && i<TAM) {
			if (criptografia==1)
				CriptografaCifraDeCesar(funcionario, i);			
			FormatoGravacao(arquiv, funcionario, i++);
		}
		fclose(arquiv);
		return true;
	} else return false;
}

bool ImportarCadastros(Pessoa funcionario[]) {

	FILE *arquiv;
	QtdRegistros = 0;

	if ((arquiv = fopen(ArquivoRegistros,"r"))!=NULL) {
		while(!feof(arquiv)) {			
			FormatoLeitura(arquiv, funcionario, QtdRegistros);
			if (criptografia==1) 
				DescriptografaCifraDeCesar(funcionario, QtdRegistros);
			QtdRegistros++;
		}
	} else {
		return false;
	}
	fclose(arquiv);
	return true;
}

bool ExportarCadastro(Pessoa funcionario[], int i) {
	
	FILE *arquiv;

	if ((arquiv = fopen(ArquivoRegistros,"a"))!=NULL) {
		if (criptografia==1) {
			CriptografaCifraDeCesar(funcionario, i);
			FormatoGravacao(arquiv, funcionario, i);
			DescriptografaCifraDeCesar(funcionario, i); 
		} else FormatoGravacao(arquiv, funcionario, i);
	} else return false;
	fclose(arquiv);
	return true;
}

bool CadastroRepetido(Pessoa funcionario[], int x) {

	int cont = 0;
	while(cont<QtdRegistros) {
		if (cont!=x)
			if (strcmp(funcionario[cont].cpf, funcionario[x].cpf)==0)
				return true;
		cont++;
	}
	return false;
}

bool Apagar(Pessoa funcionario[], int i) {

	FILE *arquiv;
	int j = 0;

	if ((arquiv = fopen(".Cadastros","a"))!=NULL) {
		while(j<QtdRegistros) {
			if (j!=i) {
				if (criptografia==1) 
					CriptografaCifraDeCesar(funcionario, j);
				FormatoGravacao(arquiv, funcionario, j);
			}
			j++;
		}
		remove("Cadastros.txt"); rename(".Cadastros","Cadastros.txt");
		fclose(arquiv);
		return true;
	} else return false;
}

void Cadastrar(Pessoa funcionario[]) {

	int cont = QtdRegistros; // Registra dados a partir de uma posição disponível dados pela variável QtdRegistros;

	do {
		Entrada(funcionario, cont); // Realiza leitura dos dados;

//		strcpy(ArquivoRegistros, funcionario[cont].empresa.setor;
		if (CadastroRepetido(funcionario, 2)!=true) {
			if (ExportarCadastro(funcionario, cont)==true) {
				printf("\aUsuario cadastrado com sucesso!");
			} // Erro ao cadastrar no arquivo
		}

		cont++;
	} while(CharBoolean('s', GetChar("Deseja continuar? (S/N): ", 0))==true);
}

void Destrutor(Pessoa func[]) {

	ExportaAjustes(ArquivoAjustes);
	AtualizarArquivo(func); 
}

void Construtor(Pessoa func[]) {

	if (ImportaAjustes(ArquivoAjustes)==false) {
		criptografia = 1;
	}
	for(int cont=0; cont<TAM; cont++) 
		strcpy(func[cont].nome, "N/D");

	if (ImportarCadastros(func)==false) {
		// Erro ao abrir o arquivo!
	}
}

int main(void) {
	
	Pessoa funcionario[TAM]; 
	
	Construtor(funcionario); // Prepara structs e variáveis para manipulação das demais funções;

	ExportaAjustes(ArquivoAjustes);
//	Cadastrar(funcionario);
	Exibir(funcionario, 0, 1);
	Destrutor(funcionario);
	return 0;
}
