#include "Graficos.h"

void setTema(int codig_tema) {
	
	start_color(); // Função que torna possível o uso das cores no CLI;
	
	init_pair(1,COLOR_BLACK,COLOR_WHITE); // Id, fonte, background;
	init_pair(2,COLOR_WHITE,COLOR_BLACK); 

	bkgd(COLOR_PAIR(codig_tema));
}

void MenuBar() {
	
	int yMax, xMax;

	getmaxyx(stdscr, yMax, xMax);
	WINDOW *win = newwin(yMax/2, xMax/2, yMax/4, xMax/4);

	box(win, 0, 0);
		

	wgetch(win);	
	wrefresh(win);

	endwin();
}

