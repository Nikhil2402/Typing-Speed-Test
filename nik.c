#include<ncurses.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char menu();
char submenu1();
void submenu2();
void submenu3();
void submenu4();
void submenu5();
void testdisplay(char);

int main() {
	int l, b;
	char choice, choice1; 
	getmaxyx(stdscr, l, b);
	initscr();
	choice = menu();
	switch(choice) {
		case '1':
			choice1 = submenu1();
			testdisplay(choice1);
			break;
		case '2':
			submenu2();
			break;
		case '3':
			submenu3();
			break;
		case '4':
			submenu4();
			break;
		case '5':
			submenu5();
			break;
	} 
	endwin();
	return 0;
}

char menu() {
	int l, b; 
	char choice;
	clear();
	getmaxyx(stdscr, l, b);
	box(stdscr, 0, 0);
	start_color();
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	attron(A_BOLD);
	attron(COLOR_PAIR(2));
	mvprintw((l - 20) / 2, (b - 40) / 2, "*** Welcome to typing speed test ***");
	attroff(A_BOLD);
	attroff(COLOR_PAIR(2));
	mvprintw((l - 15) / 2, (b - 40) / 2, "1: Choose  a topic to start the test:");
	mvprintw((l - 13) / 2, (b - 40) / 2, "2: Choose  a topic of your own:");
	mvprintw((l - 11) / 2, (b - 40) / 2, "3: Highscores:");
	mvprintw((l - 9) / 2, (b - 40) / 2, "4: Help");
	mvprintw((l - 7) / 2, (b - 40) / 2, "5: Exit");
	cbreak();
	noecho();
	attron(COLOR_PAIR(2));
	mvprintw(LINES - 3, 3, "Use indicated keys to choose the options");
	attroff(COLOR_PAIR(2));
	while(1) {
		choice = getch();
		if(choice > '5' || choice < '1') {
			mvprintw(LINES - 3, 3, "Wrong input, please select from 1 - 5 for choices");
		}
		else
			break;
	}
	return choice;
}

char submenu1() {
	int l, b;
	char option;
	clear();
	getmaxyx(stdscr, l, b);
	box(stdscr, 0, 0);
	mvprintw((l - 20) / 2, (b - 40) / 2, "1: Computer technology");
	mvprintw((l - 18) / 2, (b - 40) / 2, "2: under development:");
	mvprintw((l - 16) / 2, (b - 40) / 2, "3: under development:");
	mvprintw((l - 14) / 2, (b - 40) / 2, "4: under development:");
	mvprintw((l - 12) / 2, (b - 40) / 2, "5: under development");
	mvprintw((l - 10) / 2, (b - 40) / 2, "6: under development");
	mvprintw((l - 8) / 2, (b - 40) / 2, "7: under development:");
	mvprintw((l - 6) / 2, (b - 40) / 2, "8: under development:");
	mvprintw((l - 4) / 2, (b - 40) / 2, "9: under development");
	mvprintw((l - 2) / 2, (b - 40) / 2, "0: under development");
	cbreak();
	noecho();
	start_color();
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	mvprintw(LINES - 3, 3, "Use indicated keys to choose the options");
	attroff(COLOR_PAIR(2));
	refresh();
	while(1) {
		option = getchar();
		if(option > '9' || option < '0') {
			mvprintw(l - 3, 3, "Wrong input, please select from 0 - 9 for choices");
			refresh();
		}
		else
			break;
	}
	return option;
}

void submenu2() {
	char a[100], c;
	int l, b, i = 0, j = 2;
	clear();
	getmaxyx(stdscr, l, b);
	box(stdscr, 0, 0);
	mvprintw((l - 20) / 2, (b - 40) / 2, "Please provide address of the file you wish to practice on: ");
	getstr(a);
	FILE *fp;
	fp = fopen(a, "r");
	clear();
	box(stdscr, 0, 0);
	move(1, 5);
	if(fp == NULL) {
		printw("Error: File not found, the program now will exit");
		//system(exit);
		getch();
	}
	while(fread(&c, 1, 1, fp)) {
		if(i == (b - 10)) {
			move(1 + j, 5);
			j = j + 2;
			i = 0;
		}	
		addch(c);
		i++;
	}
	fclose(fp);
	getch();
	refresh();
}

void submenu3() {
	char c;
	int l, b, i = 0, j = 2;
	clear();
	getmaxyx(stdscr, l, b);
	box(stdscr, 0, 0);
	move(1, 5);
	FILE *fp;
	fp = fopen("./Highscores.txt", "r");
	if(fp == NULL) {
		mvprintw((l - 20) / 2, (b - 40) / 2, "Error: File not found, the program now will exit");
		//system(exit);
		getch();
	}
	while(fread(&c, 1, 1, fp)) {
		if(i == (b - 10)) {
			move(1 + j, 5);
			j = j + 2;
			i = 0;
		}	
		addch(c);
		i++;
	}
	fclose(fp);
	getch();
	refresh();
}

void submenu4() {
	char c;
	int l, b, i = 0, j = 2;
	clear();
	getmaxyx(stdscr, l, b);
	box(stdscr, 0, 0);
	move(1, 5);
	FILE *fp;
	fp = fopen("./Help.txt", "r");
	if(fp == NULL) {
		mvprintw((l - 20) / 2, (b - 40) / 2, "Error: File not found, the program now will exit");
		//system(exit);
		getch();
	}
	while(fread(&c, 1, 1, fp)) {
		if(i == (b - 10)) {
			move(1 + j, 5);
			j = j + 2;
			i = 0;
		}	
		addch(c);
		i++;
	}
	fclose(fp);
	getch();
	refresh();
}

void submenu5() {
	start_color();
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	move(LINES - 3, 3);
	clrtoeol();
	mvprintw(LINES - 3, 3, "Are you sure(y/n)");
	attroff(COLOR_PAIR(2));
	char op = getch();
	if(op == 'y' || op == 'Y')
		return;
	else if(op == 'n' || op == 'N') 
		;//return to main menu with a control structure;
	else
		submenu5();
}

void testdisplay(char choice1) {
	char c;
	FILE* fp;
	clear();
	int l, b, i = 0, j = 2;
	getmaxyx(stdscr, l, b);
	box(stdscr, 0, 0);
	move(1, 5);
	switch(choice1) {
		case '1':
			fp = fopen("./Computer technology.txt", "r");
			break;
		}
	if(fp == NULL) {
		printw("Error: File not found, the program now will exit");
		//system(exit);
		getch();
	}
	while(fread(&c, 1, 1, fp)) {
		if(i == (b - 10)) {
			move(1 + j, 5);
			j = j + 2;
			i = 0;
		}	
		addch(c);
		i++;
	}
	fclose(fp);
	getch();
	refresh();
	return;
}
