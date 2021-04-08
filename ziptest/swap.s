# Sooyoung Jeon
# CSE 2421 Lab5

# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE.

.file "swap.s"  				# optional directive 
.section .rodata				# required directives for rodata 

.data   						# required for file scope data: read-write program data     
#of static storage class 

.global swap  					# required directive for every function 
.type swap, @function			# required directive  
.text     						# required directive - code begins here 
swap: 
	pushq	%rbp   				# stack housekeeping #1 
	movq 	%rsp, %rbp  		# stack housekeeping #2 
	
	movb	$0xF0, %al			# Set first four bits with 1 in front register (al)
	movb	$0x0F, %dl			# Set last four bits with 1 in back register (dl)
	
	andb	%dil, %al			# Mask the front register with original register
	andb	%dil, %dl			# Mask the back register with original register
	
	sarb	$4, %al				# Right bit shift the front register 4 times
	salb	$4, %dl				# Left bit shift the back register with 4 times
	
	andb	$0x0F, %al			# Mask the last four bits of the front register
	andb	$0xF0, %dl			# Mask the front four bits of the back register
	
	addb	%dl, %al			# Add front and back register as al and return
	
	leave 						#return stack to original values
	ret 						#return
	.size swap, .-swap  		#required directive
