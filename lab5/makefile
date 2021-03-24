# Sooyoung Jeon
# CSE 2421 Lab5

# The bulk of this makefile was provided by Neil Kirby for CSE 2421 SP21
# YOu really need to add your name to this file.  It would be terible to
# get a zero on an easy lab.
# 
# You also need to add a zip target that builds lab5.zip, but you are
# experts at this by now.
#
# Also needed: rules for translate.o and swap.o based on their respective 
# .s files.
#
# A ton of comments would be nice as well.
# I don't have the master rule in here because we are building .o files
# from C and from assembler and they need different rules.

# one of the two mandated executables
lab5: lab5.o translate.o shim.o swap.o verify.o 
	gcc -g -o $@ $^

# the other mandated executable
swap_driver: swap_driver.o swap.o shim.o
	gcc -g -o $@ $^

# You don't need this, you don't use bad
#bad.o: bad.s
#	gcc -g -m64 -c -o $@ $^

# You don't need this, you have verify.o
#verify.o: verify.s
#	gcc -g -m64 -c -o $@ $^

# You don't need this, you have shim.o
#shim.o: shim.s
#	gcc -g -m64 -c -o $@ $^


# Swap object file
swap.o: swap.s
	gcc -g -m64 -c -o $@ $^
	
# Translate object file
translate.o: translate.s
	gcc -g -m64 -c -o $@ $^

# rules to turn our 2 C code files into their dot o files.
lab5.o: lab5.c
	gcc -ansi -pedantic -c -o $@ $^

swap_driver.o: swap_driver.c
	gcc -ansi -pedantic -c -o $@ $^

# This is not the rule you are looking for.  This is the rule used to build
# the supplied stuff, not the rule you want to zip up your masterwork when
# it is done.
lab5.zip: lab5.c swap_driver.c shim.o makefile s.output l5.output verify.o README_LAB5 translate.s swap.s
	zip $@ $^


