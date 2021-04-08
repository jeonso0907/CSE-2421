#
# Sooyoung Jeon
# Lab4: Firework
#

all:  struct_proto.o struct_proto pointer_proto.o pointer_proto read_proto.o read_proto func_ptr_proto.o func_ptr_proto listproto.o listproto lab4.o lab4 memory.o output.o calculate.o bits.o memory_func.o

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


##### GRADE THIS SECTION PLEASE ######


# Prototype 1 (Grade) 
# Test the basic struct structure

struct_proto: struct_proto.o
	gcc -g -o $@ $^ -L. -lfire -lncurses

# Prototyep 2 (Grade) 
# Test the struct pointer

pointer_proto: pointer_proto.o
	gcc -g -o $@ $^ -L. -lfire -lncurses

# Prototype 4 (Grade) 
# Test updating the struct data with given data
# Use professor provided fwx files to test

read_proto: read_proto.o
	gcc -g -o $@ $^ -L. -lfire -lncurses

# Prototyep 4 (Grade) 
# Test the function pointer to run the variable with the given function

func_ptr_proto: func_ptr_proto.o
	gcc -g -o $@ $^ -L. -lfire -lncurses


##### THANK YOU #####


# List prototype (Do not grade)

listproto : listproto.o
	gcc -g -o $@ $^ -L. -llinkedlist

# Lab4 Firework Simulation

lab4: lab4.o memory.o output.o calculate.o bits.o memory_func.o
	gcc -g -o $@ $^ -L. -lfire -lncurses -llinkedlist

# Creates a zip file for lab2

lab4.zip: makefile *.c *.h libfire.a liblinkedlist.a README_LAB4
	zip lab4.zip $^
	rm -rf install
	unzip lab4.zip -d install
	make -C install lab4

