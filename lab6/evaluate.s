# Sooyoung Jeon
# CSE 2421 Lab6

# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE.

.file "evaluate.s"  				# optional directive 
.section .rodata				# required directives for rodata 

.data   						# required for file scope data: read-write program data     
#of static storage class 

.global evaluate 				# required directive for every function 
.type evaluate, @function		# required directive  
.text     						# required directive - code begins here 
evaluate: 
	pushq	%rbp   				# stack housekeeping #1 
	movq 	%rsp, %rbp  		# stack housekeeping #2 
	xorq	%rdx, %rdx

	leaq	(%rdi), %rsi
	movw	36(%rdi), %dx
	pushq	%rdi
	
	movq	$.Before, %rdi
	movq	$0, %rax
	call	print
	
	popq	%rdi
	pushq 	%rdi
	
	movq	$calibrate, %rax
	call	vshim
	
	popq	%rdi
	
	movq	%rax, %rdx
	pushq	%rax
	
	movw	36(%rdi), %ax		################
	cwtl
	cltq
	movq	%rax, %rsi
	
	
	movq	$.After, %rdi
	movq	$0, %rax
	call 	print
	
	popq	%rax
	
	leave 						#return stack to original values
	ret 						#return
	.size evaluate, .-evaluate 		#required directive
	
.Before:
	.string	"\nevaluate: %s currently has an adjustment of %i\n"
	
.After:
	.string "evaluate: new adjustment is %i, variability is %i\n"
