# Sooyoung Jeon
# CSE 2421 Lab6

# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE.

.file "inventory.s"  				# optional directive 
.section .rodata					# required directives for rodata 

.Min:
	.string	"\ninventory: The minimum variation is %i\n"
	
.Max:
	.string "inventory: The maximum variation is %i from %s\n"

.data   							# required for file scope data: read-write program data     
#of static storage class 

.global inventory 					# required directive for every function 
.type inventory, @function			# required directive  
.text     							# required directive - code begins here 
inventory: 
	pushq	%rbp   					# stack housekeeping #1 
	movq 	%rsp, %rbp  			# stack housekeeping #2 
				
	pushq	%r12					# push the initial value of r12 into the stack
	pushq	%r13 					# push the initial value of r13 into the stack
	pushq	%r14					# push the initial value of r14 into the stack
	pushq	%r15					# push the initial value of r15 into the stack
	pushq	%rbx					# push the initial value of rbx into the stack

	movq	%rdi, %r15				# copy the address of struct array into struct array
	movq	%rsi, %rbx				# copy the valid count into current index
	movq	%rsi, %r12				# copy the valid count into first index

	jmp		cond					# start the loop with condition
	
loop:
	movq	(%r15), %rdi			# copy the address of the struct into the parameter
	movq	$evaluate, %rax			# copy the address of the evaluate function address
	call	vshim					# inderectly calls the evaluate function with vshim
	
	cmp		%r12, %rbx				# compare the current index and first index
	je		first					# if both indices are same, initialize the max and min with first
	
	cmpq	%rax, %r13				# compare the new variability with current max
	cmovl	%rax, %r13				# if new variability is higher, put it into the max
	cmovl	(%r15), %r12			# if new variability is higher, put designated name array into an array
	
	cmpq	%rax, %r14				# compare the new variability with current min
	cmovg	%rax, %r14				# if new variability is lower, put it into the min
	
	jmp 	setup					# set up the current index and next struct address for next loop

first:
	movq	%rax, %r13				# copy the first struct's new variability into the max
	movq	%rax, %r14				# copt the first struct's new variability into the min
	
setup:		
	decq	%rbx					# decrement the current index with 1
	leaq	8(%r15), %r15			# set the pointing address of the array to the next one

cond:
	cmp		$0, %rbx				# compare the current index with 0
	jne		loop					# if current index is not zero, continue the loop
	
	movq	%r14, %rsi				# copy the minimum variaiblity in the 2nd parameter
	movq	$.Min, %rdi				# copy the Min string address in the 1st parameter
	movq	$0, %rax				# clear the return value
	call	print					# call the print function with designated parameters
	
	movq	%r13, %rsi				# copy the maximum variability in the 2nd parameter
	movq	%r12, %rdx				# copy the name array address in the 3rd parameter
	movq	$.Max, %rdi				# copy the Max string address in the 1st parameter
	movq	$0, %rax				# clear the return value
	call 	print					# call the print function with designated parameters
	
	movq	%r12, %rax				# copy the max variability's name array in the return value
	
	popq	%rbx					# pop the initial value of rbx
	popq	%r15					# pop the initial value of r15
	popq	%r14					# pop the initial value of r14
	popq	%r13					# pop the initial value of r13
	popq	%r12					# pop the initial value of r12
	
	leave 							#return stack to original values
	ret 							#return
	.size inventory, .-inventory 	#required directive
	


