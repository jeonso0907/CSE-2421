#
# Sooyoung Jeon
#

all:  tags headers lab2 simulate physics bits xPositionProto yPositionProto colorProto flashProto yearProto

headers: *.c tags
	headers.sh

tags: *.c
	ctags -R .

# Grade this section please
xPositionProto: xPositionProto.o calculate.o
	gcc -g -o $@ $^ -L. -lfire -lncurses

yPositionProto: yPositionProto.o calculate.o
	gcc -g -o $@ $^ -L. -lfire -lncurses

colorProto: colorProto.o bits.o
	gcc -g -o $@ $^ -L. -lfire -lncurses

flashProto: flashProto.o bits.o
	gcc -g -o $@ $^ -L. -lfire -lncurses

yearProto: yearProto.o bits.o
	gcc -g -o $@ $^ -L. -lfire -lncurses

# Do not grade this section
p2: lab2
	gcc -g -o p2 lab2.o simulate.o physics.o bits.o -L. -lfire -lncurses

p3: lab2.o simulate.o physics.o bits.o
	gcc -g -o $@ $^ -L. -lfire -lncurses

p4: lab2
	gcc -g -o p4 lab2.o simulate.o physics.o bits.o -L. -lfire -lncurses

# Default lab2 object
lab2: lab2.o
	gcc -g -o $@ $^ simulate.o physics.o bits.o -L. -lfire -lncurses

# this is our master compiler rule to generate .o files.
# It needs all 4 warnings

%.o:%.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

# Creates a zip file for lab2
lab2.zip:   makefile *.c *.h README_LAB2 libfire.a 
	zip lab2.zip makefile *.c *.h README_LAB2 libfire.a
	rm -rf install
	lab1.zip:   makefile *.c *.h README_LAB2 libfire.a
	unzip lab2.zip -d install
	make -C install lab2 
