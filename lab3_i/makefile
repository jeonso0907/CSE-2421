
all:  tags headers lab3

headers: *.c tags
	headers.sh

tags: *.c
	ctags -R .

# all of my dependencies must be dot o files
lab3: lab3.o output.o skymath.o bits.o memory.o functions.o unreliable.o
	gcc -g -o $@ $^ -L. -lfire -llinkedlist -lncurses


# this is our master compiler rule to generate .o files.
# It needs all 4 warnings

%.o:%.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

# used to make the aipfile that distributes lab 3 code to students
sp21_instructor_lab3.zip: *.c *.h *.a *.fwx makefile *.sh *.awk
	zip $@ $^

