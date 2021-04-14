
# The bulk of this makefile was provided by Neil Kirby for CSE 2421 SP21
# YOu really need to add your name to this file.  It would be terible to
# get a zero on lab to be proud of.
# 
# You also need to add a zip target that builds lab6.zip, but you are
# experts at this by now.
#
# A ton of comments would be nice as well.
# I don't have the master rule in here because we are building .o files
# from C and from assembler and they need different rules.


# GET RID OF RULES YOU DO NOT HAVE CODE FOR.  (like various bonus, unless
# you do have code for them.)

# generic lab6 rule
lab6: lab6.o inventory.o evaluate.o calibrate.o vshim.o take.o print.o
	gcc -g -o $@ $^

# bonus B - 4 registers
b4: lab6.o i4.o evaluate.o calibrate.o vshim.o take.o print.o
	gcc -g -o $@ $^

# bonus B - 5 registers, no double touch
b5: lab6.o i5.o evaluate.o calibrate.o vshim.o take.o print.o
	gcc -g -o $@ $^

# lab6 using subscripts (many versions of instructor code)
l6s: lab6.o is.o evaluate.o calibrate.o vshim.o take.o print.o
	gcc -g -o $@ $^

# for calibrate
calibrate.o: calibrate.s
	gcc -g -m64 -c -o $@ $^

# for evaluate
evaluate.o: evaluate.s
	gcc -g -m64 -c -o $@ $^

# for inventory
inventory.o: inventory.s
	gcc -g -m64 -c -o $@ $^

# for i4 - Boinus B
i4.o: i4.s
	gcc -g -m64 -c -o $@ $^

# for i5 - Boinus B
i5.o: i5.s
	gcc -g -m64 -c -o $@ $^

# for is (not needed by students)
is.o: is.s
	gcc -g -m64 -c -o $@ $^

eval_main.o: eval_main.c
	gcc -g -ansi -pedantic -c -o $@ $<

eval_driver: eval_main.o evaluate.o calibrate.o vshim.o print.o
	gcc -g -o $@ $^

cal_main.o: cal_main.c
	gcc -g -ansi -pedantic -c -o $@ $<

cal_driver: cal_main.o calibrate.o
	gcc -g -o $@ $^

# SOOYOUNG TEST
inventory2.o: inventory2.s
	gcc -g -m64 -c -o $@ $^


# rules to turn our  C code file into their dot o files.
lab6.o: lab6.c device.h
	gcc -g -ansi -pedantic -c -o $@ $<


# This is not the rule you are looking for.  This is the rule used to build
# the supplied stuff, not the rule you want to zip up your masterwork when
# it is done.

# your zip file rule goes here


