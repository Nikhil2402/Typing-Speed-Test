project: project.o
	gcc -o project project.c -lncurses -Wall
clean:
	rm -rf *o infix
