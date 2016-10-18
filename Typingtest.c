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
int submenu5();
void testdisplay(char);
void print_time(time_t start_t, time_t end_t, int counter, int words);
void highscores(float wpm);

int main() {
	int key = 0;
	char choice, choice1; 
	initscr();
	while(1) {
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
				key = submenu5();
				break;
		}
		if(key == 1)
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
	mvprintw((l - 13) / 2, (b - 40) / 2, "2: Typing tutorials:");
	mvprintw((l - 11) / 2, (b - 40) / 2, "3: Highscores:");
	mvprintw((l - 9) / 2, (b - 40) / 2, "4: Rules:");
	mvprintw((l - 7) / 2, (b - 40) / 2, "5: Exit:");
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
	mvprintw((l - 18) / 2, (b - 40) / 2, "2: Touch Typing:");
	mvprintw((l - 16) / 2, (b - 40) / 2, "3: Information technology:");
	mvprintw((l - 14) / 2, (b - 40) / 2, "4: IMDb:");
	mvprintw((l - 12) / 2, (b - 40) / 2, "5: Aesop's Fables:");
	mvprintw((l - 10) / 2, (b - 40) / 2, "6: Open Source Softwares:");
	mvprintw((l - 8) / 2, (b - 40) / 2, "7: Android OS:");
	mvprintw((l - 6) / 2, (b - 40) / 2, "8: Matrix:");
	mvprintw((l - 4) / 2, (b - 40) / 2, "9: Barrel Roll(Small Test):");
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
		if(option > '9' || option < '1') {
			mvprintw(l - 3, 3, "Wrong input, please select from 0 - 9 for choices");
			refresh();
		}
		else
			break;
	}
	return option;
}

void submenu2() {
	int l, b;
	clear();
	getmaxyx(stdscr, l, b);
	box(stdscr, 0, 0);
/*      mvprintw((l - 20) / 2, (b - 40) / 2, "Please provide address of the file you wish to practice on: ");
	getstr(a);
	FILE *fp;
	fp = fopen(a, "r");
	clear();
	box(stdscr, 0, 0);
	move(1, 5);
	if(fp == NULL) {
		printw("Error: File not found, the program now will exit");
		getch();
		return;
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
*/
	mvprintw((l - 20) / 2, (b - 40) / 2, "Currently on Work!");
	getch();
	return;
}

void submenu3() {
	int l, b, j = 0;
	clear();
	getmaxyx(stdscr, l, b);
	box(stdscr, 0, 0);
	move(1, 5);
	FILE *fp;
	fp = fopen("./Highscores.txt", "r");
	if(fp == NULL) {
		mvprintw((l - 20) / 2, (b - 40) / 2, "Error: File not found, the program now will exit");
		getch();
		return;
	}
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	attron(A_BOLD);
	attron(A_REVERSE);
	mvprintw((l - 20) / 2, (b - 38) / 2, "**Highscores**");
	attroff(A_REVERSE);	
	mvprintw((l - 15) / 2, (b - 46) / 2, "Name");
	mvprintw((l - 15) / 2, (b - 20) / 2, "Speed");
	attroff(A_BOLD);
	attroff(COLOR_PAIR(1));
	char name[20];
	float speed;
	attron(COLOR_PAIR(2));
	while(fscanf(fp, "%s %f", name, &speed) != EOF) {
		mvprintw(((l - 15) / 2) + 3 + j, (b - 46) / 2, "%s", name);
		mvprintw(((l - 15) / 2) + 3 + j, (b - 20) / 2, "%f", speed);
		j = j + 2;
	}
	attroff(COLOR_PAIR(2));
	getch();
	refresh();
}

void submenu4() {
	char c;
	int l, b;
	clear();
	getmaxyx(stdscr, l, b);
	box(stdscr, 0, 0);
	move(3, 10);
	FILE *fp;
	fp = fopen("./Rules.txt", "r");
	if(fp == NULL) {
		mvprintw((l - 20) / 2, (b - 40) / 2, "Error: File not found, the program now will exit");
		getch();
		return;
	}
	while(fread(&c, 1, 1, fp)) {
		addch(c);
	}
	fclose(fp);
	getch();
	refresh();
}

int submenu5() {
	start_color();
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	move(LINES - 3, 3);
	clrtoeol();
	mvprintw(LINES - 3, 3, "Are you sure(y/n)");
	attroff(COLOR_PAIR(2));
	char op = getch();
	if(op == 'y' || op == 'Y') 
		return 1;
	else if(op == 'n' || op == 'N') 
		return 0;
	else
		submenu5();
}

void testdisplay(char choice1) {
	char a;
	char c;
	time_t start_t, end_t;
	FILE* fp;
	clear();
	int l, b, i = 0, j = 2, count = 0, stat = 0, counter = 0, words = 1;
	getmaxyx(stdscr, l, b);
	box(stdscr, 0, 0);
	move(3, 10);
	switch(choice1) {
		case '1':
			fp = fopen("./Computer technology.txt", "r");
			break;
		case '2':
			fp = fopen("./Touch typing.txt", "r");
			break;
		case '3':
			fp = fopen("./Information technology.txt", "r");
			break;
		case '4':
			fp = fopen("./IMDb.txt", "r");
			break;
		case '5':
			fp = fopen("./Aesop's Fables.txt", "r");
			break;
		case '6':
			fp = fopen("./Open Source Softwares.txt", "r");
			break;
		case '7':
			fp = fopen("./Android OS.txt", "r");
			break;
		case '8':
			fp = fopen("./Matrix.txt", "r");
			break;
		case '9':
			fp = fopen("./Barrel Roll.txt", "r");
			break;
		}
	if(fp == NULL) {
		printw("Error: File not found, the program now will exit");
		getch();
		return;
	}
	while(fread(&c, 1, 1, fp)) {
		if(i == (b - 30)) {
			move(4 + j, 10);
			j = j + 3;
			i = 0;
		}	
		addch(c);
		i++;
	}
	fseek(fp, 0, SEEK_SET);
	echo();
	i = 10;
	j = 4;
	attron(A_BOLD);
	time(&start_t);
	while(fread(&a, 1, 1, fp)) {
		if(i == (b - 20)) {
			move(4 + j, 10);
			j = j + 3;
			i = 10;
		}
		move(j, i);
		c = getch();	
		i++;
		if(c != a) {
			count++;
			stat = 1;
		}
		if(a == ' ') {
			if(stat == 1) {
				counter++;
				stat = 0;
			}
			words++;
		}
	}
	if(stat == 1)
		counter++;
	words++;
	time(&end_t);
	print_time(start_t, end_t, counter, words);
	attroff(A_BOLD);
	noecho();
	fclose(fp);
	getch();
	refresh();
	stat = l;
	return;
}

void print_time(time_t start_t, time_t end_t, int counter, int words) {
	long int diff;
	int hr , min, sec;
	float wpm, awpm;

	diff = end_t - start_t;
	wpm = (words / (double)diff) * 60;
	awpm = ((words - counter) / (double)diff) * 60;

	hr = (int)(diff / 3600);
   	diff = diff - hr * 3600;
	min = (int)(diff / 60);
	diff = diff - min * 60;
	sec = (int)diff; 
	
	attron(A_REVERSE);
	mvprintw(LINES - 3, 3, "Errors:- %d time taken:- %d:%d:%d WPM:- %.2f Raw WPM:- %.2f    Press any Key to continue", counter, hr, min, sec, awpm, wpm);
	attroff(A_REVERSE);

	refresh();
	getch();
	highscores(awpm);
}

void highscores(float awpm) {
	int i, status = -1, count = 0, l, b;
	float speed[5];
	char name[5][20];
	getmaxyx(stdscr, l, b);
	clear();
	FILE *fp;
	fp = fopen("./Highscores.txt", "r");
	if(fp == NULL) {
		return;
	}
	for(i = 0; i < 5; i++) {
		fscanf(fp, "%s %f", name[i], &speed[i]);
		if(speed[i] <= awpm)  
			count++;
	}
	status = status + (6 - count);
	if(status != 5) {
		mvprintw((l - 24) / 2, (b - 40) / 2, "Congratulations, You just made a highscore!");
		mvprintw((l - 20) / 2, (b - 24) / 2, "Please enter your name");
		for(i = 4; i > status; i--) {
			strcpy(name[i], name[i - 1]);
			speed[i] = speed[i - 1];
		}
		echo();
		mvscanw((l - 16) / 2, (b - 16) / 2, "%s", name[status]);
		speed[status] = awpm;
		fclose(fp);
		fp = fopen("./Highscores.txt", "w");
		for(i = 0; i < 5; i++)
			fprintf(fp, "%s %f\n", name[i], speed[i]);
	}
	else {
		mvprintw((l - 24) / 2, (b - 40) / 2, "Sorry you were unable to beat the Highscore!");
	}
	fclose(fp);
	submenu3();
}
