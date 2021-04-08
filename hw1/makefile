
all: py1 py2

py1: py1.o makefile
	gcc -ansi -pedantic -Ofast -o $@ py1.c -lm -lncurses -L. -lfire
	
	
py2: py2.o makefile
	gcc -ansi -pedantic -Ofast -o $@ py2.c -lm -lncurses -L. -lfire
