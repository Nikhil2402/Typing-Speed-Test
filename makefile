all: miniproject 
miniproject: Typingtest.o
	gcc Typingtest.c -lncurses
clean:
	r *o
