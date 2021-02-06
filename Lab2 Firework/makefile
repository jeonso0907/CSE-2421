#
# Sooyoung Jeon
#

all: lab2 lab2.o simulate.o calculate.o bits.o xPositionProto yPositionProto colorProto flashProto yearProto

headers: *.c tags
	headers.sh
	echo "hi"

tags: *.c
	ctags -R .

# [GRADE] this section please
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

# Do [NOT GRADE] this section
p2: lab2 
	gcc -g -o $@ $^ -L. -lfire -lncurses

p3: lab2.o simulate.o calculate.o bits.o
	gcc -g -o $@ $^ -L. -lfire -lncurses

p4: lab2
	gcc -g -o $@ $^ -L. -lfire -lncurses

# Default lab2 object
lab2: lab2.o simulate.o calculate.o bits.o
	gcc -g -o $@ $^ -L. -lfire -lncurses

# this is our master compiler rule to generate .o files.
# It needs all 4 warnings

%.o:%.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

# Creates a zip file for lab2
lab2.zip:   makefile *.c *.h README_LAB2 libfire.a 
	zip lab2.zip makefile *.c *.h README_LAB2 libfire.a
	rm -rf install
	unzip lab2.zip -d install
	make -C install lab2 
