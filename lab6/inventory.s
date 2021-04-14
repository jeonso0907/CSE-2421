# Sooyoung Jeon
# CSE 2421 Lab6

# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE.

.file "inventory.s"  				# optional directive 
.section .rodata				# required directives for rodata 

.data   						# required for file scope data: read-write program data     
#of static storage class 

.global inventory 				# required directive for every function 
.type inventory, @function		# required directive  
.text     						# required directive - code begins here 
inventory: 
	pushq	%rbp   				# stack housekeeping #1 
	movq 	%rsp, %rbp  		# stack housekeeping #2 
	
	pushq	%r12
	pushq	%r13
	pushq	%r14
	movq	$0, %rax
	movq	%rdi, %r13

	jmp		cond
	
loop:
	imulq	$8, %rax, %rcx
	
	pushq	%rax
	pushq	%rsi

	movq	(%r13, %rcx), %rdi

	movq	$evaluate, %rax
	call	vshim
	
	cmpq	%rax, %r12
	cmovl	%rax, %r12
	cmovl	(%r13), %r14

	popq	%rsi
	popq	%rax
	
	decq	%rsi
	incq	%rax

cond:
	cmp		$0, %rsi
	jne		loop
	
	movq	%r14, %rax
	
	popq	%r14
	popq	%r13
	popq	%r12
	
	leave 						#return stack to original values
	ret 						#return
	.size inventory, .-inventory 		#required directive
	
.Min:
	.string	"inventory: The variation is %i\n"
	
.Max:
	.string "inventory: The maximum variation is is %i from %s\n"
.Test:
	.string	"test: %s currently has an adjustment of %i\n"
