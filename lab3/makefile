#
# Neil Kirby: example makefile for lab2 SP21.  Shows using libfire.
#

all:  struct_proto.o struct_proto pointer_proto.o pointer_proto read_proto.o read_proto func_ptr_proto.o func_ptr_proto listproto.o listproto lab3.o lab3 memory.o output.o calculate.o simulate.o bits.o

headers: *.c tags
	headers.sh

tags: *.c
	ctags -R .

# example of a poorly named prototype.  Mark yours to be graded or not to
# be graded.  A word or two about what they do would be nice.
p1: p1.o
	gcc -g -o $@ $^ -L. -lfire -lncurses


# this is our master compiler rule to generate .o files.
# It needs all 4 warnings

%.o:%.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@ -llinkedlist

# Prototype 1

struct_proto: struct_proto.o
	gcc -g -o $@ $^ -L. -lfire -lncurses

# Prototyep 2

pointer_proto: pointer_proto.o
	gcc -g -o $@ $^ -L. -lfire -lncurses

# Prototype 3

read_proto: read_proto.o
	gcc -g -o $@ $^ -L. -lfire -lncurses

# Prototyep 4

func_ptr_proto: func_ptr_proto.o
	gcc -g -o $@ $^ -L. -lfire -lncurses

# List prototype

listproto : listproto.o
	gcc -g -o $@ $^ -L. -llinkedlist

# Lab3

lab3: lab3.o memory.o output.o calculate.o simulate.o bits.o
	gcc -g -o $@ $^ -L. -lfire -lncurses -llinkedlist

run:
	lab3 < rwb3.fwx
