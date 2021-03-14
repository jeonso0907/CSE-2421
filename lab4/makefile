
# Edited by Sooyoung Jeon

all:  tags headers lab4

headers: *.c tags
	headers.sh

tags: *.c
	ctags -R .

# all of my dependencies must be dot o files

# Lab4 including reliable and unreliable

lab4: lab4.o output.o skymath.o bits.o memory.o functions.o linkedlist.o reliable.o
	gcc -g -o $@ $^ -L. -lfire -lncurses
	
lab4u: lab4.o output.o skymath.o bits.o memory.o functions.o linkedlist.o unreliable.o
	gcc -g -o $@ $^ -L. -lfire -lncurses


# GRADE THIS
# 4 linked list function prototypes

p1: p1_iterate.o
	gcc -g -o $@ $^ -L. -lfire -llinkedlist -lncurses
	
p2: p2_least.o
	gcc -g -o $@ $^ -L. -lfire -llinkedlist -lncurses
	
p3: p3_sort.o
	gcc -g -o $@ $^ -L. -lfire -llinkedlist -lncurses
	
p4: p4_insertDelete.o reliable.o
	gcc -g -o $@ $^ -L. -lfire -lncurses

# this is our master compiler rule to generate .o files.
# It needs all 4 warnings

%.o:%.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

# used to make the aipfile that distributes lab 4 code to students
lab4.zip: *.c *.h *.a *.fwx makefile *.sh *.awk README_LAB4 reliable.o unreliable.o
	zip $@ $^
	
	
