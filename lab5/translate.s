# Sooyoung Jeon
# CSE 2421 Lab5

# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE.

.file "translate.s"  				# optional directive 
.section .rodata					# required directives for rodata 

.data   							# required for file scope data: read-write program data     
#of static storage class 

.globl translate  					# required directive for every function 
.type translate, @function			# required directive  
.text     							# required directive - code begins here 
translate: 
	pushq	%rbp   					# stack housekeeping #1 
	movq 	%rsp, %rbp  			# stack housekeeping #2 
	
	pushq	%rbx					# Push three callee saved registers to be retored later
	pushq	%r12
	pushq	%r13
	
	movq	$0, %rax				# Initialize the rax and rbx with zero, rax returns the count of charaters translated
	movq	$0, %rbx				# Index counting register to access the array
	movq	%rdi, %r12				# Copy string in register (r12)
	movq	%rsi, %r13				# Copy empty string (result string) in register (r13)


loop:
	movb	(%r12, %rbx), %dil		# Get an element from the array (r12) based on the index (rdx) and save it in rdi
	
	cmpb	$0, %dil				# Check rather an element is null or not
	je		exit					# If an element is null, exit the loop and end
	
	call	shim					# If an element is not null, call the swap function
	
	movb	%al, (%r13, %rbx)		# Save swapped element in the result string in appropriate index
	incq	%rbx					# Increment the index register value with 1 (or 0x01)
	
	jmp		loop					# Loop again
	
exit:
	movq	%rbx, %rax				# Save the index value (rbx) in the return register (rax)
	movb	$0x00, (%r13, %rbx)		# Save the null value ('\0') at the end of the result string
	popq	%r13					# Restore the callee saved values
	popq	%r12
	popq	%rbx
	leave 							# return stack to original values
	ret 							# return
	.size translate, .-translate  	# required directive
