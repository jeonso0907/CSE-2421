# Sooyoung Jeon
# CSE 2421 Lab6

# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE.

.file "calibrate.s"  				# optional directive 
.section .rodata				# required directives for rodata 

.data   						# required for file scope data: read-write program data     
#of static storage class 

.global calibrate  				# required directive for every function 
.type calibrate, @function		# required directive  
.text     						# required directive - code begins here 
calibrate: 
	pushq	%rbp   				# stack housekeeping #1 
	movq 	%rsp, %rbp  		# stack housekeeping #2 
	
	pushq	%rdi
	
	leaq	20(%rdi), %rdi
	movq	$0, %rsi
	movq	$0, %rax
	movq	$0, %r10
	movq	$0, %r11
	
	movw	(%rdi, %rsi), %r10w
	movw	(%rdi, %rsi), %r11w
	xorq	%r8, %r8
	
	jmp		cond
	
loop:
	movw	(%rdi, %rsi, 2), %ax
	incq	%rsi

max:
	cmpw	%ax, %r10w
	cmovl	%ax, %r10w

min:	
	cmpw	%ax, %r11w
	cmovg	%ax, %r11w

add:
	cwtl
	cltq
	addq	%rax, %r8
	movq	$0, %rax
	
cond:
	cmpq	$7, %rsi
	jle		loop
	popq	%rdi
	sarq	$3, %r8
	movw	%r8w, 36(%rdi)
	subw	%r11w, %r10w
	movq	%r10, %rax
	
	leave 						#return stack to original values
	ret 						#return
	.size calibrate, .-calibrate  		#required directive
