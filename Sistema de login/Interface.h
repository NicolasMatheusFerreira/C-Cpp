#ifndef  INTERFACE_H
#define  INTERFACE_H

	// Bibliotecas	

#include <stdio.h>
#include <windows.h>

	// Protótipos

void Loading();
void MenuEntra();
void MenuLoginAdmin();
void MenuEditar();
void MenuVersao();
void MenuFormatoUsuarios(int i, int y);
void MenuDecisao(int x, int y);
void MenuCadastroSucesso();
void MenuCadastroUsuarios();
void gotoxy(int x, int y);

	// Variáveis

int codig;

#endif

