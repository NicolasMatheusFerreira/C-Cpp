#include <stdio.h>
#include <conio.h>
#include "Sistema de login.h"
#include "Interface.h"

int op;

void Principal() {
	// Aqui chama seu programa principal.
}

void Construtor() {
	do {	
		system("cls");
		if ((codig = Entrar(arquiv, login))!=-1) {
			ImportarCadastros(arquiv, login);

			if (strcmp(login[codig].permissao, "Admin")==0 || codig==-2) {
				do {
					ImportarCadastros(arquiv, login);
					MenuLoginAdmin();
					scanf("%i", &op);
					
					switch(op) {
						case 1:
							system("cls");
							CadastroUsuarios(arquiv, login);					
						break;	
		
						case 2:
							system("cls");
							EditarCadastros(arquiv, login);
						break;	
				
						case 3:
							system("cls");
							ApagarCadastros(arquiv, login);
						break;	
				
						case 4:
							system("cls");
							ImprimeCadastros(arquiv, login);
							getchar();
						break;	
				
						case 5:
							system("cls");
							PesquisarCadastros(arquiv, login);
							getchar();
						break;	

						case 6:
							Construtor();
							exit(0);
						break;

						case 7:
							system("cls");
							Versao();
							getchar();
						break;
					}

					if (op>8) {
						gotoxy(60,39);
						printf("\aOpcao invalida, Informe novamente!");
						getchar();
						getchar();
					}
				} while(op!=8);				
			} else {
				gotoxy(68,30);
				printf("Bem-Vindo!!! %s", login[codig].nome);
				gotoxy(68,31);
				Main();
				Principal();

				getchar();
				getchar();
			}
		} else {
			gotoxy(70,28);
			printf("\aOps, usuario ou senha invalida! \n");
			getchar();
			getchar();
		}
	} while(op!=8);
}

int main(void) {		

	Loading();
	Construtor();
	
}