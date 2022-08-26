#ifndef  SISTEMA_DE_LOGIN_H
#define  SISTEMA_DE_LOGIN_H

	// Bibliotecas	

#include <stdio.h>
#include <string.h>

	// Constantes

#define TAM_USUARIOS 10000000

	// Registros

struct Login {
	char usuario[31], senha[16], confirm_senha[16], senha_admin[16];
	char nome[51], email[51], permissao[16];
} typedef Login;

	// Protótipos

void Administrador();
void Versao();
void FormatoCadastros();
void FormatoArquivos(FILE *arquiv, Login login[], int i);
void PesquisarCadastros(FILE *arquiv, Login login[]);
void ImprimeCadastros(FILE *arquiv, Login login[]);
void OrdenaCadastrosUsuarios(Login login[]);
void OrdenaCadastrosUsuariosContrario(Login login[]);
void ExportarCadastros(FILE *arquiv, Login login[]);
void EditarCadastros(FILE *arquiv, Login login[]);
void ApagarCadastros(FILE *arquiv, Login login[]);
int Entrar(FILE *arquiv, Login login[]);
void DescriptografaDados(Login login[], int i);
void ImportarCadastros(FILE *arquiv, Login login[]);
void CriptografaDados(Login login[], int i);
int UsuariosDuplicados(FILE *arquiv, Login login[], int i);
void ConfirmaCadastro(FILE *arquiv, Login login[], int i);
void CadastroUsuarios(FILE *arquiv, Login login[]);

	// Variáveis

Login login[TAM_USUARIOS];
FILE *arquiv;
int total_cadastrados;
char admin_usuario[16], admin_senha[16];

#endif
