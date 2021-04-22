# Sooyoung Jeon
# CSE 2421 Lab6

# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE.

.file "evaluate.s"  				# optional directive 
.section .rodata					# required directives for rodata 

.Before:
	.string	"\nevaluate: %s currently has an adjustment of %i\n"
	
.After:
	.string "evaluate: new adjustment is %i, variability is %i\n"

.data   							# required for file scope data: read-write program data     
#of static storage class 

.global evaluate 					# required directive for every function 
.type evaluate, @function			# required directive  
.text     							# required directive - code begins here 
evaluate: 
	pushq	%rbp   					# stack housekeeping #1 
	movq 	%rsp, %rbp  			# stack housekeeping #2 
	
	pushq	%r12					# push the initial value of r12 into the stack
	pushq	%r13					# push the initiil value of r14 into the stack
	movq	$0, %rdx				# initialize the initial avg value with zero
	movq	%rdi, %r12				# copy the address of the struct into r12

									# print before
								
	leaq	(%r12), %rsi			# copy the address of array name in the 2nd parameter
	movw	36(%r12), %dx			# copy the initial avg value in the 3rd parameter
	movq	$.Before, %rdi			# copy the address of Before string in the 1st parameter
	movq	$0, %rax				# clear the return value
	call	print					# print the string with the designated parameters

									# do calibrate
								
	movq	%r12, %rdi				# copy the address of the struct in the 1st parameter
	movq	$calibrate, %rax		# copy the address of the calibrate function in rax
	call	vshim					# indirectly call the calibrate function with the parameter
	
									# print after
												
	movq	%rax, %rdx				# copy the variability value in the 3rd parameter
	movq	%rax, %r13				# copy the variability value in r13
	
	movw	36(%r12), %ax			# copy the new average value into the current value
	cwtl							# convert current value to doubleword type
	cltq							# convert current value to quadword type
	movq	%rax, %rsi				# copy the current value in the 2nd parameter
	movq	$.After, %rdi			# copy the address of After string in the 1st parameter
	movq	$0, %rax				# clear the return value
	call 	print					# print the string with the designated parameters
	
	movq	%r13, %rax				# copy the variability value into the return value
	
	popq	%r13					# pop the initial value of r13
	popq	%r12					# pop the initial value of r12
	
	leave 							#return stack to original values
	ret 							#return
	.size evaluate, .-evaluate 		#required directive
	

