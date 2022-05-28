#include "Interface.h"
#include "Sistema de login.h"


void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void Loading() {

   int i, j;
   
   system ("cls");
   
   gotoxy(70,16);
   printf ("\n\nCarregando: \n\n");          
     
   for (i = 0; i <= 50; i++) {
	      printf ("  %d%%\r", i*2);
      fflush (stdout);                      
         
      for (j = 0; j < i; j++) {
         if (!j) 
           printf ("  ");
         printf ("%c", 219);
         Sleep(1);
      }                      
   } 
          
   printf ("\n\nIniciando...");
   Sleep (2000);
	
}

void MenuFormatoUsuarios(int i, int y) {
	gotoxy(10, y);
	printf(" _____________________________________________________________________________________________________________________________________________________");
	gotoxy(10, y+1);
	printf("|");
	gotoxy(160, y+1);
	printf("|");
	gotoxy(6, y+2);
	printf("%i", i+1);
	gotoxy(10, y+2);
	printf("| Nome: %s - E-mail: %s - Permissao: %s - Usuario: %s - Senha: %s", login[i].nome, login[i].email, login[i].permissao, login[i].usuario, login
[i].senha);
	gotoxy(160, y+2);
	printf("|");
	gotoxy(10, y+3);
	printf("|_____________________________________________________________________________________________________________________________________________________|");
}

void MenuVersao() {

	gotoxy(78,5);
		printf("# Versao #\n\n");
	gotoxy(80,10);
		printf("1.8.0 \n");
	gotoxy(75,11);
		printf("All rights reserved \n");
	gotoxy(65,12);
		printf("copyright Nicolas Matheus Ferreira %c 2020", 184);
}
void MenuEditar() {

	gotoxy(60,10);
	printf("Editar. . .");
	gotoxy(60,11);
	printf(" _______________________________________________________ \n");
	gotoxy(60,12);
	printf("|                                                       |\n");
	gotoxy(60,13);
	printf("|         (1). Nome de registro                         |\n");
	gotoxy(60,14);
	printf("|_______________________________________________________|\n");
	gotoxy(60,15);
	printf("|                                                       |\n");
	gotoxy(60,16);
	printf("|         (2). E-mail                                   |\n");
	gotoxy(60,17);
	printf("|_______________________________________________________|\n");
	gotoxy(60,18);
	printf("|                                                       |\n");
	gotoxy(60,19);
	printf("|         (3). Permissao                                |\n");
	gotoxy(60,20);
	printf("|_______________________________________________________|\n");
	gotoxy(60,21);
	printf("|                                                       |\n");
	gotoxy(60,22);
	printf("|         (4). Usuario                                  |\n");
	gotoxy(60,23);
	printf("|_______________________________________________________|\n");
	gotoxy(60,24);
	printf("|                                                       |\n");
	gotoxy(60,25);
	printf("|         (5). Senha                                    |\n");
	gotoxy(60,26);
	printf("|_______________________________________________________|\n");
	gotoxy(60,27);
	printf("|                                                       |\n");
	gotoxy(60,28);
	printf("|         (6). Voltar                                   |\n");
	gotoxy(60,29);
	printf("|_______________________________________________________|\n");

	gotoxy(60,31);
	printf("    _________________________________________________  \n");
	gotoxy(60,32);
	printf("   /                                                 \\  \n");
	gotoxy(60,33);
	printf("  /       Editar:                                     \\  \n");
	gotoxy(60,34);
	printf(" /_____________________________________________________\\");
}

void MenuLoginAdmin() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

    /* Salvar estado atual */    
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;

	system("cls");
	SetConsoleTextAttribute(hConsole, 6);
	
	gotoxy(60,5);
	printf(">>> Bem-Vindo, %s <<<\n\n \t\t\t\t\t\t\t\t%d\n\n", login[codig].nome, rand()%10);

	SetConsoleTextAttribute(hConsole, 3);
			
	gotoxy(60,11);
	printf(" _______________________________________________________ \n");
	gotoxy(60,12);
	printf("|                                                       |\n");
	gotoxy(60,13);
	printf("|         (1). Cadastro de usuarios                     |\n");
	gotoxy(60,14);
	printf("|_______________________________________________________|\n");
	gotoxy(60,15);
	printf("|                                                       |\n");
	gotoxy(60,16);
	printf("|         (2). Editar usuarios                          |\n");
	gotoxy(60,17);
	printf("|_______________________________________________________|\n");
	gotoxy(60,18);
	printf("|                                                       |\n");
	gotoxy(60,19);
	printf("|         (3). Apagar usuarios                          |\n");
	gotoxy(60,20);
	printf("|_______________________________________________________|\n");
	gotoxy(60,21);
	printf("|                                                       |\n");
	gotoxy(60,22);
	printf("|         (4). Exibir usuarios                          |\n");
	gotoxy(60,23);
	printf("|_______________________________________________________|\n");
	gotoxy(60,24);
	printf("|                                                       |\n");
	gotoxy(60,25);
	printf("|         (5). Pesquisar usuarios                       |\n");
	gotoxy(60,26);
	printf("|_______________________________________________________|\n");
	gotoxy(60,27);
	printf("|                                                       |\n");
	gotoxy(60,28);
	printf("|         (6). Relogar usuario                          |\n");
	gotoxy(60,29);
	printf("|_______________________________________________________|\n");
	gotoxy(60,31);
	printf("    _________________________________________________  \n");
	gotoxy(60,32);
	printf("   /                                                 \\  \n");
	gotoxy(60,33);
	printf("  /       (7). Versao                 (8). Sair       \\  \n");
	gotoxy(60,34);
	printf(" /_____________________________________________________\\");
			
	SetConsoleTextAttribute(hConsole, saved_attributes);
	gotoxy(60,37);
	printf("Opcao: ");
}

void MenuEntra() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

    /* Salvar estado atual */    
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;

	SetConsoleTextAttribute(hConsole, 2);
	gotoxy(77,10);
	printf(">>> Sistema de login <<<");	

	SetConsoleTextAttribute(hConsole, 1);	
	gotoxy(68,15);
	printf(" ____________________________________");
	gotoxy(68,16);
	printf("|                                    |");
	gotoxy(68,17);
	printf("|  + Usuario:                        |");
	gotoxy(68,18);
	printf("|____________________________________|");

	gotoxy(68,20);
	printf(" ____________________________________");
	gotoxy(68,21);
	printf("|                                    |");
	gotoxy(68,22);
	printf("|  + Senha:                          |");
	gotoxy(68,23);
	printf("|____________________________________|");

	gotoxy(80,26);
	printf("<Enter> Entrar");
	

	SetConsoleTextAttribute(hConsole,  7);
}

void MenuDecisao(int x, int y) {
	gotoxy(x,y);
	printf(" _______________________________________");
	gotoxy(x,y+1);
	printf("|                                       |");
	gotoxy(x,y+2);
	printf("| (1). Para continuar ou (0). Para sair |");
	gotoxy(x,y+3);
	printf("| Opcao:                                |");
	gotoxy(x,y+4);
	printf("|_______________________________________|");
}
void MenuCadastroUsuarios() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

    /* Salvar estado atual */    
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	SetConsoleTextAttribute(hConsole, 2);

	gotoxy(80,1);
	printf("Cadastrar Usuarios");

	SetConsoleTextAttribute(hConsole, 6);
	gotoxy(74,8);
	printf("Total de usuarios cadastrados: %i \n\n", total_cadastrados);

	gotoxy(20,11);
	printf(" __________________________________________________________");	
	gotoxy(20,12);
	printf("|                                                          |");
	gotoxy(20,13);
	printf("| Nome completo:                                           |");
	gotoxy(20,14);
	printf("|__________________________________________________________|");
	gotoxy(100,11);
	printf(" __________________________________________________________");	
	gotoxy(100,12);
	printf("|                                                          |");
	gotoxy(100,13);
	printf("| E-mail:                                                  |");
	gotoxy(100,14);
	printf("|__________________________________________________________|");
	gotoxy(20,16);
	printf(" __________________________________________________________");	
	gotoxy(20,17);
	printf("|                                                          |");
	gotoxy(20,18);
	printf("| Permissao:                                               |");
	gotoxy(20,19);
	printf("|__________________________________________________________|");
	gotoxy(100,16);
	printf(" __________________________________________________________");	
	gotoxy(100,17);
	printf("|                                                          |");
	gotoxy(100,18);
	printf("| Nome de usuario:                                         |");
	gotoxy(100,19);
	printf("|__________________________________________________________|");
	gotoxy(20,21);
	printf(" __________________________________________________________");	
	gotoxy(20,22);
	printf("|                                                          |");
	gotoxy(20,23);
	printf("| Senha do usuario:                                        |");
	gotoxy(20,24);
	printf("|__________________________________________________________|");
	gotoxy(100,21);
	printf(" __________________________________________________________");	
	gotoxy(100,22);
	printf("|                                                          |");
	gotoxy(100,23);
	printf("| Confirme senha:                                          |");
	gotoxy(100,24);
	printf("|__________________________________________________________|");

	SetConsoleTextAttribute(hConsole, 7);
	gotoxy(20,29);
	printf("Senha do Admin.: ");

	MenuDecisao(100,29);
}

void MenuCadastroSucesso() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

    /* Salvar estado atual */    
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	
	SetConsoleTextAttribute(hConsole, 2);

	gotoxy(20,31);
	printf(" __________________________________________________________");
	gotoxy(20,32);
	printf("|                                                          |");
	gotoxy(20,33);
	printf("| Usuario cadastrado com sucesso!                          |");
	gotoxy(20,34);
	printf("|__________________________________________________________|");

	SetConsoleTextAttribute(hConsole, 7);
}
