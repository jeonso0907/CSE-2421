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
	
	movb	%dil, %al			# Copy the parameter value (rdi) into the return value (rdx)
	rorb	$4, %al				# Rotate the al value back and forth with 4 bits to swap
	
	leave 						#return stack to original values
	ret 						#return
	.size swap, .-swap  		#required directive
