/****************************************************************************
* Copyright (C) Nikhil Ahirkar ahirkarnn15.it@coep.ac.in 		    *
*									    *
* This program is a free software; you can redistribute it and/or modify it *
* under the terms of the GNU Lesser General Public Licence as published by  *
* the Free Software Foundation; either version 2.1 of the Licence, or       *
* (at your option) any later version.                                       *
*									    *
* This progtam is distributed in the hope that it will be useful,	    *
* but WITHOUT ANT WARRANTY; without even the implied warranty of 	    *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 		    *
* GNU Lesser General Public Licence for more details.			    *
*									    *
* You Should have received a copy of the GNU Lesser General Public Licence  *
* along with this program; if not write to the Free Software Foundation,    *
* INC., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.        *
****************************************************************************/

#include<ncurses.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/*--------------------------Function Prototypes----------------------------*/
char main_menu();
char test();
void test_display(char);
float print_time(time_t start_t, time_t end_t, int, int);
void change_highscores(float);
char tutorial();
void tutorial_display(char *, char);
void display_highscores();
void reset_highscores();
void display_rules();
int end_program();

/*-----------------------------------main----------------------------------*/
int main() {
	char choice, choice1; 
	initscr(); /* initializing window */
	char *test_array;
	test_array = NULL; /* initializing char* */
	int key = 0; /* a variable to exit the program */
	while(1) {
		choice = main_menu(); /* main_menu() returns selected option */
		switch(choice) { 
			case '1': /* in case 1, typing test submenu is selected */
				choice1 = test(); 
				if(choice1 == '0')
					break;
				test_display(choice1);
				break;
			case '2': /* in case 2, tutorial submenu is selected */
				choice1 = tutorial();
				if(choice1 == '8')
					break;
				tutorial_display(test_array, choice1);
				break;
			case '3': /* in case 3, Highscores are displayed */
				display_highscores();
				break;
			case '4': /* in case 4, Rules are displayed */
				display_rules();
				break;
			case '5': /* in case 5, Highscores can be reset */
				reset_highscores();
				break;
			case '6': /* in case 6, The program can exit */
				key = end_program(); /* if end_program returns 1, program exits */
				break;
		}
		if(key == 1)
			break;
	} 
	endwin(); /* End Window */
	return 0;
}

/*-------------------------------------------main menu-----------------------------------------*/
/* main_menu() displays the menu of the Program. main_menu() returns the choice selected by the user in char*/
char main_menu() {
	int l, b; 
	char choice;
	clear(); /*  to clear the window */
	getmaxyx(stdscr, l, b); /* to get maximum resolution of the current window */
	box(stdscr, 0, 0); /* to create borders */
	start_color(); 
	init_pair(1, COLOR_CYAN, COLOR_BLACK); /* initializing pair 1 as Cyan and Black combination */
	attron(A_BOLD); 
	attron(COLOR_PAIR(1));
	/* coordinates are adjusted to print message at their specific locations in the window */
	mvprintw((l - 20) / 2, (b - 40) / 2, "*** Welcome to typing speed test ***"); 
	attroff(A_BOLD);
	attroff(COLOR_PAIR(1));
	mvprintw((l - 15) / 2, (b - 40) / 2, "1: Choose  a topic to start the test:");
	mvprintw((l - 13) / 2, (b - 40) / 2, "2: Typing tutorials:");
	mvprintw((l - 11) / 2, (b - 40) / 2, "3: Highscores:");
	mvprintw((l - 9) / 2, (b - 40) / 2, "4: Rules:");
	mvprintw((l - 7) / 2, (b - 40) / 2, "5: Reset Highscores:");
	mvprintw((l - 5) / 2, (b - 40) / 2, "6: Exit:");
	refresh(); /* to update window */
	cbreak(); /* to enter cbreak mode */
	noecho(); /* to make the input invisible */
	attron(COLOR_PAIR(1));
	mvprintw(l - 3, 3, "Use indicated keys to choose the options");
	attroff(COLOR_PAIR(1));
	curs_set(0); /* to make the cursor invisible */
	init_pair(2, COLOR_RED, COLOR_BLACK); /* initializing pair 2 as Red and Black combination */
	while(1) {
		choice = getch();
		if(choice > '6' || choice < '1') { 
			attron(COLOR_PAIR(2));
			mvprintw(LINES - 3, 3, "Wrong input, please select from 1 - 5 for choices");
			attroff(COLOR_PAIR(2));
			refresh();
		}
		else
			break;
	}
	curs_set(1); /* to make the cursor visible again */
	return choice; /* returns the option selected by the user*/
}

/*--------------------------------------Typing Test Menu---------------------------------------------*/
/* test() displays the typing test menu. test() returns the topic selected by the user*/
char test() {
	int l, b;
	char option;
	clear(); /*  to clear the window */
	getmaxyx(stdscr, l, b); /* to get maximum resolution of the current window */
	box(stdscr, 0, 0); /* to create borders */
	/* coordinates are adjusted to print message at their specific locations in the window */
	mvprintw((l - 20) / 2, (b - 40) / 2, "1: Computer technology");
	mvprintw((l - 18) / 2, (b - 40) / 2, "2: Touch Typing:");
	mvprintw((l - 16) / 2, (b - 40) / 2, "3: Information technology:");
	mvprintw((l - 14) / 2, (b - 40) / 2, "4: IMDb:");
	mvprintw((l - 12) / 2, (b - 40) / 2, "5: Aesop's Fables:");
	mvprintw((l - 10) / 2, (b - 40) / 2, "6: Open Source Softwares:");
	mvprintw((l - 8) / 2, (b - 40) / 2, "7: Android OS:");
	mvprintw((l - 6) / 2, (b - 40) / 2, "8: Matrix:");
	mvprintw((l - 4) / 2, (b - 40) / 2, "9: Barrel Roll(Small Test):");
	mvprintw((l - 2) / 2, (b - 40) / 2, "0: Return Back to Main Menu:");
	refresh(); /* to update window */
	cbreak(); /* to enter cbreak mode */
	noecho(); /* to make the input invisible */
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK); /* initializing pair 1 as Cyan and Black combination */
	attron(COLOR_PAIR(1));
	mvprintw(LINES - 3, 3, "Use indicated keys to choose the options");
	attroff(COLOR_PAIR(1));
	refresh(); /* to update window */
	curs_set(0); /* to make the cursor invisible */
	while(1) {
		option = getchar();
		if(option > '9' || option < '0') {
			init_pair(2, COLOR_RED, COLOR_BLACK); /* initializing pair 2 as Red and Black combination */
			attron(COLOR_PAIR(2));
			mvprintw(l - 3, 3, "Wrong input, please select from 0 - 9 for choices");
			attroff(COLOR_PAIR(2));
			refresh(); /* to update window */
		}
		else
			break;
	}
	curs_set(1); /* to make the cursor visible again */
	return option; /* returns the topic selected by the user*/
}

/*--------------------------------------------Typing test Display-------------------------------------*/
/* test_display() displays the window where the typing test occurs*/
void test_display(char choice1) {
	char a;
	int c;
	int l, b;
	int i, r, k, j, stat, counter, words, t;
	float awpm;
	time_t start_t, end_t;
	FILE* fp;
	clear(); /*  to clear the window */
	getmaxyx(stdscr, l, b); /* to get maximum resolution of the current window */
	box(stdscr, 0, 0); /* to create borders */
	/* coordinates are adjusted to print message at their specific locations in the window */
	move(3, 10);
	/* -----opening the selected topic in reading mode----- */
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
	r = 0; /* r counts the number of characters read from the file */
	k = 0; /* k detects when to start printing characters to next line */ 
	j = 2; /* y co-ordinate of the window */
	/* -----printing the contents of the selected file----- */
	while(fread(&a, 1, 1, fp)) {
		if(k == (b - 30)) {
			move(4 + j, 10);
			j = j + 3;
			k = 0;
		}
		addch(a);
		k++;
		r++;
	}
	refresh(); /* to update window */
	move(l - 3, 3);
	attron(A_REVERSE); /* to reverse all the attributes, resulting in inverted output */
	printw("Press HOME Key to restart, END key to return back to main menu");
	attroff(A_REVERSE);
	fseek(fp, 0, SEEK_SET); /* to set fp at the start of the file */
	keypad(stdscr, TRUE);
	i = 10; /* x co-ordinate of the window */
	j = 4; /* y co-ordinate of the window */
	stat = 0; /* to detect wether a word is incorrect */
	counter = 0; /* counts no. of incorrect words */
	words = 0; /* counts total no. of words */
	t = 0; /* to start timer */
	curs_set(1); /* to make the cursor visible */
	/* -----beginning of typing test----- */
	while(r - 1) {
		r--;
		fread(&a, 1, 1, fp); /* reading a character from the file */
		if(i == (b - 20)) { /* algorithm to shift the cursor to specific locations */
			move(4 + j, 10);
			j = j + 3;
			i = 10;
		}
		move(j, i); /* to shift cursor */
		noecho(); /* to make input invisible */
		c = getch(); /* fetching a character from keyboard */
		if(t == 0) { /* timer starts running as soon as the first letter is typed */
			time(&start_t);	
			t = 1;
		}
		i++;
		if(c != a) { /* whenever the input does not match the required character */
			stat = 1; /* stat changed to 1 as the letter in a word is incorrect */
			attron(A_STANDOUT); /* inverts the colors of background and foreground */
			attron(A_BOLD);	
			printw("^"); /* '^' is an indication that the word typed is incorrect */
			attroff(A_BOLD);
			attroff(A_STANDOUT);
		}
		else /* whenever input is correct */
			printw("%c", c);
		if(a == ' ') { /* indicates the end of a word */
			if(stat == 1) { /* if the previous word was incorrect */
				counter++;
				stat = 0; /* resetting stat for the upcoming word */
			}
			words++; /* incrementing the counter for words */
		}
		if(c == KEY_END) { 
			return;
		}
		if(c == KEY_HOME) {
			test_display(choice1);
			return;
		}
	}
	if(stat == 1)
		counter++; /* counts if there was mistake in last word */
	words++; /* counts the last word */
	time(&end_t);
	t = 0;
	attron(A_BOLD);
	awpm = print_time(start_t, end_t, counter, words); /* awpm is the actual wpm */
	attroff(A_BOLD);
	fclose(fp);
	refresh(); /* to update window */
	change_highscores(awpm);
	return;
}

/*-------------------------------Time, Accuracy, WPM, Stats display--------------------------*/
/* print_time() is a function which is called within test_display(). 
 * print_time() displays the result of the test at the bottom right corner of the window 
 * print_time() returns the actual wpm */
float print_time(time_t start_t, time_t end_t, int counter, int words) {
	curs_set(0); /* to make the cursor invisible */
	long int diff;
	int hr, min, sec, l, b;
	float wpm, awpm, acc;
	int c;
	getmaxyx(stdscr, l, b); /* to get maximum resolution of the current window */
	/* -----Algorithm to calculate stats----- */	
	diff = end_t - start_t; /* counts time difference */
	wpm = (words / (double)diff) * 60;
	awpm = ((words - counter) / (double)diff) * 60;
	hr = (int)(diff / 3600);
   	diff = diff - hr * 3600;
	min = (int)(diff / 60);
	diff = diff - min * 60;
	sec = (int)diff; 
	acc = (100.00 - (counter * 100.00) / words);
	/* coordinates are adjusted to print message at their specific locations in the window */
	attron(A_REVERSE); /* to reverse all the attributes, resulting in inverted output */
	mvprintw(l - 7, b - 30, "Errors:- %d", counter);
	mvprintw(l - 6, b - 30, "time taken:- %d:%d:%d", hr, min, sec);
	mvprintw(l - 5, b - 30, "WPM:- %.2f Raw WPM:- %.2f", awpm, wpm);
	mvprintw(l - 4, b - 30, "Accuracy:- %f", acc);
	mvprintw(l - 3, b - 30, "Press END key to exit");
	attroff(A_REVERSE);
	refresh(); /* to update window */
	keypad(stdscr, TRUE); /* Entering Keypad mode */
	/* Loop to exit only when END Key is pressed */
	while(1) {	
		c = getch();
		if(c == KEY_END)
			break;
	}
	curs_set(1); /* to make the cursor visible again */
	return awpm;
}

/*-------------------------------------Changing Highscores-------------------------------*/
/* change_highscores() is called whenever the user beats previous highscore. change_highscores() updates the highscores*/
void change_highscores(float awpm) {
	int  l, b, i, status, count;
	float speed[5]; 
	char name[5][20];
	clear(); /*  to clear the window */
	getmaxyx(stdscr, l, b); /* to get maximum resolution of the current window */
	box(stdscr, 0, 0); /* to create borders */
	curs_set(0); /* to make the cursor invisible */
	FILE *fp;
	fp = fopen("./Highscores.txt", "r");
	if(fp == NULL) {
		printw("Error: File not found, the program now will exit");
		getch();
		return;
	}
	/* Algorithm to check if current score beats the previous top five scores */
	status = -1; 
	count = 0;
	for(i = 0; i < 5; i++) {
		fscanf(fp, "%s %f", name[i], &speed[i]);
		if(speed[i] <= awpm)  
			count++;
	}
	status = status + (6 - count);
	if(status != 5) { /* if current score beats the previous top five scores */
		mvprintw((l - 24) / 2, (b - 40) / 2, "Congratulations, You just made a highscore!");
		mvprintw((l - 20) / 2, (b - 24) / 2, "Please enter your name");
		for(i = 4; i > status; i--) {
			strcpy(name[i], name[i - 1]);
			speed[i] = speed[i - 1];
		}
		curs_set(1); /* to make the cursor visible */
		echo(); /* to make keyboard input visible */
		mvscanw((l - 16) / 2, (b - 16) / 2, "%s", name[status]);
		speed[status] = awpm;
		fclose(fp);
		fp = fopen("./Highscores.txt", "w");
		for(i = 0; i < 5; i++)
			fprintf(fp, "%s %f\n", name[i], speed[i]);
	}
	else {
		mvprintw((l - 24) / 2, (b - 40) / 2, "Sorry, you were unable to beat highscores!");
		getch();
	}
	fclose(fp);
	curs_set(1); /* to make the cursor visible again */
	display_highscores();
}

/*--------------------------------------------Tutorial Menu-----------------------------------------------*/
/* tutorial() displays the tutorial menu, where the user can select a lesson to practice on it. */
char tutorial() {
	int l, b;
	char option;
	clear(); /*  to clear the window */
	getmaxyx(stdscr, l, b); /* to get maximum resolution of the current window */
	box(stdscr, 0, 0); /* to create borders */
	/* coordinates are adjusted to print message at their specific locations in the window */
	mvprintw((l - 20) / 2, (b - 40) / 2, "1: Lesson 1: 1 2 3 4 5 q w e r t");
	mvprintw((l - 18) / 2, (b - 40) / 2, "2: Lesson 2: 6 7 8 9 0 y u i o p");
	mvprintw((l - 16) / 2, (b - 40) / 2, "3: Lesson 3: a s d f g z x c v b");
	mvprintw((l - 14) / 2, (b - 40) / 2, "4: Lesson 4: h j k l ; ' n m , . /");
	mvprintw((l - 12) / 2, (b - 40) / 2, "5: Lesson 5: q w e r t a s d f g");
	mvprintw((l - 10) / 2, (b - 40) / 2, "6: Lesson 6: i o p [ ] j k l ; ' ");
	mvprintw((l - 8) / 2, (b - 40) / 2, "7: Lesson 7: ! @ # $ % ^ & * ( ) { } : < > ?");
	mvprintw((l - 6) / 2, (b - 40) / 2, "8: Return Back to Main Menu:");
	cbreak(); /* to enter cbreak mode */
	noecho(); /* to make keyboard input invisible */
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK); /* initializing pair 1 as Cyan and Black combination */
	attron(COLOR_PAIR(1));
	mvprintw(l - 3, 3, "Use indicated keys to choose the options");
	attroff(COLOR_PAIR(1));
	refresh(); /* to update window */
	curs_set(0); /* to make the cursor invisible */
	while(1) {
		option = getchar();
		if(option > '8' || option < '1') {
			init_pair(2, COLOR_RED, COLOR_BLACK); /* initializing pair 2 as Red and Black combination */
			attron(COLOR_PAIR(2));
			mvprintw(l - 3, 3, "Wrong input, please select from 1 - 8 for choices");
			attroff(COLOR_PAIR(2));
			refresh(); /* to update window */
		}
		else
			break;
	}
	return option;
}

/*---------------------------------Random Strings for tutorials---------------------------------*/
/* char *lesson[] is a character pointer array which points to an array of strings. these strings are used to generate random arrays for tutorials */
char *lesson[] = {"12345qwert", 
		  "67890yuiop",
		  "asdfgzxcvb",
		  "hjkl;'nm,./",
		  "qwertasdfg",
		  "iop[]jkl;'",
		  "!@#$%^&*(){}:<>"
 };

/*---------------------------------------Tutorial Display----------------------------------------*/
/* tutorial_display() displays the window where tutorial occurs. */
void tutorial_display(char *test_array, char choice1) {
	int i, index, length, choice, count;
	int l, b;
	int c;
	float acc;
	getmaxyx(stdscr, l, b); /* to get maximum resolution of the current window */
	test_array = (char *)malloc(((b - 34) / 2) * sizeof(char)); /* allocating memory according to size of the window for tutorial */
	choice = choice1 - '0' - 1; /* converting char to int */
	length = strlen(lesson[choice]); 
	/* Algorithm to generate a string of random characters from the group of a lesson selected by the user */
	for(i = 0; i <= (b - 30) / 2; ++i) {
		if(i % 6 == 0) 
			test_array[i] = ' '; /* to generate words of 5 characters */
		else {
			index = (int)(random() % length); /* using random() to get a random index for the array */
			test_array[i] = lesson[choice][index]; /* adding the randomly generated character to the array */
		}
	}
	test_array[i] = '\0'; /* to convert array of characters into a string */
	clear(); /*  to clear the window */
	box(stdscr, 0, 0); /* to create borders */
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK); /* initializing pair 1 as Cyan and Black combination */
	attron(COLOR_PAIR(1));
	attron(A_BOLD);
	move(3, (b - 16) / 2);
	printw("LESSON %c", choice1);
	attroff(A_BOLD);
	attroff(COLOR_PAIR(1));
	move(6, 10);
	addstr(test_array); /* to print the generated random string into window */
	move(l - 3, 3);
	attron(A_REVERSE); /* to reverse all previous attributes, resulting into an inverted text */
	printw("Press HOME Key to restart, END key to return back to main menu");
	attroff(A_REVERSE);
	move(7, 11);
	noecho(); /* to make keyboard input invisible */
	i = 1;
	count = 0;
	keypad(stdscr, TRUE); /* entering keypad mode */
	curs_set(1); /* to make cursor visible */
	/* -----beginning of the tutorial----- */
	while(i <= (b - 30) / 2) {
		c = getch(); /* fetching an input from keyboard	*/	
		if(c != test_array[i]) { /* whenever the input does not match the required character */
			attron(A_STANDOUT); /* inverts the colors of background and foreground */
			attron(A_BOLD);	
			printw("^"); /* '^' is an indication that the word typed is incorrect */
			attroff(A_BOLD);
			attroff(A_STANDOUT);
			count++; /* incrementing no. of mistakes made */
		}
		else /* whenever input is correct */
			printw("%c", c);
		if(c == KEY_END) {
			return;
		}
		if(c == KEY_HOME) {
			tutorial_display(test_array, choice1);
			return;
		}
		i++;
	}
	refresh(); /* to update window */
	/* -----calculating and printing accuracy-----*/
	acc = (100.00 - (count * 100.00) / (i - 1)); /* to calculate accuracy */
	attron(A_REVERSE); /* to reverse all previous attributes, resulting into an inverted text */
	curs_set(0); /* to make cursor invisible */	
	move(l - 3, 3);
	clrtoeol(); /* to clear entire line of the cursor position */
	mvprintw(l - 3, b - 30, "Accuracy = %f", acc);
	mvprintw(l - 2, b - 30, "Press END Key to continue");
	attroff(A_REVERSE);
	refresh(); /* to update window */
	/* Loop to exit only when END Key is pressed */
	while(1) {
		c = getch();
		if(c == KEY_END)
			break;
	}
	/* -----whenever accuracy is less than 95%----- */
	if(acc < 95) {
		move(l - 2, 3);
		clrtoeol(); /* to clear entire line of the cursor position */
		move(l - 3, 3);
		clrtoeol(); /* to clear entire line of the cursor position */
		attron(A_REVERSE); /* to reverse all previous attributes, resulting into an inverted text */
		printw("Your Accuracy is low. You should acheive minimum 95 accuracy. Press END key to restart the practice");
		attroff(A_REVERSE);
		/* Loop to exit only when END Key is pressed */
		while(1) {
			c = getch();
			if(c == KEY_END)
				break;
		}
		tutorial_display(test_array, choice1);
		return;
	}
	move(l - 2, 3);
	clrtoeol(); /* to clear entire line of the cursor position */
	move(l - 3, 3);
	clrtoeol(); /* to clear entire line of the cursor position */
	attron(COLOR_PAIR(1));
	printw("Congratulations, you have completed the practice. Press HOME to restart, END to exit");
	attroff(COLOR_PAIR(1));
	/* Loop to exit when END Key is pressed, or to restart when HOME key is pressed */
	while(1) {
		c = getch();
		if(c == KEY_END)
			break;
		else if(c == KEY_HOME) {
			tutorial_display(test_array, choice1);
			return;
		}
	}
	return;
}

/*-------------------------------------------------Highscores Menu-----------------------------------------*/
/* display_highscores() display the highscores of the typing test */
void display_highscores() {
	int l, b, j;
	clear(); /*  to clear the window */
	getmaxyx(stdscr, l, b); /* to get maximum resolution of the current window */
	box(stdscr, 0, 0); /* to create borders */
	curs_set(0); /* to make cursor invisible */
	move(1, 5);
	FILE *fp;
	fp = fopen("./Highscores.txt", "r");
	if(fp == NULL) {
		mvprintw((l - 20) / 2, (b - 40) / 2, "Error: File not found, the program now will exit");
		getch();
		return;
	}
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK); /* initializing pair 1 as Cyan and Black combination */
	init_pair(2, COLOR_YELLOW, COLOR_BLACK); /* initializing pair 2 as Yellow and Black combination */
	attron(COLOR_PAIR(1));
	attron(A_BOLD);
	attron(A_REVERSE); /* to reverse all previous attributes, resulting into an inverted text */
	/* coordinates are adjusted to print message at their specific locations in the window */
	mvprintw((l - 20) / 2, (b - 38) / 2, "**Highscores**");
	attroff(A_REVERSE);	
	mvprintw((l - 15) / 2, (b - 46) / 2, "Name");
	mvprintw((l - 15) / 2, (b - 20) / 2, "Speed");
	attroff(A_BOLD);
	attroff(COLOR_PAIR(1));
	char name[20];
	float speed;
	j = 0; /* y co-ordinate of the current window */
	attron(COLOR_PAIR(2));
	while(fscanf(fp, "%s %f", name, &speed) != EOF) {
		mvprintw(((l - 15) / 2) + 3 + j, (b - 46) / 2, "%s", name);
		mvprintw(((l - 15) / 2) + 3 + j, (b - 20) / 2, "%f", speed);
		j = j + 2; /* moving two lines below */
	}
	attroff(COLOR_PAIR(2));
	getch(); /* waiting for an input so that window is stable */
	curs_set(1); /* to make cursor visible again */
	refresh(); /* updating window */
	return;
}

/*---------------------------------------To reset Highscores--------------------------------------------*/
/* reset_highscores() resets the previous highscores */
void reset_highscores() {
	int l, b;
	char op;
	getmaxyx(stdscr, l, b); /* to get maximum resolution of the current window */
	curs_set(0); /* to make cursor invisible */
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK); /* initializing pair 1 as Cyan and Black combination */
	move(l - 3, 3);
	clrtoeol(); /* to clear entire line of the cursor position */
	attron(COLOR_PAIR(1));
	mvprintw(l - 3, 3, "Are you sure? (y/n)");
	attroff(COLOR_PAIR(1));
	op = getch();
	if(op == 'y' || op == 'Y') {
		clear();
		int i;
		FILE *fp;
		/* ----- reset highscores ----- */
		float score;
		score = 50;
		fp = fopen("./Highscores.txt", "w");
		if(fp == NULL) {
			move((l - 8) / 2, (b - 56) / 2);
			printw("Error: File not found");
		}
		for(i = 0; i < 5; i++) {
			fprintf(fp, "No_Name %f\n", score);
			score = score - 10;
		}
		fclose(fp);
		move((l - 8) / 2, (b - 46) / 2);
		printw("Highscores have been reset!");
		getch(); /* waiting for an input so that window is stable */
		curs_set(1); /* to make cursor visible again */
		return;
	}
	else if(op == 'n' || op == 'N') {
		curs_set(1); /* to make cursor visible again */
		return;
	}
	else { /* if input is neither yes or no */ 
		reset_highscores();
		return;
	}
}

/*-----------------------------------------Rules Menu--------------------------------------*/
/* display_rules() displays the rules of the typing test and tutorials */
void display_rules() {
	char c;
	int l, b;
	clear(); /*  to clear the window */
	getmaxyx(stdscr, l, b); /* to get maximum resolution of the current window */
	curs_set(0); /* to make cursor invisible */
	move(3, 10);
	FILE *fp;
	fp = fopen("./Rules.txt", "r");
	if(fp == NULL) {
		mvprintw((l - 20) / 2, (b - 40) / 2, "Error: File not found, the program now will exit");
		getch(); /* waiting for an input so that window is stable */
		return;
	}
	/* printing rules in the window */
	while(fread(&c, 1, 1, fp)) {
		addch(c);
	}
	fclose(fp);
	box(stdscr, 0, 0); /* to create borders */
	getch(); /* waiting for an input so that window is stable */
	curs_set(1); /* to make cursor visible again */
	refresh(); /* updating window */
	return;
}

/*-------------------------------------------To exit Program-----------------------------------*/
/* end_program() terminates the program */
int end_program() {
	char op;
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK); /* initializing pair 1 as Cyan and Black combination */
	attron(COLOR_PAIR(1));
	move(LINES - 3, 3);
	clrtoeol(); /* to clear entire line of the cursor position */
	curs_set(0); /* to make cursor invisible */
	mvprintw(LINES - 3, 3, "Are you sure? (y/n)");
	attroff(COLOR_PAIR(1));
	op = getch();
	curs_set(1); /* to make cursor visible again */
	if(op == 'y' || op == 'Y') 
		return 1;
	else if(op == 'n' || op == 'N') 
		return 0;
	else
		return end_program();
	return 2;
}
