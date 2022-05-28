#include "Sistema de login.h"
#include "Interface.h"

	// Funções

void Administrador() {

	strcpy(admin_usuario, "Admin");
	strcpy(admin_senha, "123"); 
}

void Versao() {
	MenuVersao();
	getchar();
}

void FormatoCadastros(int i, int y) {

	MenuFormatoUsuarios(i, y);
}

void FormatoArquivos(FILE *arquiv, Login login[], int i) {

	fprintf(arquiv, "%s\n", login[i].nome);
	fprintf(arquiv, "%s\n", login[i].email);
	fprintf(arquiv, "%s\n", login[i].permissao);
	fprintf(arquiv, "%s\n", login[i].usuario);
	fprintf(arquiv, "%s\n\n", login[i].senha);
}

void PesquisarCadastros(FILE *arquiv, Login login[]) {

	char pesquisa_cadastros[31];
	int encontrado = 0, i;
	
	gotoxy(10,5);
	printf("Pesquisar: ");
	setbuf(stdin, NULL);
	fgets(pesquisa_cadastros, sizeof(pesquisa_cadastros), stdin);
	pesquisa_cadastros[strlen(pesquisa_cadastros)-1]='\0';
	
	OrdenaCadastrosUsuarios(login);
	for(i=0; i<total_cadastrados && encontrado==0; i++)
		if (strcmp(pesquisa_cadastros, login[i].usuario)==0)
			encontrado = 1;
	
	if (encontrado==1) {
		FormatoCadastros(--i, 7); getchar();
	} else {
		gotoxy(10,7);
		printf("\aCadastro nao encontrado! \n");
	}
}

int ListarCadastros(Login login[]) {

	int i = 0;

	for(i=0; i<total_cadastrados; i++) {
		gotoxy(60, 8+i);
		printf("[%d] %s - [%s]\n", i+1, login[i].usuario, login[i].nome);
	}
	return 8+i;
}

void ImprimeCadastros(FILE *arquiv, Login login[]) {

	ImportarCadastros(arquiv, login);
	OrdenaCadastrosUsuarios(login);

	int y = 10, i;
	gotoxy(65,4);
	printf("Total de usuarios cadastrados: %i \n\n", total_cadastrados);
	if (strcmp(login[0].usuario, "-1")==0) {
		gotoxy(65, 10);
		printf("Nenhum usuario cadastrado!");
	} else {
		for(i=0; i<total_cadastrados; i++) {
			FormatoCadastros(i, y);
			y+=4;
		}
	}
	getchar();
}

void OrdenaCadastrosUsuarios(Login login[]) {

	Login aux;
	for(int i=0; i<total_cadastrados; i++)
		for(int j=0; j<total_cadastrados-1; j++) 
			if (strcmp(login[j].usuario, login[j+1].usuario)>0) {
				aux = login[j];
				login[j]=login[j+1];
				login[j+1]=aux;
			}
}

void ExportarCadastros(FILE *arquiv, Login login[]) {

	if ((arquiv = fopen("Cadastros.txt","w"))==NULL)
		printf("\aErro ao abrir o arquivo! \n");
	else {
		for(int i=0; i<total_cadastrados; i++) 
			if (strcmp(login[i].usuario, "-1")!=0) {
				CriptografaDados(login, i);
				FormatoArquivos(arquiv, login, i);
			}
		fclose(arquiv);
	}
}

void EditarCadastros(FILE *arquiv, Login login[]) {

	int op, encontrado=0;
	char editar_usuario[31], novo_nome[51], novo_email[51], novo_permissao[16], novo_usuario[31], novo_senha[16];
	
	ImportarCadastros(arquiv, login);

	gotoxy(60,2);
	printf("(0). Voltar ou (2). Inserir");
	gotoxy(60,3);
	printf("Opcao: ");
	scanf("%i", &op);
	
	if (op==2) {
		gotoxy(60,7);
		printf("(Nome de usuario): ");
		setbuf(stdin, NULL);
		fgets(editar_usuario, sizeof(editar_usuario), stdin);
		editar_usuario[strlen(editar_usuario)-1]='\0';

		for(int i=0; i<total_cadastrados && encontrado==0; i++)
			if (strcmp(editar_usuario, login[i].usuario)==0) {
				do {
					MenuEditar();
					gotoxy(79,33);
					scanf("%i", &op);
	
					switch(op) {
						case 1:
							printf("Novo nome: ");
							setbuf(stdin, NULL);
							fgets(novo_nome, sizeof(novo_nome), stdin);
							novo_nome[strlen(novo_nome)-1]='\0';
							strcpy(login[i].nome, novo_nome);
						break;
		
						case 2:
							printf("Novo e-mail: ");
							setbuf(stdin, NULL);
							fgets(novo_email, sizeof(novo_email), stdin);
							novo_email[strlen(novo_email)-1]='\0';
							strcpy(login[i].email, novo_email);
						break;
					
						case 3:
							printf("Permissao: ");
							setbuf(stdin, NULL);
							fgets(novo_permissao, sizeof(novo_permissao), stdin);
							novo_permissao[strlen(novo_permissao)-1]='\0';
							strcpy(login[i].permissao, novo_permissao);
						break;
		
						case 4:
							printf("Novo usuario: ");
							setbuf(stdin, NULL);
							fgets(novo_usuario, sizeof(novo_usuario), stdin);
							novo_usuario[strlen(novo_usuario)-1]='\0';
							strcpy(login[i].usuario, novo_usuario);
						break;
				
						case 5:
							printf("Nova senha: ");
							setbuf(stdin, NULL);
							fgets(novo_senha, sizeof(novo_senha), stdin);
							novo_senha[strlen(novo_senha)-1]='\0';
							strcpy(login[i].senha, novo_senha);
						break;
					}
				} while(op!=6);
				encontrado=1;
			} 
		
			if (encontrado==0) {
				gotoxy(70,5);
				printf("\aUsuario nao encontrado!");
				getchar();
				getchar();
			}

			ExportarCadastros(arquiv, login);
	}
}

void ApagarCadastros(FILE *arquiv, Login login[]) {

	char remove_usuario[31];
	FILE *arquiv2;
	int encontrado=0, tam, opcao;

	do {
		system("cls");
		ImportarCadastros(arquiv, login);
		tam = ListarCadastros(login);

		gotoxy(60, 3);
		printf("Remover usuarios cadastrados");
		gotoxy(60, 5);
		printf("(1). Continuar OU (2). Para voltar: ");
		scanf("%d", &opcao);

		if (opcao==1) {
			gotoxy(60,6);
			printf("Remover Usuario: ");
			setbuf(stdin, NULL);
			fgets(remove_usuario, sizeof(remove_usuario), stdin);
			remove_usuario[strlen(remove_usuario)-1]='\0';
		

			for(int i=0; i<total_cadastrados; i++) // Percorre o vetor e enquanto for diferente o cadastro selecionado registra em outro arquivo.
				if (strcmp(remove_usuario, login[i].usuario)!=0 && strcmp(login[i].usuario, "-1")!=0) {
				arquiv2 = fopen("Cadastros2.txt","a");
				CriptografaDados(login, i);
				fprintf(arquiv2, "%s\n", login[i].nome);
				fprintf(arquiv2, "%s\n", login[i].email);
				fprintf(arquiv2, "%s\n", login[i].permissao);
				fprintf(arquiv2, "%s\n", login[i].usuario);
				fprintf(arquiv2, "%s\n\n", login[i].senha);
				fclose(arquiv2);	
			} 

			for(int i=0; i<total_cadastrados; i++)
				if (strcmp(remove_usuario, login[i].usuario)==0 && i<total_cadastrados) 
					encontrado=1;

			if (encontrado==1) {
				gotoxy(60,tam+5);
				printf("Usuario deletado com sucesso!!!");
				getchar();
			} else {
				gotoxy(60,tam+5);
				printf("\aUsuario nao encontrado!!!");
				getchar();
			}

			remove("Cadastros.txt"); // Apaga o arquivo original e renomeia o novo arquivo.
			rename("Cadastros2.txt", "Cadastros.txt");
		
			if (strcmp(remove_usuario, login[codig].usuario)==0) { //Caso um usuário exclua ele próprio o sistema sai.
				exit(0);
			}
		} else if (opcao!=1 && opcao!=2){
			gotoxy(60, 6);
			printf("\aOpcao invalida!");
			getchar();
			getchar();
		}
	} while(opcao!=2);

}

void DescriptografaDados(Login login[], int i) {

	int CHAVE=3;

	for(int h=10; h>0; h--) { // Realiza o processo inverso da criptografia.
		for(int j=0; j<strlen(login[i].nome); j++) 
			login[i].nome[j]-=CHAVE;

		for(int j=0; j<strlen(login[i].email); j++)
			login[i].email[j]-=CHAVE;

		for(int j=0; j<strlen(login[i].permissao); j++)
			login[i].permissao[j]-=CHAVE;

		for(int j=0; j<strlen(login[i].usuario); j++)
			login[i].usuario[j]-=CHAVE;
	
		for(int j=0; j<strlen(login[i].senha); j++)
			login[i].senha[j]-=CHAVE;
	}
}

void ImportarCadastros(FILE *arquiv, Login login[]) {

	int i=-1;

	total_cadastrados=0;	
	for(int i=0; i<TAM_USUARIOS; i++)
		strcpy(login[i].usuario, "-1");
		
	if ((arquiv = fopen("Cadastros.txt","r"))==NULL) {
	
	} else {
		while(!feof(arquiv)) {
			i++;
			fgets(login[i].nome, sizeof(login[i].nome), arquiv);
			login[i].nome[strlen(login[i].nome)-1]='\0';
			fscanf(arquiv, "\n");

			fgets(login[i].email, sizeof(login[i].email), arquiv);
			login[i].email[strlen(login[i].email)-1]='\0';
			fscanf(arquiv, "\n");

			fgets(login[i].permissao, sizeof(login[i].permissao), arquiv);
			login[i].permissao[strlen(login[i].permissao)-1]='\0';
			fscanf(arquiv, "\n");

			fgets(login[i].usuario, sizeof(login[i].usuario), arquiv);
			login[i].usuario[strlen(login[i].usuario)-1]='\0';
			fscanf(arquiv, "\n");

			fgets(login[i].senha, sizeof(login[i].senha), arquiv);
			login[i].senha[strlen(login[i].senha)-1]='\0';
			fscanf(arquiv, "\n\n");
			DescriptografaDados(login, i);
			
			if (strcmp(login[i].usuario, "-1")!=0) // A cada chamada da função zera a variável, e soma novamente a quantidade de cadastros.
				total_cadastrados++; 
		}
		fclose(arquiv);
	}
}

int Entrar(FILE *arquiv, Login login[]) {

	char entra_usuario[31], entra_senha[16];
	int liberado = 0, i;
	
	ImportarCadastros(arquiv, login);
	Administrador();

	MenuEntra();
	
	gotoxy(82,17);
	setbuf(stdin, NULL);
	fgets(entra_usuario, sizeof(entra_usuario), stdin);
	entra_usuario[strlen(entra_usuario)-1]='\0';

	gotoxy(80,22);	
	setbuf(stdin, NULL);
	fgets(entra_senha, sizeof(entra_senha), stdin);
	entra_senha[strlen(entra_senha)-1]='\0';
	
	if (strcmp(entra_usuario, admin_usuario)==0 && strcmp(entra_senha, admin_senha)==0)
		return -2;

	for(i=0; i<TAM_USUARIOS && liberado==0; i++) // Percorre o vetor, e testa se os dados do usuário estão cadastrados.
		if (strcmp(entra_usuario, login[i].usuario)==0 && strcmp(entra_senha, login[i].senha)==0)
			liberado = 1;

	return (liberado==1)? --i:-1;
}

void CriptografaDados(Login login[], int i) {

	int CHAVE=3;

	for(int h=0; h<10; h++) { // Repete o processo dez vezes.
		for(int j=0; j<strlen(login[i].nome); j++) 
			login[i].nome[j]+=CHAVE; // Soma chave = "N" letras no caractere contido no vetor.

		for(int j=0; j<strlen(login[i].email); j++)
			login[i].email[j]+=CHAVE;

		for(int j=0; j<strlen(login[i].permissao); j++)
			login[i].permissao[j]+=CHAVE;

		for(int j=0; j<strlen(login[i].usuario); j++)
			login[i].usuario[j]+=CHAVE;
	
		for(int j=0; j<strlen(login[i].senha); j++)
			login[i].senha[j]+=CHAVE;
	}
}

int UsuariosDuplicados(FILE *arquiv, Login login[], int i) {
		
	return 0;
}

void ConfirmaCadastro(FILE *arquiv, Login login[], int i) {

	int tentativas=3;

	do {
		gotoxy(20,31);
		printf("%i Tentativas restantes. \n\n", tentativas);
		gotoxy(37,29);
		setbuf(stdin, NULL);
		fgets(login[i].senha_admin, sizeof(login[i].senha_admin), stdin);
		login[i].senha_admin[strlen(login[i].senha_admin)-1]='\0';
			
		if (strcmp(login[i].senha_admin,admin_senha)!=0) {
			gotoxy(20,33);
			printf("\aSenha de administrador invalido, repita novamente! \n");
			tentativas--; // A cada tentativa inválida, subtrai um.
		}

	} while(strcmp(login[i].senha_admin,admin_senha)!=0 && tentativas>0); // Sai do looping se tentativas for excedidas ou dados forem válidos.

	if (tentativas==0) {
		gotoxy(20,31);
		printf("%i Tentativas restantes. \n\n", tentativas);
	}

	if (UsuariosDuplicados(arquiv, login, i)==0) {
		if (strcmp(login[i].senha_admin, admin_senha)==0) { // Se dados forem válidos registra dados no arquivo.
			CriptografaDados(login, i); // Criptografa dados utilizando a cifra de César.
			FormatoArquivos(arquiv, login, i);
			MenuCadastroSucesso();
		}
	} else
		printf("\aUsuarios Duplicados!");
}

void CadastroUsuarios(FILE *arquiv, Login login[]) {

	int i=-1, op;

	MenuCadastroUsuarios();
	gotoxy(109,32);
	scanf("%i", &op);

	if (op==1) {

   		do {
			ImportarCadastros(arquiv, login);
			if ((arquiv = fopen("Cadastros.txt","a"))==NULL)
				printf("\aErro ao abrir o arquivo!");
			else {
				i++;
				system("cls");
				MenuCadastroUsuarios();
			
					gotoxy(37,13);
					setbuf(stdin, NULL);
					fgets(login[i].nome, sizeof(login[i].nome), stdin);
					login[i].nome[strlen(login[i].nome)-1]='\0';
			
					gotoxy(110,13);
					setbuf(stdin, NULL);
					fgets(login[i].email, sizeof(login[i].email), stdin);
					login[i].email[strlen(login[i].email)-1]='\0';
			
					gotoxy(33,18);
					setbuf(stdin, NULL);
					fgets(login[i].permissao, sizeof(login[i].permissao), stdin);
					login[i].permissao[strlen(login[i].permissao)-1]='\0';

					gotoxy(119,18);			
					setbuf(stdin, NULL);
					fgets(login[i].usuario, sizeof(login[i].usuario), stdin);
					login[i].usuario[strlen(login[i].usuario)-1]='\0';
			
					// Inseri senhas e Verifica.
				
					do {
						gotoxy(40,23);
						setbuf(stdin, NULL);
						fgets(login[i].senha, sizeof(login[i].senha), stdin);
						login[i].senha[strlen(login[i].senha)-1]='\0';
	
						gotoxy(118,23);
						setbuf(stdin, NULL);
						fgets(login[i].confirm_senha, sizeof(login[i].confirm_senha), stdin);
						login[i].confirm_senha[strlen(login[i].confirm_senha)-1]='\0';
					
						if (strcmp(login[i].senha, login[i].confirm_senha)!=0) {
							gotoxy(20,26);				
							printf("\aSenhas diferentes, confirmacao de senhas nao confere! \n");
						}

					} while(strcmp(login[i].senha, login[i].confirm_senha)!=0);
					
					ConfirmaCadastro(arquiv, login, i);
					
					gotoxy(109,32);
					scanf("%i", &op);
					fclose(arquiv);			
			}
		} while(op!=0);
	}
}
